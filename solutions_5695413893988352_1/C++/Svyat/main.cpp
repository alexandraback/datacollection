#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 4e18;

int T;
string a, b;
ll dp[20][2];
pii ans[20][2];
int par[20][2];
int n;
ll ten[20];
int len;

void load() {
  cin >> a >> b;
}

ll f(int pos, int c, int rev) {
  if (pos == n + 1) {
    if (c) return INF;
    return 0;
  }
  if (dp[pos][c] != -1) return dp[pos][c];
  if (a[pos] != '?' && b[pos] != '?') {
    int val1 = a[pos] - '0';
    int val2 = b[pos] - '0';
    val1 -= c;
    if (val1 < val2) {
      ans[pos][c] = mp(val1 + c, val2);
      par[pos][c] = 1;
      return dp[pos][c] = f(pos + 1, 1, rev) + ten[pos] * (10 + val1 - val2);
    }
    ans[pos][c] = mp(val1 + c, val2);
    par[pos][c] = 0;
    return dp[pos][c] = f(pos + 1, 0, rev) + ten[pos] * (val1 - val2);
  } else if (b[pos] != '?') {
    int val2 = b[pos] - '0';
    dp[pos][c] = INF;
    for (int i = 0; i < 10; ++i) {
      if (dp[pos][c] > f(pos + 1, i - c - val2 < 0, rev) + ten[pos] * ((10 + i - c - val2) % 10)) {
        dp[pos][c] = f(pos + 1, i - c - val2 < 0, rev) + ten[pos] * ((10 + i - c - val2) % 10);
        ans[pos][c] = mp(i, val2);
        par[pos][c] = i - c - val2 < 0;
      }
    }
  } else if (a[pos] != '?') {
    int val1 = a[pos] - '0';
    dp[pos][c] = INF;
    for (int i = 0; i < 10; ++i) {
      if (dp[pos][c] > f(pos + 1, val1 - c - i < 0, rev) + ten[pos] * ((10 + val1 - c - i) % 10)) {
        dp[pos][c] = f(pos + 1, val1 - c - i < 0, rev) + ten[pos] * ((10 + val1 - c - i) % 10);
        ans[pos][c] = mp(val1, i);
        par[pos][c] = val1 - c - i < 0;
      }
    }
  } else {
    dp[pos][c] = INF;
    ans[pos][c] = mp(1e9, 1e9);
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (dp[pos][c] > f(pos + 1, i - c - j < 0, rev) + ten[pos] * ((10 + i - c - j) % 10) ||
          (dp[pos][c] == f(pos + 1, i - c - j < 0, rev) + ten[pos] * ((10 + i - c - j) % 10) && (i - c - j < 0 || mp(i, j) < ans[pos][c]))) {
          dp[pos][c] = f(pos + 1, i - c - j < 0, rev) + ten[pos] * ((10 + i - c - j) % 10);
          ans[pos][c] = mp(i, j);
          par[pos][c] = i - c - j < 0;
        }
      }
    }
  }
  return dp[pos][c];
}

pair<string, string> rest() {
  pair<string, string> res;
  int c = 0;
  for (int i = 0; i < n; ++i) {
    res.first += '0' + ans[i][c].first;
    res.second += '0' + ans[i][c].second;
    c = par[i][c];
  }                                           
  reverse(res.first.begin(), res.first.end());
  reverse(res.second.begin(), res.second.end());
  return res;
}

void solve(int tc) {
  n = a.size();               
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  a += '1';
  b += '1';
  memset(dp, 0xff, sizeof dp);
  ll ans1 = f(0, 0, 0);
  swap(a, b);
  memset(dp, 0xff, sizeof dp);
  ll ans2 = f(0, 0, 1);
  pair<string, string> res;
  if (ans1 < ans2) {
    memset(dp, 0xff, sizeof dp);
    swap(a, b);
    f(0, 0, 0);
    res = rest();
  } else if (ans1 > ans2) {
    res = rest();
    swap(res.first, res.second);
  } else {
    pair<string, string> res2 = rest();
    swap(res2.first, res2.second);
    memset(dp, 0xff, sizeof dp);
    swap(a, b);
    f(0, 0, 0);
    res = rest();
    res = min(res, res2);
  }
  cout << "Case #" << tc << ": " << res.first << ' ' << res.second << '\n';
}

void clear() {
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ten[0] = 1;
  for (int i = 1; i < 20; ++i)
    ten[i] = ten[i - 1] * 10ll;
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    clog << "Testcase " << tc << endl;
    load();
    solve(tc);
    clear();
  }
  return 0;
}