#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 50;

int adj[MAX_N][MAX_N];

int32_t main()
{
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("B-small-attempt3.out", "w", stdout);
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_)
    {
        cout << "Case #" << _ << ": ";
        int b, m;
        cin >> b >> m;
        if (m > (1LL << (b - 2)))
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        memset(adj, 0, sizeof adj);
        for (int i = 1; i < b; ++i)
            for (int j = i + 1; j < b; ++j)
                adj[i][j] = 1;
        adj[0][b - 1] = 1;
        m --;
        int x = 0;
        while (m)
        {
            if ((m & 1LL))
                adj[0][b - x - 2] = 1;
            m >>= 1LL;
            x ++;
        }
        cout << "POSSIBLE\n";
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < b; ++j)
                cout << adj[i][j];
            cout << '\n';
        }
    }
    return 0;
}
