#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int MaxiS[40], MaxNo[40], isSu[40];

void init()
{
    isSu[0] = MaxiS[0] = MaxNo[0] = 0;
    for(int i = 1; i <= 30; ++i)
    {
        isSu[i] = 0;
        int avg = i / 3;
        int remain = i % 3;
        MaxNo[i] = avg;
        if(remain == 0)
        {
            if(avg + 1 <= 10)
            {
                isSu[i] = 1;
                MaxiS[i] = avg + 1;
            }
        }
        if(remain == 1)
        {
            MaxNo[i] = avg + 1;
            if(avg > 0)
            {
                isSu[i] = 1;
                MaxiS[i] = avg + 1;
            }
        }
        if(remain == 2)
        {
            MaxNo[i] = avg + 1;
            if(avg + 2 <= 10)
            {
                isSu[i] = 1;
                MaxiS[i] = avg + 2;
            }
        }
//        printf("%d  %d   %d   %d\n", i, isSu[i], MaxiS[i], MaxNo[i]);
    }


}
int ele[110];
int dp[110][110];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    init();
    int test, cas(1), n, m, least;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d%d%d", &n, &m, &least);
        for(int i = 0; i < n; ++i)
            scanf("%d", ele + i);
        sort(ele, ele + n);
        for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = -1000000000;
        dp[0][0]=  0;
        for(int i = 1; i <= n; ++i)
        {
            int val = ele[i - 1];
            for(int j = 0; j < i && j <= m; ++j)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + (MaxNo[val] >= least));
                if(isSu[val])
                {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + (MaxiS[val] >= least));
                }
            }
        }
        printf("Case #%d: %d\n",cas++, max(0, dp[n][m]));
    }
    return 0;
}
