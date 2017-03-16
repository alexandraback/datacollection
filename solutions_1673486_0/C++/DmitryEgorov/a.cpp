#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int main()
{
  int tst, cnt, a, b, i;
  long double tmp, res, p;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &tst);
  for (cnt=1; cnt<=tst; cnt++)
  {
    cerr<<cnt<<endl;
    scanf("%d%d", &a, &b), res=b+2;
    for (p=1.0, i=0; i<a; i++)
    {
      cin>>tmp, p*=tmp;
      //cerr<<i<<" "<<p<<" "<<b-a+1<<" "<<2*(a-i-1)<<endl;
      res=min(res,b-a+1+2*(a-i-1)+(1.0-p)*(b+1));
    }
    printf("Case #%d: %.8lf\n", cnt, (double)res);
  }
  return 0;
}
