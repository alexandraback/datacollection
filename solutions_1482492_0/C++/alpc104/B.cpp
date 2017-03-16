#include <cstdio>
#include <cmath>
int T,n,a;
double t[20],at[20],g[100];
double dis,mv,ans;

int main() {
  freopen("small.in","r",stdin);
  freopen("small.out","w",stdout);

  register int i,j,k,p;
  scanf("%d",&T);
  for (p=1; p<=T; p++) {
    printf("Case #%d: \n",p);
    scanf("%lf%d%d",&dis,&n,&a);
    for (i=1; i<=n; i++)
      scanf("%lf%lf",&t[i],&at[i]);
    for (i=1; i<=a; i++)
      scanf("%lf",&g[i]);

    if (n==1) {
      for (i=1; i<=a; i++) {
        ans=sqrt(dis*2/g[i]);
        printf("%.8lf\n",ans);
      }
      continue;
    }
    mv=(at[2]-at[1])/(t[2]-t[1]);
    if (n==2&&at[n]>dis) {
      t[n]=((dis-at[1])/(at[n]-at[1]))*t[n];
      at[n]=dis;
    }
    for (i=1; i<=a; i++) {
      ans=((sqrt(mv*mv+at[1]*2*g[i])+mv)/g[i])<t[2]?t[2]:sqrt(dis*2/g[i]);
      printf("%.8lf\n",ans);
    }
  }
  return 0;
}
