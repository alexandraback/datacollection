#include <iostream>
#include <cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n;
vector<int> eg[1005];
int len[1005];
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
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cn,cc=0,temp;
    scanf("%d",&cn);
    while(cn--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            eg[i].clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&len[i]);
            for(int j=0;j<len[i];++j){
              scanf("%d",&temp);
              eg[i].push_back(temp);
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
