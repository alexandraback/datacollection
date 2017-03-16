#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

map<vector<int>, int> memo;

int solve(vector<int> a) {
  if (a.size() == 0) return 0;
  sort(a.begin(), a.end(), greater<int>());
  if (a[0] <= 3) {
    return a[0];
  }
  if (memo.count(a)) return memo[a];
  int &ans = memo[a];

  int ans1 = 10000;
  int n = (int)a.size();
  a.push_back(0);
  int was[10] = {0};
  for (int i = 0; i < n; ++i) {
    int t = a[i];
    if (was[t]) continue;
    was[t] = true;
    while (true) {
      --a[i];
      ++a.back();
      if (a[i] < a.back()) break;
      ans1 = min(ans1, solve(a));
    }
    a[i] = t;
    a.back() = 0;
  }
  a.pop_back();

  for (int &v : a) --v;
  while (a.size() && a.back() == 0) {
    a.pop_back();
  }
  int ans2 = solve(a);
  return ans = min(ans1, ans2) + 1;
}

int solve1() {
  int D;
  cin >> D;
  vector<int> cnt(1010);
  int m = 0;
  for (int i = 0; i < D; ++i) {
    int t;
    cin >> t;
    ++cnt[t];
    m = max(m, t);
  }
  int ans = m;
  int ops = 0;
  while (m > 1) {
    ops += cnt[m];
    cnt[m / 2] += cnt[m];
    cnt[(m + 1) / 2] += cnt[m];
    cnt[m] = 0;
    while (!cnt[m]) --m;
    ans = min(ans, ops + m);
  }
  return ans;
}

int solve2() {
  int D;
  cin >> D;
  vector<int> a(D);
  for (int i = 0; i < D; ++i) cin >> a[i];
  memo.clear();
  return solve(a);
}

int main() {
#ifdef LOCAL_HOST
  freopen("B-small-attempt5.in", "r", stdin);
  //  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int n = 1; n <= N; ++n) {
    int ans = solve2();
    cout << "Case #" << n << ": " << ans << endl;
  }

  return 0;
}
