#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int L=1021;
const double eps=1e-5;
int map[L][L];
bool vis[L];
int n;
bool dfs(int a)
{
    if(vis[a])
        return true;
    int i;
    vis[a]=1;
    for(i=0;i<n;i++)
    {
        if(a!=i && map[a][i])
        {
            if(dfs(i))
                return true;
        }
    }
    return false;
}

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int t,q=1,i,j,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {
            vis[i]=0;
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&j);
                map[j-1][i]=1;
            }
        }
        bool k=0;
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                k=1;
            if(k) break;
        }
        printf("Case #%d: ",q++);
        if(k) puts("Yes");
        else puts("No");
    }
    return 0;
}
