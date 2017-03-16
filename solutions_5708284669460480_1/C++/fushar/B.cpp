#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

const int oo = 100000;

int T;
int K, L, S;

char keys[105], target[105];

int fail[105];
int dp[105][105];

double dp2[105][105];

int main()
{
    scanf("%d", &T);
    REP(tc, T)
    {
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s", keys);
        scanf("%s", target+1);

        int q = 0;
        fail[1] = 0;
        for (int i = 2; i <= L; i++)
        {
            while (q && target[q+1] != target[i])
                q = fail[q];
            if (target[q+1] == target[i])
                q++;
            fail[i] = q;
        }

        memset(dp, 0, sizeof dp);

        REP(i, S) REP(j, L)
            dp[i][j] = -oo;

        dp[0][0] = 0;

        REP(i, S) REP(j, L)
        {
            REP(k, K)
            {
                int add = 0;
                int newj = j;
                while (newj && target[newj+1] != keys[k])
                    newj = fail[newj];
                if (target[newj+1] == keys[k])
                    newj++;

                if (newj == L)
                {
                    add++;
                    newj = fail[newj];
                }

                dp[i+1][newj] = max(dp[i+1][newj], add + dp[i][j]);
            }
        }

        int minBananas = 0;
        REP(j, L)
            minBananas = max(minBananas, dp[S][j]);

        memset(dp2, 0, sizeof dp2);

        REP(j, L)
            dp2[S][j] = 0;

        for (int i = S-1; i >= 0; i--) REP(j, L)
        {
            REP(k, K)
            {
                int add = 0;
                int newj = j;
                while (newj && target[newj+1] != keys[k])
                    newj = fail[newj];
                if (target[newj+1] == keys[k])
                    newj++;

                if (newj == L)
                {
                    add++;
                    newj = fail[newj];
                }

                dp2[i][j] += (add + dp2[i+1][newj]) / K;
            }
        }

        printf("Case #%d: %.10lf\n", tc+1, minBananas - dp2[0][0]);
    }
}
