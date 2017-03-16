#include <iostream>
#include <cstring>
using namespace std;

int dp[1<<21], N, k[32][64], K[32], T[32];

int _dp(int mask) {
    if (dp[mask] == -1) {
        int c[256], i, j;

        memset(c, 0, sizeof(c));
        for (i=0; i<=N; i++) if ((mask>>i)&1) {
            c[T[i]]--;
            for (j=0; j<K[i]; j++) c[k[i][j]]++;
        }

        for (i=0; i<=N; i++) if (!((mask>>i)&1) && c[T[i]]) {
            if (_dp(mask^(1<<i)) != -2) {dp[mask] = i; break;}
        }
        if (dp[mask] == -1) dp[mask] = -2;
    }
    return dp[mask];
}

int main() {
    int CASES, cases, i, j, cur;

    cin >> CASES;
    for (cases=1; cases<=CASES; cases++) {
        cin >> K[0] >> N;
        for (i=0; i<K[0]; i++) cin >> k[0][i];
        for (i=1; i<=N; i++) {
            cin >> T[i] >> K[i];
            for (j=0; j<K[i]; j++) cin >> k[i][j];
        }

        memset(dp, -1, sizeof(dp)); dp[(1<<(N+1))-1] = -3;
        cout << "Case #" << cases << ":";
        if (_dp(1) == -2) cout << " IMPOSSIBLE" << endl;
        else {
            cur = 1;
            while (dp[cur] != -3) {
                cout << ' ' << dp[cur];
                cur ^= (1<<dp[cur]);
            }
            cout << endl;
        }
    }

    return 0;
}
