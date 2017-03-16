#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


long long int pow10(long long int x)
{
  long long int res = 1;
  while (x-->0)
  {
    res*= 10;
  }
  return res;
}

long long int min(int a, int b)
{
  return a < b ? a: b;
}

int f (int c, int w)
{
  if (c == w) return w - 1;
  return w;
}

int main()
{  
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int R, C, W;
    cin >> R >> C >> W;
    int sol;
    if (W == 1) sol = R*C;
    else 
    {
      int a = (C/(W) - 1)*R;
      int b = R - 1;
      int c = 1 + f(W + C%W, W);
      sol = a + b + c;
      //cout << a << " " << b << " " << c << endl;
    }
    cout << "Case #" << t << ": " << sol << endl;
  }
  return 0;
}










