#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define mem(a, val) memset((a), val, sizeof(a))
#define inf    1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi acos(-1.0)
#define sqr(a) ((a)*(a))
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef vector< pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

int t[110], dp[110][110];

int main() {
/*  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);/**/

  int T, N, S, p;
  scanf("%d\n", &T);
  rep(tt, T) {
    scanf("%d%d%d", &N, &S, &p);
    rep(i, N)
      scanf("%d", t + i + 1);
    if (p == 0) {
      printf("Case #%d: %d\n", tt + 1, N);
      continue;
    }

    mem(dp, 0);
    FOR(i, 1, N) {
      FOR(j, 0, S) {
        if (t[i] >= p + (p - 1) + (p - 1))
          dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        else
          dp[i][j] = dp[i - 1][j];

        if (t[i] < 2 || t[i] > 28 || j == 0) continue;
        if (t[i] >= p + (p - 2) + (p - 2))
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        else
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }

/*    FOR(i, 1, N) {
      FOR(j, 0, S)
        printf("%d ", dp[i][j]);
      printf("\n");
    }*/

    printf("Case #%d: %d\n", tt + 1, dp[N][S]);
  }

  return 0;
}
