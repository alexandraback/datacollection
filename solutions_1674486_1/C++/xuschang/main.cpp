#include <iostream>
#include <cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n;
vector<int> edge[1005];
int Len[1005];
bool vis[1004];
bool bfs()
{
    for(int s=1;s<=n;++s)
    {
        queue<int> qq;
        memset(vis,0,sizeof(vis));
        qq.push(s);
        vis[s]=1;
        while(!qq.empty())
        {
            int u=qq.front();qq.pop();
            for(int i=0;i<Len[u];++i)
            {
                int v=edge[u][i];
                if(vis[v]==false)
                {
                    vis[v]=1;
                    qq.push(v);
                }
                else
                   return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,cc=0,temp;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            edge[i].clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&Len[i]);
            for(int j=0;j<Len[i];++j){
              scanf("%d",&temp);
              edge[i].push_back(temp);
            }
        }
        printf("Case #%d: ",++cc);
        if(bfs())
            printf("Yes\n");
        else
           printf("No\n");
    }
    return 0;
}

