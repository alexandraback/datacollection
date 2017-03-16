#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 30;

int d[1234];
int dp[1234][1234];

int solve(int n, int m) {
  if(n <= m) return 0;
  int &res = dp[n][m];
  if(res != -1) return res;
  res = inf;
  for(int i = 1; i + i <= n; ++i) {
    res = min(res, solve(i, m) + solve(n - i, m) + 1);
  }
  return res;
}

int main() {
  freopen("B.in", "rt", stdin);
  freopen("B.out", "wt", stdout);
  memset(dp, -1, sizeof dp);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int n; scanf("%d", &n);
    int max = 0;
    for(int i = 0; i < n; ++i) {
      scanf("%d", d + i);
      if(max < d[i]) {
        max = d[i];
      }
    }
    int ans = max;
    for(int j = 1; j <= max; ++j) {
      int cost = j;
      for(int i = 0; i < n; ++i) {
        cost += solve(d[i], j);
      }
      if(ans > cost) {
        ans = cost;
      }
    }
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}
