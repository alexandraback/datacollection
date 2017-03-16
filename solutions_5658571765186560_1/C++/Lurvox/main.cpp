#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <cmath>


using namespace std;

static int X,R,C;


string solve() {

  if(X==1)
    return "GABRIEL";
  if((R*C)%X !=0) {
    return "RICHARD";
  }  
  if(X==2) {
    return "GABRIEL";
  }
  if(X==3) {
    if(R==1 || C==1)
      return "RICHARD";
    else {
      return "GABRIEL";
    }    
  }
  if (X==4){
    if(R==1 || C==1)
      return "RICHARD";
    else if (R == 2 && C ==2)
      return "RICHARD";
    else if( (R==2 && C==4)||(R==4 && C==2))
      return "RICHARD";
    else
      return "GABRIEL";   

  } else { //For larger input
    if(X>=7) //Richard always chooses the "donut"
      return "RICHARD";
    if(X>R && X>C)
      return "RICHARD";
    if(3>R || 3 > C)
      return "RICHARD";

    int min = R <= C? R : C;
    int max = R >= C? R : C;
    if(X==5) {
      if(min == 3) {
	if(max == 5) 
	  return "RICHARD";
	else
	  return "GABRIEL";
      } else {
	return "GABRIEL";
      }
    } else {//X==6, final analysis
      if(min == 3){
	return "RICHARD";
      } else {
	return "GABRIEL";
      }
    }
  }
 

}


int main() {

  ifstream input ("D-large.in");
  ofstream output ("output.txt");
  int T;
  input >> T;
  for (int i=1; i<=T; i++) {
    input >> X >> R >> C;
    output << "Case #" << i <<": " << solve() << "\n";
  }

  input.close();
  output.close();

  return 0;
}
