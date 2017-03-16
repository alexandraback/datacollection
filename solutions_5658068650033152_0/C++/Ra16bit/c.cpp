#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int t,tt,i,j,k,p,n,m,e,r,inf,f[22][88][22];
int main() {
  freopen("Cs.in","r",stdin);
  freopen("Cs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&n,&m,&e);
    memset(f,0,sizeof(f));
    r=3*(n+m);
    for (i=1; i<=m; i++) f[1][i][i]=i;
    for (i=1; i<=n; i++) for (j=1; j<=2*(n+m); j++) for (k=1; k<=m; k++) if (f[i][j][k]>0) {
      //printf("%d %d %d = %d\n",i,j,k,f[i][j][k]);
      if (f[i][j][k]>=e) r=min(r,j+(i==1?0:max(0,k-2)));
      //printf("%d\n",r);
      if (i==n) continue;
      for (p=-2; p<=2; p++) if (k+p>=1 && k+p<=m) f[i+1][j+min(k+p,2)][k+p]=max(f[i+1][j+min(k+p,2)][k+p],f[i][j][k]+k+p);
    }
    printf("Case #%d: %d\n",t,r);
    if (n==1 || m==1 || e<=4) {
    //printf("%d %d %d %d\n",n,m,e,r);
      //if (e!=r) puts("!!!!");
    }
  }
  return 0;
}
