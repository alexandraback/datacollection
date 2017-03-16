#include <iostream>
#include <cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,flag;
vector<int> v[1009];
int vis[1009];
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(!vis[y])
        dfs(y);
        else flag=1;
    }
}
void solve()
{
    scanf("%d",&n);
    flag=0;
    for(int i=0;i<=n;i++)
    v[i].clear();
    int m,t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&t);
            v[i].push_back(t);
        }
    }
    for(int i=1;i<=n;i++)
    {
            memset(vis,0,sizeof(vis));
            dfs(i);
            if(flag)break;
    }
    if(flag)puts("Yes");
    else puts("No");
}
int main()
{
    int ca;
    freopen("4.in","r",stdin);
    freopen("a2.out","w",stdout);
    scanf("%d",&ca);
    for(int ii=1;ii<=ca;ii++)
    {
        printf("Case #%d: ",ii);
        solve();
    }
    return 0;
}
