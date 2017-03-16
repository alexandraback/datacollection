#include <stdio.h>
double min(double a,double b){return a<b?a:b;}
int main(int argc, const char *argv[])
{
  int T,A,B;
  double p[110];
  scanf("%d",&T);
  for(int tm=1;tm<=T;tm++){
    printf("Case #%d: ",tm);
    scanf("%d%d",&A,&B);
    for(int i=0;i<A;i++)
      scanf("%lf",p+i);
    double ans=B+2;
    for(int i=0;i<=A;i++){
      double t=1;
      for(int j=0;j<i;j++)
        t*=p[j];
      ans=min(ans,A-i+t*(B-i+1)+(1-t)*(B-i+B+2));
    }
    printf("%.6f\n",ans);
  }
  return 0;
}
