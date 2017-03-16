#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool flag;
bool vis[1005];
int conv[1005];
int edg[1005][1005];
int n,cas(0);

void dfs(int x)
{
    int i(0);
    for(i=1; i<=edg[x][0]; ++i)
    {
        if(!vis[edg[x][i]])
        {
            vis[edg[x][i]] = 1;
            dfs(edg[x][i]);
            if(flag) return;
        }
        else
        {
            flag= true;
            return;
        }
    }
}

void solve()
{
    int i(0),j(0);
    scanf("%d", &n);
    flag = false;
    memset(vis,0,sizeof(vis));
    for(i=1; i<=n; ++i)
    {
        scanf("%d", &edg[i][0]);
        for(j=1; j<=edg[i][0]; ++j)
        {
            scanf("%d", &edg[i][j]);

        }
    }
    for(i=1; i<=n; ++i)
    {
        if(edg[i][0]>1)
        {
            memset(vis,0,sizeof(vis));
            vis[i] =1;
            dfs(i);
            if(flag) break;
        }
    }
    if(flag) printf("Case #%d: Yes\n",++cas);
    else printf("Case #%d: No\n",++cas);
}


int main()
{
    int t(0);
    freopen("A-large.in","r",stdin);
    freopen("A-small-attempt.out","w",stdout);
    scanf("%d", &t);
    while(t--)
    {
        solve();
    }
    return 0;
}
