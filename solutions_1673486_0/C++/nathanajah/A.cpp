#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;

int t,aaaa;
int n,m,i;
double dp[200000][2];
double prob[200000];
double mini;

int main()
{
    scanf("%d",&t);
    for (aaaa=0;aaaa<t;++aaaa)
    {
        memset(dp,-1,sizeof(dp));
        dp[0][1]=1;
        dp[0][0]=0;
        scanf("%d %d",&n,&m);
        for (i=1;i<=n;++i)
            scanf("%lf",&prob[i]);
        mini=min(n+m+1,m+2);
        for (i=1;i<=n;++i)
        {
            dp[i][1]=dp[i-1][1]*prob[i];
            dp[i][0]=dp[i-1][1]*(1-prob[i])+dp[i-1][0];
            mini=min(mini,(n-2*i+m+1)*dp[i][1]+(n-2*i+2*m+2)*dp[i][0]);
        }
        printf("Case #%d: %.6lf\n",aaaa+1,mini);
    }
}
