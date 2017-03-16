#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn=105;

int n;
int A,B,K,a[50],b[50],k[50];
long long dp[50][2][2][2];
bool vis[50][2][2][2];

long long dfs(int pos,bool pa,bool pb,bool pc)
{
    if(pos<0)return 1LL;
    if(vis[pos][pa][pb][pc])return dp[pos][pa][pb][pc];
    dp[pos][pa][pb][pc]=0;
    vis[pos][pa][pb][pc]=1;
    int ta=pa?1:a[pos],tb=pb?1:b[pos],tc=pc?1:k[pos];
    for(int i=0;i<=ta;i++)
    for(int j=0;j<=tb;j++)
    {
        if((i&j)>tc)break;
        dp[pos][pa][pb][pc]+=dfs(pos-1,pa||(i<ta),pb||(j<tb),pc||((i&j)<tc));
    }
    return dp[pos][pa][pb][pc];
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("b-ans.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        memset(vis,0,sizeof(vis));
        cin>>A>>B>>K;
        A--;B--;K--;
        for(int i=0;i<50;i++)
        {
            a[i]=A&1;
            A=A>>1;
            b[i]=B&1;
            B=B>>1;
            k[i]=K&1;
            K=K>>1;
        }
        printf("Case #%d: %I64d\n",cas,dfs(40,0,0,0));
    }
    return 0;
}
