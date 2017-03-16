#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <float.h>
#include <ctime>
#include <list>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

bool isSurprising(int a, int b, int c) {
  return abs(a - b) == 2 || abs(a - c) == 2 || abs(b - c) == 2;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  cin >> t;

  FOR (tt, t) {
    int n, s, p;
    cin >> n >> s >> p;

    VI t(n);
    FOR (i, n) cin >> t[i];

    VVI dp(n + 1, VI(n + 1, -1));
    dp[0][0] = 0;

    FOR (i, n) FOR (j, n + 1) if (dp[i][j] != -1) {
      FOR (a, 11) FOR (b, 11) FOR (c, 11)
        if (a + b + c == t[i] && abs(a - b) <= 2 && abs(a - c) <= 2 && abs(b - c) <= 2) {
          int const points = max(a, max(b, c));

          if (isSurprising(a, b, c) && j < n) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (points >= p));
          } else {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (points >= p));
          }

        }
    }

    int res = max(0, dp[n][s]);
    printf("Case #%d: %d\n", tt + 1, res);
  }

  return 0;
}