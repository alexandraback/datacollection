#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define FILENAME "B-small-attempt2"

int dp[1024][1024];
int INF = 1001;


void init() {
    int MAX = 10;
    for(int i = 1; i <= MAX; ++i) {
        for(int d = 1; d <= MAX; ++d) {
            if (i <= d) dp[i][d] = 0;
            else {
                int best = INF;
                for (int l = 0; l < d; ++l) {
                    for (int k = 1; k+k <= i-l; ++k) {
                        best = min(best, 1 + dp[k][d-l] + dp[i-l-k][d-l]);
                    }
                }
                dp[i][d] = best;
            }
        }
    }
}

int solveB(vector<int>& P) {
    int best = INF, bestS = -1;
    for (int s = 1; s <= 1000; ++s) {
        int cur = 0;
        for (int i = 1; i <= 1000; ++i) {
            cur += P[i] * dp[i][s];
        }
        if (s + cur < best) bestS = s;
        best = min(best, s + cur);
    }
    cerr << "Best S: " << bestS << endl;
    return best;
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    init();
    for (int i = 1; i <= 10; ++i) {
        cerr << i << ": ";
        for (int j = 1; j <= 10; ++j)
            cerr << dp[i][j] << ' ';
        cerr << endl;
    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cerr << "[Case " << t << "] ";
        int n, a;
        vector<int> P(1001, 0);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            P[a]++;
        }
        cout << "Case #" << t << ": " << solveB(P) << endl;
    }

    return 0;
}
