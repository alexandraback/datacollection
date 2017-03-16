#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define INF (1<<30)
#define MAXN 105
using namespace std;

__int64 a[MAXN],b[MAXN],A[MAXN],B[MAXN],f[MAXN][MAXN];
int n,m;

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
          int i,j;
          scanf("%d%d",&n,&m);
          for (i=1;i<=n;i++) scanf("%I64d%I64d",&a[i],&A[i]);
          for (i=1;i<=m;i++) scanf("%I64d%I64d",&b[i],&B[i]);
          memset(f,0,sizeof(f));
          for (i=1;i<=n;i++)
              for (j=1;j<=m;j++)
              {
                  f[i][j]=f[i-1][j];
                  f[i][j]=max(f[i][j],f[i][j-1]);
                  if (A[i]==B[j])
                     f[i][j]=max(f[i][j],f[i-1][j-1]+min(a[i],b[j]));
              }
          printf("Case #%d: %I64d\n",++cas,f[n][m]);
    }
    system("pause");
}
