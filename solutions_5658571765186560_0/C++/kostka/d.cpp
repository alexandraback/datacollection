#include "bits/stdc++.h"

using namespace std;

vector <int> I;
vector <int> K;
set <pair <int, int> > J;

bool M[] = {0,0,0,0, 
            0,0,0,0,
            0,0,0,0,
            0,0,0,0,

            1,0,1,0,
            0,0,0,0,
            1,0,1,0,
            0,0,0,0,

            1,1,1,1,
            1,1,0,1,
            1,0,0,0,
            1,1,0,1,

            1,1,1,1,
            1,1,1,1,
            1,1,1,0,
            1,1,0,0};

string test()
{
  int a, b, c;
  cin >> a >> b >> c;
  if(M[(a-1)*16+(b-1)*4+(c-1)] == 0)
    return "GABRIEL";
  else
    return "RICHARD";
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
  {
    //cerr << tti << "\n";
    cout << "Case #" << tti << ": " << test() << "\n";
  }
}
