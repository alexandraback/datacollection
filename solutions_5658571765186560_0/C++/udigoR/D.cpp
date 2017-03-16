#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("D-small-attempt1.in");
  ofstream out("D-small-attempt1.out");

  //ifstream in("D-large.in");
  //ofstream out("D-large.out");

  in >> T;

  for(int i=0; i<T; ++i)
  {
    int solve = 0; 
    int X, R, C;
    bool isRichard = true;

    in >> X >> R >> C;

    if( (R*C) % X != 0)
      isRichard = true;
    else
    {
      if(X==1 || X == 2)
        isRichard = false;

      if(X==3)
        if( R*C == 3)
          isRichard = true;
        else
          isRichard = false;

      if(X==4)
      {
        if(R==4 && C==4)
          isRichard = false;
        if((R==4 && C==3) || (R==3 && C==4))
          isRichard = false;
      }

      if(X==5)
      {
      }

      if(X==6)
      {
      }

      if(X>=7)
        isRichard = true;
    }


    out << "Case #"<<i+1<<": ";

    if(isRichard)
      out << "RICHARD" << endl;
    else
      out << "GABRIEL" << endl;
  }

  return 0;
}