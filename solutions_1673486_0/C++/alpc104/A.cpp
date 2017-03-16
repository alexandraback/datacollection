#include <cstdio>
#include <algorithm>
#define N 100010
int a,b;
double p[N],p2,t2,t3,ans;

int main() {
  freopen("A-small-attempt0.in","r",stdin);
  freopen("small.out","w",stdout);

  int T,t,i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    scanf("%d%d",&a,&b);
    p[0]=1;
    ans=2+b;
    for (i=1;i<=a;i++) {
      scanf("%lf",&p2);
      p[i]=p[i-1]*p2;
    }
    for (i=0;i<=a;i++) {
      t3=p[a-i];
      t2=t3*(b-a+i*2+1);
      t2+=(1-t3)*(b-a+i*2+1+b+1);
      if (t2<ans) ans=t2;
    }
    printf("Case #%d: %.6lf\n",t,ans);
  }
}
