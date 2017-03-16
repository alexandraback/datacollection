#include<cstdio>
#include<algorithm>
#define Max 100005

using namespace std;

double dp[Max][2];
double arr[Max];

int main()
{
    int z;
    scanf("%d", &z);

    for(int zi = 0; zi<z;zi++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i=1;i<=n;i++)
            scanf("%lf", &arr[i]);

        //memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for(int i=1;i<=n;i++)
        {
            //correct
            dp[i][1] = arr[i] * dp[i-1][1];
            //typo
            dp[i][0] = (1 - arr[i]) * dp[i-1][1] + dp[i-1][0];
        }

        
        double ans = m + 2;

        for(int i=0;i<=n;i++)
        {
            double a, b;
            a = dp[i][1] * ( 2*(n-i) + m - n + 1 );
            b = dp[i][0] * ( 2*(n-i) + m - n + 1 + m + 1);

            //printf("%d, %lf %lf, %lf %lf\n", i, dp[i][0], dp[i][1], a, b);
            ans = min(a + b, ans);
        }

        printf("Case #%d: %.6lf\n", zi + 1, ans);
    }
}
