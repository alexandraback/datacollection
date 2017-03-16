#include <cstdio>

#define B 100001

int T,a,b;
double p[B];
double t[B];
double ret;

int main() {
  int i;
  double tmp;
  scanf("%d",&T);
  for(int lT=1;lT<=T;lT++){
    scanf("%d%d",&a,&b);
    for(i=1;i<=a;i++)scanf("%lf",&p[i]);
    t[0]=1;
    for(i=1;i<=a;i++)
      t[i]=t[i-1]*p[i];
    ret=1+b+1;
    for(i=0;i<=a;i++){
      tmp=(a-i)+(b-i)+1;
      tmp+=(b+1)*(1-t[i]);
      if(ret>tmp)ret=tmp;
    }
    printf("Case #%d: %.6lf\n",lT,ret);
  }
  return 0;
}
