#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void solve(int T);

/*
   0 : x+ : E
   1 : x- : W
   2 : y+ : N
   3 : y- : S
*/

int main()
{
	int T;
	cin >> T;
  for(int i=1; i<=T; i++)
    solve(i);
}	

void solve(int T)
{
  cout << "Case #" << T << ": "; 
  int X, Y;
  cin >> X >> Y;
  for(int i=0; i<abs(X); i++)
  {
    if(X > 0)
      cout << "WE";
    else
      cout << "EW";
  }
  for(int i=0; i<abs(Y); i++)
  {
    if(Y > 0)
      cout << "SN";
    else
      cout << "NS";
  }
  cout << endl;
}

