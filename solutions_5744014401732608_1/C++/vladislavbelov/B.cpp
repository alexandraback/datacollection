#include <bits/stdc++.h>

using namespace std;

void solution();

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef HOME
    freopen("B.in", "rt", stdin);
    clock_t start = clock();
#endif
    solution();
#ifdef HOME
    cerr.precision(3);
    cerr << endl << "Total time: " << fixed << double(clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}

typedef long long ll;
#define int ll

int b, m;

int dp[64], g[64][64];

bool is_possible()
{
    dp[0] = 1;
    for (int i = 1; i < b; ++i)
    {
        dp[i] = 0;
        for (int j = 0; j < i; ++j)
        {
            dp[i] += dp[j];
        }
    }
    return dp[b - 1] >= m;
}

void solve()
{
    if (!is_possible())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;
    memset(g, 0, sizeof(int) * 64 * 64);
    /*
    for (int i = 0; i < b; ++i)
        cerr << dp[i] << " ";
    cerr << endl;
    */
    for (int i = 0; i < b - 1; ++i)
    {
        for (int j = 0; j < i; ++j)
            g[j][i] = 1;
    }
    int M = m;
    --m;
    g[0][b - 1] = 1;
    for (int i = 1; i < b - 1 && m > 0; ++i)
    {
        if (m & 1)
            g[i][b - 1] = 1;
        m >>= 1;
    }
    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < b; ++j)
            cout << g[i][j];
        cout << endl;
    }
    dp[0] = 1;
    for (int i = 1; i < b; ++i)
    {
        dp[i] = 0;
        for (int j = 0; j < i; ++j)
            if (g[j][i])
                dp[i] += dp[j];
    }
    assert(dp[b - 1] == M);
}

void solution()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << t + 1 << ": ";
        cin >> b >> m;
        solve();
    }
}
