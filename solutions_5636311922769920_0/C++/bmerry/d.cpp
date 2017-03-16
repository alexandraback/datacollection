#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        ll K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << cas + 1 << ":";
        if (C * S < K)
        {
            cout << " IMPOSSIBLE\n";
            continue;
        }
        S = (K + C - 1) / C;
        int nxt = 0;
        for (int i = 0; i < S; i++)
        {
            ll tile = 0;
            for (int j = 0; j < C; j++)
            {
                tile = tile * K + nxt;
                nxt = (nxt + 1) % K;
            }
            cout << ' ' << tile + 1;
        }
        cout << '\n';
    }
    return 0;
}
