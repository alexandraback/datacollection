#include <stdio.h>
double min(double a,double b){return a<b?a:b;}
int T,A,B;
double p[110000],pp[110000];
int main(int argc, const char *argv[])
{
  scanf("%d",&T);
  for(int tm=1;tm<=T;tm++){
    printf("Case #%d: ",tm);
    scanf("%d%d",&A,&B);
    for(int i=0;i<A;i++)
      scanf("%lf",p+i);
    double ans=B+2;
    pp[0]=1;
    for(int i=1;i<=A;i++)
      pp[i]=pp[i-1]*p[i-1];
    for(int i=0;i<=A;i++){
      double t=pp[i];
      ans=min(ans,A-i+t*(B-i+1)+(1-t)*(B-i+B+2));
    }
    printf("%.6f\n",ans);
  }
  return 0;
}
