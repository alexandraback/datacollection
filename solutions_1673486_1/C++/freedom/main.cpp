#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100000;
double p[MAXN],f[MAXN];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,tt,a,b,i;
    double e1,e2,e3,res;
    scanf("%d",&tt);
    for(cas = 1;cas <= tt;++cas) {
      scanf("%d %d",&a,&b);
      f[0] = 1;
      for(i = 1;i <= a;++i) {
        scanf("%lf",&p[i]);
        f[i] = f[i - 1] * p[i];
      }
      e1 = b + 2;
      e2 = (2 - f[a]) * b - a + 2 - f[a];
      res = min(e1,e2);
      for(i = 1;i <= a;++i) {
        e3 = f[a - i] * (2 * i + b - a + 1) + (1 - f[a - i]) * (2 * i + 2 * b - a + 2);
        res = min(res,e3);
      }
      printf("Case #%d: %lf\n",cas,res);
    }
}
