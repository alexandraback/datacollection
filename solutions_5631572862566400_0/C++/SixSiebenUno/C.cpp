#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 1007;

int T,n,bff[MaxN],in[MaxN];
int len,ans,ans2;
bool vis[MaxN];
vector<int> iv[MaxN];

void Init()
{
    scanf("%d",&n); ans = ans2 = 0;
    for (int i=1; i<=n; i++) in[i] = 0,iv[i].clear(),vis[i]=false;
    for (int i=1; i<=n; i++)
    {
        scanf("%d",bff+i); in[bff[i]]++;
        iv[bff[i]].push_back(i);
    }
}

void DFS(int x)
{
    vis[x] = true;
    if(!vis[bff[x]])
    {
        len++; DFS(bff[x]);
    }
    return;
}

void Calc(int x,int s)
{
    if(s>len) len=s;
    vis[x] = true;
    for (int i=0; i<iv[x].size(); i++)
    {
        if(!vis[iv[x][i]]) Calc(iv[x][i],s+1);
    }
    return;
}

void Solve()
{
    int i,k; ans = ans2 = 0;
    while (true)
    {
        for (i=1; i<=n&&in[i]; i++);
        if (i>n) break;
        in[i] = -1;
        in[bff[i]]--;
    }
    for (i=1; i<=n; i++)
        if(in[i]>0&&!vis[i])
        {
             len = 1;
             DFS(i);
             if(len>2)
             {
                 if(len>ans) ans = len;
             }
             else if(len==2)
             {
                 k = len;
                 len = 0; Calc(i,0); k+=len;
                 len = 0; Calc(bff[i],0); k+=len;
                 ans2 += k;
             } 
        }
    if(ans2>ans) ans=ans2;
    printf("%d\n",ans);
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for (int i=1; i<=T; i++)
    {
        printf("Case #%d: ",i);
        Init(); Solve();
    }
    return 0;
}
