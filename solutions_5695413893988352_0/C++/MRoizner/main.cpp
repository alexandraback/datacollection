#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))

#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cerr << "> " << #x << ": " << (x) << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;

string output(int64 c, int64 j, int n) {
    vector<int> cc, jj;
    for (int i = 0; i < n; ++i) {
        cc.push_back(c % 10);
        c /= 10;
        jj.push_back(j % 10);
        j /= 10;
    }
    string res;
    for (int i = n - 1; i >= 0; --i) {
        res.push_back(cc[i] + '0');
    }
    res.push_back(' ');
    for (int i = n - 1; i >= 0; --i) {
        res.push_back(jj[i] + '0');
    }
    return res;
}

string foo(string c, string j) {
    int n = c.length();
    // debug(n);
    vector< vector< pair<int64, int64> > > dp(n + 1, vector< pair<int64, int64> >(3));
    vector<int64> tens(19);
    tens[1] = 1;
    for (int i = 2; i < 19; ++i) {
        tens[i] = tens[i - 1] * 10;
    }
    for (int i = 1; i < n + 1; ++i) {
        // debug(i);
        // 1
        {
            int d1 = c[n - i] == '?' ? 9 : c[n - i] - '0';
            int d2 = j[n - i] == '?' ? 0 : j[n - i] - '0';
            dp[i][1] = make_pair(d1 * tens[i] + dp[i - 1][1].first, d2 * tens[i] + dp[i - 1][1].second);
        }
        // 2
        {
            int d1 = c[n - i] == '?' ? 0 : c[n - i] - '0';
            int d2 = j[n - i] == '?' ? 9 : j[n - i] - '0';
            dp[i][2] = make_pair(d1 * tens[i] + dp[i - 1][2].first, d2 * tens[i] + dp[i - 1][2].second);            
        }
        // 0
        {
            if (c[n - i] != '?' && j[n - i] != '?') {
                int d1 = c[n - i] - '0';
                int d2 = j[n - i] - '0';
                int p = d1 < d2 ? 1 : d1 > d2 ? 2 : 0;
                dp[i][0] = make_pair(d1 * tens[i] + dp[i - 1][p].first, d2 * tens[i] + dp[i - 1][p].second);
            } else if (c[n - i] != '?') {
                int d1 = c[n - i] - '0';
                int64 best = -1;
                for (int d2 = d1 - 1; d2 <= d1 + 1; ++d2) {
                    if (d2 < 0) continue;
                    if (d2 > 9) continue;
                    int p = d1 < d2 ? 1 : d1 > d2 ? 2 : 0;
                    int64 r = abs(d1 * tens[i] + dp[i - 1][p].first - (d2 * tens[i] + dp[i - 1][p].second));
                    if (best == -1 || r < best) {
                        best = r;
                        dp[i][0] = make_pair(d1 * tens[i] + dp[i - 1][p].first, d2 * tens[i] + dp[i - 1][p].second);
                    }
                }
                assert(best != -1);
            } else if (j[n - i] != '?') {
                int d2 = j[n - i] - '0';
                int64 best = -1;
                for (int d1 = d2 - 1; d1 <= d2 + 1; ++d1) {
                    if (d1 < 0) continue;
                    if (d1 > 9) continue;
                    int p = d1 < d2 ? 1 : d1 > d2 ? 2 : 0;
                    int64 r = abs(d1 * tens[i] + dp[i - 1][p].first - (d2 * tens[i] + dp[i - 1][p].second));
                    if (best == -1 || r < best) {
                        best = r;
                        dp[i][0] = make_pair(d1 * tens[i] + dp[i - 1][p].first, d2 * tens[i] + dp[i - 1][p].second);
                    }
                }
                assert(best != -1);
            } else {
                int64 best = -1;
                for (int d1 = 0; d1 <= 1; ++d1) {
                    for (int d2 = 0; d2 <= 1; ++d2) {
                        int p = d1 < d2 ? 1 : d1 > d2 ? 2 : 0;
                        int64 r = abs(d1 * tens[i] + dp[i - 1][p].first - (d2 * tens[i] + dp[i - 1][p].second));
                        if (best == -1 || r < best) {
                            best = r;
                            dp[i][0] = make_pair(d1 * tens[i] + dp[i - 1][p].first, d2 * tens[i] + dp[i - 1][p].second);
                        }
                    }
                }
                assert(best != -1);
            }
        }
    }

    return output(dp[n][0].first, dp[n][0].second, n);
}

int main() {
     // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;

    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        string c, j;
        cin >> c >> j;
        auto res = foo(c, j);
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
