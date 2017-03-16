#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define FILE_IO
int dp[10], a[55][55];
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

        LL N, M;
        scanf("%lld%lld", &N, &M);

        int ok = 0;

        for(LL K = 1; K < N; K++)
            if( (1LL << (K - 1) >= M) )
            {
                memset(a, 0, sizeof(a));
                for(int i = 1; i <= K; i++)
                    for(int j = i + 1; j <= K; j++)
                        a[i][j] = 1;
                for(int i = 1; i <= K; i++)
                    a[i][N] = 1;

                LL rem = (1LL << (K - 1)) - M;
                for(int i = 2; i <= K; i++)
                    if( (1LL << (i - 2)) & rem )
                        a[i][N] = 0;

                printf("POSSIBLE\n");
                for(int i = 1; i <= N; i++, printf("\n"))
                    for(int j = 1; j <= N; j++)
                        printf("%d", a[i][j]);
                ok = 1;
                break;

            }

        if(!ok)
            printf("IMPOSSIBLE\n");
    }

    return 0;
}
