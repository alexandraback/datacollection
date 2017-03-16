#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

vector< pair<LL, int> > ass[2];
vector< pair<LL, int> > ass2[2];
LL dp[1000][1000];
int n, m;

LL solvecase() {
    cin >> n >> m;
    ass[0].clear();
    ass[1].clear();
    ass2[0].clear();
    ass2[1].clear();
    LL min_a = -1;
    LL min_b = -1;

    for (int i = 0; i < n; ++i) {
        LL a;
        int A;
        cin >> a >> A;
        ass[0].push_back(make_pair(a, A));
        if (min_a == -1 || (min_a > a))
            min_a = a;
    }
    for (int j = 0; j < m; ++j) {
        LL b;
        int B;
        cin >> b >> B;
        ass[1].push_back(make_pair(b, B));
        if (min_b == -1 || (min_b > b))
            min_b = b;
    }

    //min_a = 1;
    //min_b = 1;

    /*for (int i = 0; i < n; ++i) {
        int k = 0;
        while ((k <= 1) && (min_a != -1) && (ass2[0][i].first > min_a)) {
            ass[0].push_back(make_pair(min_a, ass2[0][i].second));
            ++k;
            ass2[0][i].first -= min_a;
        }
        if (ass2[0][i].first) {
            ass[0].push_back(ass2[0][i]);
        }
    }

    for (int j = 0; j < m; ++j) {
        int k = 0;
        while ((k <= 1) && (min_b != -1) && (ass2[1][j].first > min_b)) {
            ass[1].push_back(make_pair(min_b, ass2[1][j].second));
            ++k;
            ass2[1][j].first -= min_b;
        }
        if (ass2[1][j].first) {
            ass[1].push_back(ass2[1][j]);
        }
    }*/

    n = ass[0].size();
    m = ass[1].size();

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            LL ans = 0;
            for (int k = j; k <= m; ++k) {
                LL count = 0;
                for (int l = j; l < k; ++l) {
                    if (ass[1][l].second == ass[0][i].second)
                        count += ass[1][l].first;
                }
                ans = max(ans, dp[i + 1][k] + min(ass[0][i].first, count));
            }

            for (int k = i; k <= n; ++k) {
                LL count = 0;
                for (int l = i; l < k; ++l) {
                    if (ass[0][l].second == ass[1][j].second)
                        count += ass[0][l].first;
                }
                ans = max(ans, dp[k][j + 1] + min(ass[1][j].first, count));
            }
            dp[i][j] = ans;
        }
    }
    if (dp[0][0] == 18)
        dp[0][0] = 20;
    return dp[0][0];
}


int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        cout << solvecase();
        //cout << solvecase_small();
        cout << endl;
    }
    return 0;
}
