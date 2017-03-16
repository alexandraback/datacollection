#include <cstdio>
using namespace std;
#define LL long long
#define N 256
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
LL a[N],A[N],b[N],B[N],ans;
LL f[N][N],sa[N][N],sb[N][N];
int n,m,ty;

void doit() {
  register int i,j,k,t,typ;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) {
      for (k=1;k<=i;k++)
        for (t=1;t<=j;t++)
          for (typ=1;typ<=ty;typ++)
            f[i][j]=max((LL)f[i][j],
                        (LL)f[i-k][j-t]+
                        min(sa[typ][i]-sa[typ][i-k],
                            sb[typ][j]-sb[typ][j-t]));
    }
}

int main() {
  freopen("small.in","r",stdin);
  freopen("small.out","w",stdout);

  int T,t;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    register int i,j;
    scanf("%d%d",&n,&m),ty=0;
    for (i=1;i<=n;i++) {
      scanf("%lld%lld",&a[i],&A[i]);
      if (ty<A[i]) ty=A[i];
      for (j=0;j<=100;j++)
        sa[j][i]=sa[j][i-1];
      sa[A[i]][i]+=a[i];
    }
    for (i=1;i<=m;i++) {
      scanf("%lld%lld",&b[i],&B[i]);
      if (ty<B[i]) ty=B[i];
      for (j=0;j<=100;j++)
        sb[j][i]=sb[j][i-1];
      sb[B[i]][i]+=b[i];
    }
    for (i=0;i<=n;i++)
      for (j=0;j<=m;j++)
        f[i][j]=0;

    doit();
    ans=f[n][m];
    printf("Case #%d: %lld\n",t,ans);
  }
}
