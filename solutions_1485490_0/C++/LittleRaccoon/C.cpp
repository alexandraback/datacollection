// code jam round 1C
// problem C

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 110;

int typeA[MAXN], typeB[MAXN], n, m;
long long accountA[MAXN], accountB[MAXN], f[MAXN][MAXN], sumA[MAXN][MAXN], sumB[MAXN][MAXN];

int main()
{
    int testcase;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%d", &(accountA[i]), &(typeA[i]));
            f[i][0] = 0;
        }
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld%d", &(accountB[j]), &(typeB[j]));
            f[0][j] =  0;
        }
        f[0][0] = 0;
        for (int i = 1; i <= 100; i++)
            sumA[0][i] = sumB[0][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 100; j++)
                sumA[i][j] = typeA[i] == j ? sumA[i - 1][j] + accountA[i] : sumA[i - 1][j];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= 100; j++)
                sumB[i][j] = typeB[i] == j ? sumB[i - 1][j] + accountB[i] : sumB[i - 1][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
                if (typeA[i] == typeB[j])
                {
                    int target = typeA[i];
                    for (int k1 = 0; k1 < i; k1++)
                        for (int k2 = 0; k2 < j; k2++)
                        {
                            long long delta = sumA[i][target] - sumA[k1][target] < sumB[j][target] - sumB[k2][target] ? sumA[i][target] - sumA[k1][target] : sumB[j][target] - sumB[k2][target];
                            f[i][j] = f[k1][k2] + delta > f[i][j] ? f[k1][k2] + delta : f[i][j];
                        }
                }
            }
        printf("Case #%d: %lld\n", test, f[n][m]);
    }
    return 0;
}
