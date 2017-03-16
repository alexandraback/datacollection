#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

long long dp[101][101];

long long boxes[101][2];
long long toys[101][2];

int main()
{
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n, m;
        memset(dp, 0, sizeof(dp));

        cin >> n >> m;

        for (int i = 0; i < n; i++)
            cin >> boxes[i][0] >> boxes[i][1];

        for (int i = 0; i < m; i++)
            cin >> toys[i][0] >> toys[i][1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                long long t = 0, b = 0, typ = boxes[i][1];

                for (int i1 = i; i1 < n; i1++) {
                    if (typ == boxes[i1][1]) b += boxes[i1][0];

                    for (int j1 = j; j1 < m; j1++) {
                        if (toys[j1][1] == typ) t += toys[j1][0];
                        dp[i1 + 1][j1 + 1] = max(dp[i1 + 1][j1 + 1], dp[i][j] + min(b, t));
                    }
                }
            }
        }

        long long res = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) res = max(res, dp[i][j]);

        cout << "Case #" << test << ": " << res << endl;
    }
}
