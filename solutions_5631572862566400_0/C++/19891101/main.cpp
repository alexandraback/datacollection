
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>
#include <list>
#include <deque>


#include <fstream>
#include <sstream>

#include <iomanip>


#define FFF freopen("test","r",stdin)
using namespace std;

const int N=1005;

int n;
int g[N];
int g1[N];
int f[N];

int in[N];

int visit[N];

int dfs(int t,int F)
{
    visit[t]=1;
    int k=g[t];
    if(k==F) return 1;
    if(visit[k]) return 0;

    return dfs(k,F);
}

int check(int t)
{
    memset(visit,0,sizeof(visit));
    return dfs(t,t);
}

int DFS(int t)
{
    if(visit[t]) return 0;
    visit[t]=1;
    return DFS(g[t])+1;
}

void dfs1(int t,int sum)
{
    f[t]=max(f[t],sum);

    visit[t]=1;

    int k=g[t];

    if(g[k]==t) return;

    if(visit[k]) return;

    dfs1(k,sum+1);

}

int Get(int a[])
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int ok=1;
            if(i==j)
            {
                ans=max(ans,1); continue;
            }
            for(int k=i;k<=j;k++)
            {
                if(k==i)
                {
                    if(g[a[i]]!=a[j]&&g[a[i]]!=a[k+1])
                    {
                        ok=0; break;
                    }
                }
                else if(k==j)
                {
                    if(g[a[j]]!=a[i]&&g[a[j]]!=a[k-1])
                    {
                        ok=0; break;
                    }
                }
                else
                {
                    if(g[a[k]]!=a[k-1]&&g[a[k]]!=a[k+1])
                    {
                        ok=0; break;
                    }
                }
            }
            if(ok) ans=max(ans,j-i+1);
        }
    }
    return ans;
}

int baoli()
{
    int a[11];
    for(int i=1;i<=n;i++) a[i]=i;
    int ans=0;
    do
    {
        int tmp=Get(a);
        if(tmp>ans) ans=tmp;
    }while(next_permutation(a+1,a+n+1));
    return ans;
}

void deal()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        g[i]=x;
        g1[x]=i;

        f[i]=0;
        in[i]=0;
    }



    for(int i=1;i<=n;i++) if(check(i)) in[i]=1;

    int ans=1;
    for(int i=1;i<=n;i++) if(in[i])
    {
        memset(visit,0,sizeof(visit));
        int tmp=DFS(i);
        if(tmp>ans) ans=tmp;
    }

    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        dfs1(i,1);
    }

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int t=g[i];
        if(g[t]==i&&i<t)
        {
            sum+=f[i]+f[t];
        }
    }

    if(sum>ans) ans=sum;
    printf("%d\n",ans);
    return;
 //   return;

int Ans=baoli();
    if(Ans!=ans)
    {
        puts("$$$$$$$$$$$");
        printf("## %d\n",Ans);
        for(int i=1;i<=n;i++) printf("%d ",g[i]); puts("");
    }

}

int main()
{


    freopen("C-small-attempt1.in","r",stdin);;
    freopen("ans","w",stdout);
    int T;
    scanf("%d",&T);
    int num=0;
    while(T--)
    {
        printf("Case #%d: ",++num);
        deal();
    }
}

/**
7
2 1 1 3 6 7 1

**/
