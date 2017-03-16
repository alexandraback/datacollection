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
  } else {
    if(R==1 || C==1)
      return "RICHARD";
    else if (R == 2 && C ==2)
      return "RICHARD";
    else if( (R==2 && C==4)||(R==4 && C==2))
      return "RICHARD";
    else
      return "GABRIEL";   

  }
 

}


int main() {

  ifstream input ("D-small-attempt0.in");
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
