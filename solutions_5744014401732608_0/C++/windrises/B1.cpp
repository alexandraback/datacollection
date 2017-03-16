#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<complex>
#define ft first
#define sd second
#define pb push_back
#define mkp make_pair
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)<(b)?(b):(a))
using namespace std;
typedef long long LL;
typedef pair<int,int> Pair;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
const int maxn=8;
int n,m;
bool g[maxn][maxn];
int dp[maxn];
int dfs1(int u)
{
    if(dp[u]!=-1) return dp[u];
    dp[u]=0;
    for(int i=1;i<=n;i++)
    {
        if(g[u][i])
        {
            dp[u]+=dfs1(i);
        }
    }
    return dp[u];
}
bool check()
{
    memset(dp,-1,sizeof(dp));
    dp[n]=1;
    dfs1(1);
    if(dp[1]==m) return 1;
    else return 0;
}
void print()
{
    puts("POSSIBLE");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d",g[i][j]);
        }
        puts("");
    }
}
bool dfs(int x,int y,bool f)
{
    g[x][y]=f;
    if(x==y&&f==1) return 0;
    if(x==n-1&&y==n)
    {
        if(check())
        {
            print();
            return 1;
        }
        return 0;
    }
    int tx=x,ty=y+1;
    if(ty>n)
    {
        tx++;
        ty=1;
    }
    if(dfs(tx,ty,0)) return 1;
    if(dfs(tx,ty,1)) return 1;
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    //freopen("B-large.in","r",stdin);
    //freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        memset(g,0,sizeof(g));
        scanf("%d%d",&n,&m);
        printf("Case #%d: ",kase);
        if(!dfs(1,1,0))
            puts("IMPOSSIBLE");
    }
}
