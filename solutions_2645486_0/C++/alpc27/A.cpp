#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int a[12];
int dp[12][12];

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,kk;
    int T;
    int E,R,N;
    scanf("%d", &T);
    for (kk = 1;kk <= T;kk++)
    {
        scanf("%d%d%d", &E, &R, &N);
        if (R > E)
            R = E;
        for (i = 1;i <= N;i++)
            scanf("%d", &a[i]);
        printf("Case #%d: ", kk);
        memset(dp,-1,sizeof(dp));
        dp[0][E] = 0;
        for (i = 1;i <= N;i++)
        {
            for (j = E;j >= R;j--)
            {
                if (dp[i - 1][j] != -1)
                {
                    for (k = 0;k <= j;k++)
                    {
                        //if (i == 2 && j == 2 && k == 2)
                            //printf("%d %d\n", dp[i - 1][j], k * a[i]);
                        dp[i][min(E, j - k + R)] = max(dp[i][min(E, j - k + R)], dp[i - 1][j] + k * a[i]);
                        //printf("aaa %d %d %d %d\n", i, j, k, dp[i][min(E, j - k + R)]);
                    }
                }
            }
        }
        int ans = -1;
        for (i = 0;i <= N;i++)
        {
            for (j = 0;j <= E;j++)
                ans = max(ans, dp[i][j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
