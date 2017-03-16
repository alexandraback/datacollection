#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1111;

int a[MAXN];
int dp[MAXN][MAXN];

vector<int> vv;

int brute(vector<int> v, int cnt) {
  int last = v[v.size() - 1];
  int res = last + cnt;
  if (last == 1) return res;
  for (int i = 1; i <= last / 2; ++i) {
    vector<int> vv = v;
    vv.push_back(0);
    vv[vv.size() - 2] = i;
    vv[vv.size() - 1] = last - i;
    sort(vv.begin(), vv.end());
    res = min(res, brute(vv, cnt + 1));
  }
  vector<int> vv = v;
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i] > 0) vv[i]--;
  }
  res = min(res, brute(vv, cnt + 1));
  return res;
}

void init() {
  memset(dp, 0x3F, sizeof(dp));
  for (int mid = 1; mid < MAXN; ++mid) {
    for (int i = 0; i <= mid; ++i) {
      dp[mid][i] = 0;
    }
    for (int i = mid + 1; i < MAXN; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        dp[mid][i] = min(dp[mid][i], dp[mid][j] + dp[mid][i - j] + 1);
      }
    }
  }
}

int main() {
  init();
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int n;
    cin >> n;
    vv.clear();
    int lim = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      lim = max(lim, a[i]);
    }
    sort(a, a + n);
    int ans = INT_MAX;
    for (int mid = 1; mid <= lim; ++mid) {
      int tmp = 0;
      for (int i = 0; i < n; ++i) {
        tmp += dp[mid][a[i]];
      }
      ans = min(ans, tmp + mid);
    }
    printf("Case #%d: %d\n", T, ans);
  }
}