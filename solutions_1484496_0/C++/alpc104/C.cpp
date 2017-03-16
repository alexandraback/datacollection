#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define N 512
#define Sum 2100000
int T,t,n,m,a[N],f[Sum];
string path[Sum];

int dfs(int x,long long k,string p) {
  //printf("dfs(%d,%lld,%s)\n",x,k,p.data());
  if (f[k]&&path[k]!=p) {
    printf("%s\n%s\n",path[k].data(),p.data());
    return 1;
  }
  f[k]=1,path[k]=p;
  register int i;
  static char st[36];
  for (i=x+1;i<=n;i++) {
    sprintf(st,"%d ",a[i]);
    if (dfs(i,k+a[i],p+st)) return 1;
  }
  return 0;
}

int main() {
  freopen("C-small-attempt0.in","r",stdin);
  freopen("out.txt","w",stdout);
  register int i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    printf("Case #%d:\n",t);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d",a+i);
    memset(f,0,sizeof(f));
    if (!dfs(0,0,"")) printf("Impossible\n");
  }
  return 0;
}
