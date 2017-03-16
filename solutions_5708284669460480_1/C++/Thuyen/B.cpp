#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) int(a.size())
#define reset(a, x) memset(a, x, sizeof(a))

#define FOR(i, a, b)   for(int i = a; i <= b; ++i)
#define FORD(i, a, b)  for(int i = a; i >= b; --i)
#define REP(i, n)      for(int i = 0, _n = n; i < _n; ++i)
#define REPD(i, n)     for(int i = n - 1; i >= 0; --i)
#define FORSZ(i, x)    for(int i = 0; i < sz(x); ++i)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vii;

#define oo 1000000007
#define eps 1E-9

int T, K, L, S, jump[105];

double dp[105][105][105];

string keys, target;

void preprocess() {
    jump[0] = -1;
    for (int i = 0, j = -1; i < target.size(); ) {
        for (; j >= 0 && target[i] != target[j]; j = jump[j]);
        jump[++i] = ++j;
    }
}


int main() {
    #ifdef LOCAL_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);

    cout << std::fixed << setprecision(10);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> K >> L >> S;
        cin >> keys >> target;

        memset(dp, 0, sizeof dp);
        memset(jump, 0, sizeof jump);

        preprocess();

        dp[0][0][0] = 1;

        for (int i = 0; i < S; ++i)
        for (int j = 0; j <= S - L + 1; ++j)
        for (int k = 0; k < L; ++k)
        if (dp[i][j][k] > 0) {
            for (int l = 0; l < K; ++l) {
                int idx = k;
                for (; idx >= 0 && keys[l] != target[idx]; idx = jump[idx]);

                ++idx;

                if (idx == L)
                    dp[i + 1][j + 1][jump[L]] += dp[i][j][k];
                else
                    dp[i + 1][j][idx] += dp[i][j][k];
            }
        }

        double res = 0;

        int maxCnt = 0;

        for (int j = 0; j <= S - L + 1; ++j)
        for (int k = 0; k < L; ++k)
        if (dp[S][j][k] > 0)
            res += dp[S][j][k] * j, maxCnt = max(maxCnt, j);

        for (int i = 0; i < S; ++i)
            res /= K;

        res = maxCnt - res;

        cout << "Case #" << t << ": " << res << "\n";
    }
}
