#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

double p[100010], pgood[100010];
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t, ntest, a, b, i, j;
    cin >> ntest;
    for(t = 1; t <= ntest; ++t)
    {
      cin >> a >> b;
      
      for(pgood[0] = 1, i = 1; i <= a; ++i)
      {
            cin >> p[i];
            pgood[i] = pgood[i-1] * p[i];
      }     
      
      double res = b + 2; //enter + retype
      res = min(res, pgood[a] * (b-a+1) + (1-pgood[a])*(2*b-a+2)); //keep typing
      
      for(i = 1; i <= a; ++i)
      {
          //backspace i times
          double expected = pgood[a-i] * (2*i+b-a+1) + (1-pgood[a-i])*(2*i+2*b-a+2); 
          res = min(res, expected);
      }
      printf("Case #%d: %.10f\n", t, res);
    }    
    return 0;
}
