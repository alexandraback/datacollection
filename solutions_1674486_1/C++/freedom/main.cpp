#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
int n;
vector<int> graph[MAXN];
int len[MAXN];
bool visited[MAXN];
bool Bfs()
{
    for(int s=1;s<=n;++s)
    {
        queue<int> open;
        memset(visited,0,sizeof(visited));
        open.push(s);
        visited[s]=1;
        while(!open.empty())
        {
            int u=open.front();open.pop();
            for(int i=0;i<len[u];++i)
            {
                int v=graph[u][i];
                if(visited[v]==false)
                {
                    visited[v]=true;
                    open.push(v);
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
    freopen("a.in","r",stdin);
    freopen("a.txt","w",stdout);
    int cas,tt,tmp;
    tt = 0;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            graph[i].clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&len[i]);
            for(int j=0;j<len[i];++j){
              scanf("%d",&tmp);
              graph[i].push_back(tmp);
            }
        }
        printf("Case #%d: ",++tt);
        if(Bfs())
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

