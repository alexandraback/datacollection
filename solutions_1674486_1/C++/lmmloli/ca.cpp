#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int map[1005][1005];
int n;
int work()
{
    int i,j,k;
    for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
        if (i==k || j==k || i==j) continue;
        if (map[i][k]==1 && map[k][j]==1)
        {
            if (map[i][j]==1) return 1;
            else map[i][j]=1;
        }
    }
   return 0;
}
int main()
{
    int t,i,j,m,x,ca=0;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for (j=1;j<=m;j++)
            {
                scanf("%d",&x);
                map[x][i]=1;
            }
        }
        int ret = work();
        if (ret==1) printf("Case #%d: Yes\n",++ca);
        else printf("Case #%d: No\n",++ca);
    }
    return 0;
}
