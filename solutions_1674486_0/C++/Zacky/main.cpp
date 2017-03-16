#include <iostream>
#include <cstdio>
#include<cmath>
#include <memory.h>
#include<queue>
using namespace std;
const int maxn = 1010;
vector <int> eg[maxn];
int len[maxn];
bool vis[maxn];
int n;

bool bfs()
{
    for(int s=1;s<=n;++s)
    {
        queue <int> qq;
        memset(vis,0,sizeof(vis));
        qq.push(s);
        vis[s]=1;
        while(!qq.empty())
        {
            int u=qq.front();qq.pop();
            for(int i=0;i<len[u];++i)
            {
                int v=eg[u][i];
                if(vis[v]==false)
                {
                    vis[v]=true;
                    qq.push(v);
                }
                else
                   return true;
            }
        }
    }
    return false;
}

void solve()
{
    int temp;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        eg[i].clear();
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&len[i]);
        for(int j=0;j<len[i];++j)
        {
            scanf("%d",&temp);
              eg[i].push_back(temp);
        }
    }
    printf(bfs() ? "Yes\n" : "No\n");
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int casn,cas=0;
    scanf("%d",&casn);
    while(cas < casn)
    {
        printf("Case #%d: ",++cas);
        solve();
    }
    return 0;
}
