#include <iostream>
#include <utility>
#include <fstream>

using std::endl; 

int main(){
  int cases;
  int X;
  int C;
  int R;
  std::ifstream inFile("D-small-attempt2.in");
  std::ofstream outFile("output.txt");

  inFile >> cases;
  for(int i = 1; i <= cases; ++i){
    inFile >> X;
    inFile >> R;
    inFile >> C;
    switch(X){
    case 1:
      outFile << "Case #" << i << ": GABRIEL" << endl;
      break;
    case 2:
      if (R == 1 && C == 1){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else if ((R*C)%2 != 0){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else{
	outFile << "Case #" << i << ": GABRIEL" << endl;
      }
      break;
    case 3:
      if (R == 1 || C == 1){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else if ((R*C)%3 != 0){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else{
	outFile << "Case #" << i << ": GABRIEL" << endl;
      }
      break;
    case 4:
      if (R < 3 || C < 3){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else if ((R*C)%4 != 0){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else{
	outFile << "Case #" << i << ": GABRIEL" << endl;
      }
      break;
    
    case 5:
      if (R < 5 || C < 5){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else if ((R*C)%5 != 0){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else{
	outFile << "Case #" << i << ": GABRIEL" << endl;
      }
      break;

    case 6:
      if (R < 5 || C < 5){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else if ((R*C)%6 != 0){
	outFile << "Case #" << i << ": RICHARD" << endl;
      }
      else{
	outFile << "Case #" << i << ": GABRIEL" << endl;
      }
      break;
      
    default:
      outFile << "Case #" << i << ": RICHARD" << endl;
    }
  }
}
