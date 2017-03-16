#include <iostream>
#include <cstdio>
using namespace std;
#define INF (-1)
int a[40], b[40], k[40];
void to_binary(int *binary, int num)
{
    int p = 0;
    while (num)
    {
        if (num & 1) binary[p] = 1;
        else binary[p] = 0;
        p++;
        num >>= 1;
    }
}
long long int dp[40][2][2][2];

long long int dfs(int pos, int i, int j, int l)
{
    if (pos < 0)
    {
        if (i == 0 || j == 0 || l == 0) return 0;
        return 1;
    }
    if (dp[pos][i][j][l] != INF) return dp[pos][i][j][l];
    long long int &res = dp[pos][i][j][l];
    res = 0;
    for (int r = 0; r < 2; ++r)
    {
        if (i == 0 && r > a[pos]) continue;
        for (int t = 0; t < 2; ++t)
        {
            if (j == 0 && t > b[pos]) continue;
            if (l == 0 && (r&t) > k[pos]) continue;
            res += dfs(pos - 1, i || (r < a[pos]), j || (t < b[pos]), l || ((r&t) < k[pos]));
        }
    }
    return res;
}
int main()
{
    //freopen("B-large.in","r", stdin);
    //freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int aa, bb, kk;
        scanf("%d %d %d", &aa, &bb, &kk);
        for (int i = 0; i < 40; ++i) a[i] = b[i] = k[i] = 0;
        to_binary(a, aa);
        to_binary(b, bb);
        to_binary(k, kk);
        for (int pos = 0; pos < 40; ++pos)
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    for (int k = 0; k < 2; ++k)
                        dp[pos][i][j][k] = INF;
        printf("Case #%d: ", cas);
        printf("%lld\n", dfs(39, 0, 0, 0));
    }
    return 0;
}
