#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int T, E, R, N, V[100], Dp[100][100];

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int i, TestCase, j, k;
    scanf("%i", &T);
    for(TestCase = 1; TestCase <= T; TestCase ++)
    {
        printf("Case #%i: ", TestCase);
        scanf("%i %i %i", &E, &R, &N);
        for(i = 1; i <= N; ++ i) scanf("%i", &V[i]);
        memset(Dp, 0, sizeof(Dp));
        Dp[1][E] = 0;
        for(i = 1; i <= N; ++ i)
            for(j = 0; j <= E; ++ j)
                for(k = 0; k <= j; ++ k)
                    Dp[i + 1][min(j - k + R, E)] = max(Dp[i + 1][min(j - k + R, E)], Dp[i][j] + k * V[i]);
        int Ans = 0;
        for(i = 0; i <= E; ++ i) Ans = max(Ans, Dp[N + 1][i]);
        printf("%i\n", Ans);
    }
    return 0;
}
