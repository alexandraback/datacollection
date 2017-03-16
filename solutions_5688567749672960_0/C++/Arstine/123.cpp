#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#include<limits.h>
#include<cmath>
#include<set>
#include<stack>
#include<deque>

using namespace std;

#define lim 1000001

int dp[lim];

int rev(int n)
{
    int m=0;
    while(n)
    {
        m=m*10+n%10;
        n/=10;
    }
    return m;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t,T,i,x,n;
    for(i=0;i<lim;i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(i=1;i<lim;i++)
    {
        dp[i]=min(dp[i-1]+1,dp[i]);
        x=rev(i);
        if(x>i && x<lim)
            dp[x]=min(dp[x],dp[i]+1);
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",t,dp[n]);
    }

    return 0;
}
