#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 1100
using namespace std;
int a[N],vis[N],hh[N];
int b[N];
int n,m,k;
int f;
void dfs2(int i)
{
    if(i==n+1)
    {
        int now=1;
        for(int j=1;j<=n;j++)
            if(hh[j])
                now*=b[j];
        vis[now]=1;
        return;
    }
    hh[i]=0;
    dfs2(i+1);
    hh[i]=1;
    dfs2(i+1);
}
void dfs1(int i)
{
    if(f)return;
    if(i==n+1)
    {
        memset(hh,0,sizeof(hh));
        memset(vis,0,sizeof(vis));
        dfs2(1);
        int find=0;
        for(int j=1;j<=k;j++)
            if(!vis[a[j]])
            {
                find=1;break;
            }
        if(!find)
        {
            for(int j=1;j<=n;j++)
                printf("%d",b[j]);
            puts("");
            f=1;
        }
        return;
    }
    for(int j=2;j<=m;j++)
    {
        b[i]=j;
        dfs1(i+1);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #1:\n");
        int R;
        scanf("%d%d%d%d",&R,&n,&m,&k);
        while(R--)
        {
            for(int i=1;i<=k;i++)
                scanf("%d",&a[i]);
            f=0;
            dfs1(1);
        }
    }
    return 0;
}
