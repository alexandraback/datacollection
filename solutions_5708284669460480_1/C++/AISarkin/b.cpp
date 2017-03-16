#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAX_N = 105;

int k, l, s;
bool pos[MAX_N][MAX_N][MAX_N];
long double dp[MAX_N][MAX_N][MAX_N];
string alpha, t;

int main() {
    int tests;

    cin >> tests;

    for (int test_id = 1; test_id <= tests; test_id++) {
        cin >> k >> l >> s;

        cin >> alpha >> t;

        int f[MAX_N] = {0};

        for (int i = 1; i < l; i++) {
            f[i] = f[i - 1];

            while (f[i] > 0 && t[i] != t[f[i]]) {
                f[i] = f[f[i] - 1];
            }

            if (t[i] == t[f[i]]) {
                f[i]++;
            }
        }

        for (int i = 0; i <= s; i++) {
            for (int j = 0; j <= l; j++) {
                for (int k = 0; k <= s; k++) {
                    pos[i][j][k] = false;
                    dp[i][j][k] = 0.0;
                }
            }
        }

        cout << "Case #" << test_id << ": ";

        bool stop = false;
        for (int i = 0; i < l; i++) {
            if (count(alpha.begin(), alpha.end(), t[i]) == 0) {
                cout << 0.0 << endl;

                stop = true;
                break;
            }
        }

        if (stop) {
            continue;
        }
                
        for (int i = 0; i < k; i++) {
            if (alpha[i] == t[0]) {
                dp[1][1][(l == 1)] += 1.0 / k; 
                pos[1][1][(l == 1)] = true;
            } else {
                dp[1][0][0] += 1.0 / k;
            }
        }

        for (int i = 2; i <= s; i++) {
            for (int ff = 0; ff <= l; ff++) {
                for (int kk = 0; kk < k; kk++) {
                    int tf = ff;

                    while (tf > 0 && alpha[kk] != t[tf]) {
                        tf = f[tf - 1];
                    }

                    if (alpha[kk] == t[tf]) {
                        tf++;
                    }

                    for (int q = 0; q <= s; q++) {
                        dp[i][tf][q + (tf == l)] += dp[i - 1][ff][q] * (1.0 / k);

                        if (pos[i - 1][ff][q]) {
                            pos[i][tf][q + (tf == l)] = true;
                        }
                    }
                }
            }
        }

        long double ans = 0.0;
        int mx = 0;

        for (int i = 0; i <= l; i++) {
            for (int j = 0; j <= s; j++) {
                ans += dp[s][i][j] * j;

                if (pos[s][i][j]) {
                    mx = max(mx, j);
                }
            }
        }

        cout << setprecision(9) << fixed << mx - ans << endl;
    }

    return 0;
}
