#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 100010;
double p[N] , dp[N][2] , pro[N];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ans.large","w",stdout);
    int t ,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        int n , m ;
        scanf("%d %d",&n,&m);
        for(int i = 1; i<= n ; i ++)
            scanf("%lf",&p[i]);

        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        // 1 correct 0 wrong

        for(int i = 1 ; i <= n ;i ++)
        {
            dp[i][0] = dp[i-1][0] * p[i];
            dp[i][1] = dp[i-1][1] + dp[i-1][0] * (1 - p[i]);
        }
        double sum = dp[n][0] * (m - n + 1) + dp[n][1] * ( m - n + 1 + m + 1);
        double expect = 2 + m;
        expect = min(expect , sum);
        for(int i = n - 1 , j = 1 ; i >= 0 ; i -- , j ++)
        {
            double now = dp[i][0] * ( m - i + j  + 1) + dp[i][1] * ( m - i + j +  1 +  m + 1);
            expect = min(expect , now);
            //printf("%d %.12lf\n",i,now);
        }
        printf("Case #%d: %.12lf\n",cas++,expect);
    }
    return 0;
}
