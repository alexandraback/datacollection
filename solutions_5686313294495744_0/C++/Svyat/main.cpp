#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int T;
int n;
string a[16], b[16];
int x[20];
int y[20];

void load() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
}

int getbit(int mask, int bit) {
  return mask >> bit & 1;
}

bool can(int mask) {
  x[0] = 0;
  y[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (getbit(mask, i)) x[++*x] = i;
    else y[++*y] = i;
  }
  for (int i = 1; i <= x[0]; ++i) {
    bool wasa = false, wasb = false;
    for (int j = 1; j <= y[0]; ++j) {
      if (a[x[i]] == a[y[j]]) wasa = true;
      if (b[x[i]] == b[y[j]]) wasb = true;
    }
    if (wasa == false || wasb == false) return false;
  }
  return true;
}

void solve(int tc) {
  int res = 0;
  for (int i = 0; i < 1 << n; ++i) {
    if (can(i)) {
      res = max(res, __builtin_popcount(i));
    }
  }
  cout << "Case #" << tc << ": " << res << '\n';
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