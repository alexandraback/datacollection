#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1010;
int n;
int len[MAXN],vis[MAXN];
vector<int> nxt[MAXN];

bool bfs()
{
    for(int s=1;s<=n;++s)
    {
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(s);
        vis[s]=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=0;i<len[u];++i)
            {
                int v=nxt[u][i];
                if(vis[v]==false)
                {
                    vis[v]=true;
                    q.push(v);
                }
                else
                {
                   return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    freopen("small.in","r",stdin);
    freopen("small.out","w",stdout);
    int cn,cas=0,temp;
    int i,j;
    scanf("%d",&cn);
    while(cn--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;++i)
            nxt[i].clear();
        for(i=1;i<=n;++i)
        {
            scanf("%d",&len[i]);
            for(j=0;j<len[i];++j){
              scanf("%d",&temp);
              nxt[i].push_back(temp);
            }
        }
        printf("Case #%d: ",++cas);
        if(bfs() == true)
            printf("Yes\n");
        else
           printf("No\n");
    }
    return 0;
}
