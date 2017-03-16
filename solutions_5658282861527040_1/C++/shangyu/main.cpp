#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 100000
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
LL dp[35][2][2][2];
int d1[35],d2[35],d3[35];
LL dfs(int i,int a,int b,int c)
{
    if(i==-1)
    return 1;
    LL  & ans = dp[i][a][b][c];
    int j,g,e;
    if(ans==-1)
    {
        ans = 0;
    for(j = 0; j <= (a?d1[i]:1) ; j++)
    {
        for(g = 0; g <= (b?d2[i]:1) ; g++)
        {
            e = (j&g);
            if(!c||e<=d3[i])
            ans+=dfs(i-1,a&&(j==d1[i]),b&&(g==d2[i]),c&&(e==d3[i]));
        }
    }
    }
    return ans;
}
LL cal(int a,int b,int c)
{
    int g = 0;
    while(a)
    {
        d1[g++] = a%2;
        a/=2;
    }
    g = 0;
    while(b)
    {
        d2[g++] = b%2;
        b/=2;
    }
    g = 0;
    while(c)
    {
        d3[g++] = c%2;
        c/=2;
    }
    return dfs(30,1,1,1);
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t,n,m,k;
    cin>>t;
    int ko = 0;
    while(t--)
    {
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        memset(d3,0,sizeof(d3));
memset(dp,-1,sizeof(dp));
        cin>>n>>m>>k;
        n--,m--,k--;
        printf("Case #%d: ",++ko);
        cout<<cal(n,m,k)<<endl;
    }
    return 0;
}
