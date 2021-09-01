/*IR remote control car with Arduino.
 * https://srituhobby.com
 */
 
#include <AFMotor.h>
#include <IRremote.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

IRrecv IR(A0);
decode_results result;

int Speed = 200;

#define up 16718055
#define down 16730805
#define left 16716015
#define right 16734885
#define Stop 16726215

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  IR.enableIRIn();
}

void loop() {
  if (IrReceiver.decode(&result)) {
    Serial.println(result.value);
    IR.resume();
  }
  delay(100);
  if (result.value == up ) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  } else if (result.value == down ) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
  } else if (result.value == Stop) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  } else if (result.value == left) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  } else if (result.value == right) {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  }
}
