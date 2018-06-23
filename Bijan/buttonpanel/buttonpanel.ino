#include <Encoder.h>
#include <Bounce.h>

#define BUTTON 14
#define LED 19
#define POT 20
#define CLK 22
#define DAT 21

// Documentation for Teensy functions:
// Button reading - https://www.pjrc.com/teensy/td_libs_Bounce.html
// Encoder reading - https://www.pjrc.com/teensy/td_libs_Encoder.html
// Press Cmd-Shift-L from Arduino to view the serial plotter
Encoder enc ( CLK , DAT );
Bounce myButton = Bounce (BUTTON, 20);

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(POT, INPUT);
  Serial.begin(115200);
}

void loop() {
  if (myButton.update()) {
    if (myButton.fallingEdge()) {
      Serial.println("button pressed");
    }
  }
  Serial.println(enc.read());
  Serial.println(analogRead(POT));
  delay(50);
}
