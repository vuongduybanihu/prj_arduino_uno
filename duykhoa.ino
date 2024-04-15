#include "DHT.h" 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  
 
#define led1 10
#define led2 11
#define led3 12
#define led4 13
#define in1  6
#define in2 5
#define ENA  9 

const int DHTPIN = 2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);


//int sensorPin = A0;
int tocdo = 0; 
void dung()
{
  digitalWrite (in1, LOW); 
  digitalWrite (in2, LOW);
  analogWrite(ENA, tocdo);
    digitalWrite (led1, LOW);
    digitalWrite (led2, LOW);
    digitalWrite (led3, LOW);
    digitalWrite (led4, LOW); 
}

void cap1()
{
    digitalWrite (in1, HIGH); 
    digitalWrite (in2, LOW);
    analogWrite(ENA, tocdo+60);
      digitalWrite (led1, HIGH);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
}

void cap2()
{
    digitalWrite (in1, HIGH); 
    digitalWrite (in2, LOW);
    analogWrite(ENA, tocdo+100);
      digitalWrite (led2, HIGH);
      digitalWrite (led1, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
}
  void cap3()
{
    digitalWrite (in1, HIGH); 
    digitalWrite (in2, LOW);
    analogWrite(ENA, tocdo+150);
     digitalWrite (led3, HIGH);
     digitalWrite (led1, LOW);
     digitalWrite (led2, LOW);
     digitalWrite (led4, LOW);
}
void cap4()
{
    digitalWrite (in1, HIGH); 
    digitalWrite (in2, LOW);
    analogWrite(ENA, tocdo+255);
     digitalWrite (led4, HIGH);
     digitalWrite (led1, LOW);
     digitalWrite (led3, LOW);
     digitalWrite (led2, LOW);
}

void setup() 
 {
   Serial. begin (9600);
   dht.begin();
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);

 
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Nhiet Do:");
  lcd.setCursor(3, 1);
  lcd.print("(^_^) (^_^)");
}

void loop() {
  //int reading = analogRead(A0);
 float t = dht.readTemperature();
  //int voltage = map(reading,0,1023,0,500);
 //float voltage = (reading*5.0/1024.0);
 //float temp = voltage*100;
  lcd.setCursor(10,0);
  lcd.print(t);
  delay(100);
if ( t < 28 ){
  dung();
  }
else if( 28< t && t <30) {  
cap1(); 
}
else if( 30< t && t <33) {  
cap2(); 
}
else if(33<t&& t <35){  
  cap3();
}
else if ( 35<t){
cap4();
}

}
