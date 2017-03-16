#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int dp[1 << 16];
int fa[1 << 16], fb[1 << 16];

bool IS(int mask, int bit) {
  return (mask >> bit) & 1;
}

void solve2() {
  int n;
  cin >> n;
  map < string, int > ma, mb;
  vector < pair < int, int > > all;
  int ca = 0, cb = 0, add = 0;
  set < pair < int, int > > f;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (!ma.count(a)) ma[a] = ++ca;
    if (!mb.count(b)) mb[b] = ++cb;
    all.push_back(make_pair(ma[a], mb[b]));
  }
  memset(dp, 0, sizeof(dp));
  memset(fa, 0, sizeof(fa));
  memset(fb, 0, sizeof(fb));
  for (int mask = 0; mask < 1 << n; ++mask) {
    for (int bit = 0; bit < n; ++bit) {
      if (mask & (1 << bit)) {
        fa[mask] |= 1 << all[bit].first;
        fb[mask] |= 1 << all[bit].second;
      }
    }
  }
  for (int mask = 0; mask < 1 << n; ++mask) {
    for (int bit = 0; bit < n; ++bit) {
      if (~mask & (1 << bit)) {
        if (IS(fa[mask], all[bit].first) && IS(fb[mask], all[bit].second)) {
          dp[mask | (1 << bit)] = max(dp[mask | (1 << bit)], dp[mask] + 1);
        } else {
          dp[mask | (1 << bit)] = max(dp[mask | (1 << bit)], dp[mask]);
        }
      }
    }
  }
  if (dp[(1 << n) - 1] != n - max(ma.size(), mb.size())) {
    printf("\n");
    printf("%d %d\n", dp[(1 << n) - 1], n - max(ma.size(), mb.size()));
    printf("\n");
  }
}

string get(int n, int len) {
  string res;
  while (n > 0) {
    res += (char)(n % 10 + '0');
    n /= 10;
  }
  while (res.length() < len) {
    res += "0";
  }
  return res;
}

bool can(string &a, string &b) {
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] == '?' || a[i] == b[i]) {
      continue;
    }
    return false;
  }
  return true;
}

void solve() {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int bst = INF;
  pair < int, int > result = make_pair(INF, INF);
  int len = (int)a.length();
  string arr[1000];
  int to = (len == 1 ? 10 : len == 2 ? 100 : 1000);
  for (int i = 0; i < to; ++i) {
    arr[i] = get(i, len);
  }
  for (int i = 0; i < 1000; ++i) {
    string sa = arr[i];
    if (!can(a, sa)) continue;
    for (int j = 0; j < 1000; ++j) {
      if (bst < abs(i - j)) {
        continue;
      }
      string sb = arr[j];
      if (!can(b, sb)) continue;
      if (bst > abs(i - j) || bst == abs(i - j) && result > make_pair(i, j)) {
        bst = abs(i - j);
        result = make_pair(i, j);
      }
    }
  }
  reverse(arr[result.first].begin(), arr[result.first].end());
  if (result.second != result.first) {
    reverse(arr[result.second].begin(), arr[result.second].end());
  }
  cout << arr[result.first] << ' ' << arr[result.second] << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    printf("Case #%d: ", ti);
    solve();
  }
  return 0;
}
