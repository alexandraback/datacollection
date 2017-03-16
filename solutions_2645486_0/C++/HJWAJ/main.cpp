#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
long long v[10005];
int dfs(int nowe,int now,int n,int e,int r)
{
    long long mmax=0,tmp;
    if(now==n)return 0;
    for(int i=0;i<=nowe;i++)
    {
        tmp=v[now]*i+dfs(min(nowe-i+r,e),now+1,n,e,r);
        if(tmp>mmax)mmax=tmp;
    }
    return mmax;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,tt=0,n,i;
    long long e,r,ans;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        scanf("%lld%lld%d",&e,&r,&n);
        for(i=0;i<n;i++)scanf("%lld",v+i);
        ans=dfs(e,0,n,e,r);
        printf("Case #%d: %lld\n",tt,ans);
    }
    return 0;
}
