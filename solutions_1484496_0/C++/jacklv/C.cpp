#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int N=512;
const int Sum=2100000;

int T,t,n,m,a[N],f[Sum];
string stri[Sum];

int dfs(int x,long long k,string p)
{
  if (f[k]&&stri[k]!=p)
  {
    printf("%s\n%s\n",stri[k].data(),p.data());
    return 1;
  }
  f[k]=1,stri[k]=p;
  int i;
  char st[36];
  for (i=x+1;i<=n;i++)
 {
    sprintf(st,"%d ",a[i]);
    if (dfs(i,k+a[i],p+st)) return 1;
  }
  return 0;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  int i,j,k;
  scanf("%d",&T);
  for (t=1;t<=T;t++) {
    printf("Case #%d:\n",t);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%d",a+i);
    memset(f,0,sizeof(f));
    if (!dfs(0,0,"")) printf("Impossible\n");
  }
}
