#include <queue>
#include <bitset>
#include <cstdio>
#include <iostream>


using namespace std;

const int MAXN = 110;

int jasonA[MAXN], DisneyB[MAXN], n, m;
long long lhA[MAXN], lhB[MAXN], f[MAXN][MAXN], sumA[MAXN][MAXN], sumB[MAXN][MAXN];

int main()
{
	//HelloWorld
    int tcgcabcd;
    scanf("%d", &tcgcabcd);
    for (int test = 1; test <= tcgcabcd; test++)
    {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%d", &(lhA[i]), &(jasonA[i]));
            f[i][0] = 0;
        }
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld%d", &(lhB[j]), &(DisneyB[j]));
            f[0][j] =  0;
        }
        f[0][0] = 0;
        for (int i = 1; i <= 100; i++)
            sumA[0][i] = sumB[0][i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 100; j++)
                sumA[i][j] = jasonA[i] == j ? sumA[i - 1][j] + lhA[i] : sumA[i - 1][j];
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= 100; j++)
                sumB[i][j] = DisneyB[i] == j ? sumB[i - 1][j] + lhB[i] : sumB[i - 1][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
                if (jasonA[i] == DisneyB[j])
                {
                    int target = jasonA[i];
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
