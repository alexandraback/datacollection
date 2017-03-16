#include <iostream>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<map>
#include<vector>
#include <algorithm>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int dp[110];

int main()
{
    freopen("ppppp.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);

    int T,icase = 1;

    scanf("%d",&T);

    while(T--)
    {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;

        int C,D,V;
        scanf("%d %d %d",&C,&D,&V);

        int x;

        while(D--)
        {
            scanf("%d",&x);
            for(int i = V;i >= x; --i)
                dp[i] = (dp[i]|dp[i-x]);
        }

        int ans = 0;

        for(int i = 1;i <= V; ++i)
        {
            if(dp[i] == 0)
            {
                ans++;
                for(int j = V;j >= i; --j)
                    dp[j] = (dp[j]|dp[j-i]);
            }
        }

        printf("Case #%d: %d\n",icase++,ans);
    }

    return 0;
}






