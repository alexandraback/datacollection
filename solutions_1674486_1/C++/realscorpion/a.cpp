#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n,node[1005],vis[1005],edg_cnt;

struct link
{
    int v,next;
}edge[500000];

void addedge(int u,int v)
{
    edge[edg_cnt].v=v;
    edge[edg_cnt].next=node[u];
    node[u]=edg_cnt++;
}

bool dfs(int u)
{
    //printf("vis node %d\n",u);
    vis[u]=1;
    int v;
    for(int i=node[u];i;i=edge[i].next)
    {
        v=edge[i].v;
        if(vis[v]==2)
            return true;
        if(!vis[v] && dfs(v))
            return true;
    }
    vis[u]=2;
    return false;
}

int main()
{
    //freopen("t.txt","r",stdin);
    //freopen("A-small-attempt2.in","r",stdin);
    //freopen("A-small-attempt2-out.txt","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int T;
    scanf("%d",&T);

    for(int ii=1;ii<=T;++ii)
    {
        printf("Case #%d: ",ii);
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(node,0,sizeof(node));
        edg_cnt=1;
        int m;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&m);
            for(int j=1;j<=m;++j)
            {
                int v;
                scanf("%d",&v);
                addedge(i,v);
            }
        }

        bool succ=false;
        for(int i=1;i<=n;++i)
        {
            memset(vis,0,sizeof(vis));
            //if(!vis[i])
            {
                if(dfs(i))
                {
                    puts("Yes");
                    succ=true;
                    break;
                }
            }
        }
        if(!succ)
            puts("No");
    }
    return 1;
}
