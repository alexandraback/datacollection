#include <cstdio>
using namespace std;
int t,tt;
double c,f,x,a,b,r;
int main() {
  freopen("Bs.in","r",stdin);
  freopen("Bs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%lf%lf%lf",&c,&f,&x);
    a=2; b=0;
    do {
      r=b+x/a;
      b+=c/a;
      a+=f;
    } while (b+x/a<r);
    printf("Case #%d: %.7lf\n",t,r);
  }
  return 0;
}
