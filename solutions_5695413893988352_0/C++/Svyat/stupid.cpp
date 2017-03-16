#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int T;
string a, b;
int n;
int X[10];
int Y[10];

void load() {
  cin >> a >> b;
}

bool ok(int x, int y) {
  for (int i = 0; i < (int)a.size(); ++i) {
    X[i] = x % 10;
    x /= 10;
  }                        
  reverse(X, X + a.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    Y[i] = y % 10;
    y /= 10;
  }
  reverse(Y, Y + a.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] != '?' && a[i] != X[i] + '0') return false;
  }
  for (int i = 0; i < (int)a.size(); ++i) {
    if (b[i] != '?' && b[i] != Y[i] + '0') return false;
  }
  return true;
}

string conv(int x) {
  string res;
  for (int i = 0; i < (int)a.size(); ++i) {
    res += x % 10 + '0';
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}

void solve(int tc) {
  int best = 1e9;
  pii ans = mp(1e9, 1e9);
  if (a.size() == 1) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (ok(i, j)) {
          if (abs(i - j) < best || (abs(i - j) == best && mp(i, j) < ans)) {
            best = abs(i - j);
            ans = mp(i, j);
          }
        }
      }
    }
  } else if (a.size() == 2) {
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        if (ok(i, j)) {
          if (abs(i - j) < best || (abs(i - j) == best && mp(i, j) < ans)) {
            best = abs(i - j);
            ans = mp(i, j);
          }
        }
      }
    }
  } else {
  for (int i = 0; i < 1000; ++i) {
      for (int j = 0; j < 1000; ++j) {
        if (ok(i, j)) {
          if (abs(i - j) < best || (abs(i - j) == best && mp(i, j) < ans)) {
            best = abs(i - j);
            ans = mp(i, j);
          }
        }
      }
    }
  }
  cout << "Case #" << tc << ": " << conv(ans.first) << ' ' << conv(ans.second) << '\n';
}

void clear() {
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
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