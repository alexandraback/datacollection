#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int dp[105][2];
char str[105];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s",str);
        if(str[0]=='+')
            dp[0][1]=1;
        else
            dp[0][0]=1;
        for(int i=1; i<strlen(str); i++)
        {
            if(str[i]=='+')
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=1+dp[i-1][0];
            }
            else
            {
                dp[i][1]=dp[i-1][1];
                dp[i][0]=1+dp[i-1][1];
            }
        }
        printf("Case #%d: %d\n",cas,dp[strlen(str)-1][0]);
    }
    return 0;
}
