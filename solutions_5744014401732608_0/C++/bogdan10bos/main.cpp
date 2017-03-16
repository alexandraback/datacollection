#include <bits/stdc++.h>

using namespace std;

#define FILE_IO
int dp[10], a[10][10];
int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);

        int N, M;
        scanf("%d%d", &N, &M);
        /*if(M > (1 << (N - 2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }*/

        //printf("POSSIBLE\n");
        int ok = 0;
        int K = N * (N - 1) / 2;
        for(int msk = 0; msk < 1 << K; msk++)
        {
            memset(a, 0, sizeof(a));
            memset(dp, 0, sizeof(dp));

            int bt = -1;
            for(int i = 1; i < N; i++)
                for(int j = i + 1; j <= N; j++)
                {
                    bt++;
                    if( (1 << bt) & msk )
                        a[i][j] = 1;
                }

            dp[N] = 1;
            for(int i = N - 1; i >= 1; i--)
            {
                dp[i] = 0;
                for(int j = i + 1; j <= N; j++)
                    if(a[i][j])
                        dp[i] += dp[j];
            }

            if(dp[1] == M)
            {
                printf("POSSIBLE\n");
                for(int i = 1; i <= N; i++, printf("\n"))
                    for(int j = 1; j <= N; j++)
                        printf("%d", a[i][j]);
                ok = 1;
                break;
            }
        }

        if(!ok)
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
