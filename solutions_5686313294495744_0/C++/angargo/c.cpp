#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;

int n;
set<string> f, s;
vector<string> vf, vs;

bool ok(int mask) {
  set<string> a, b;
  for (int i = 0; i < n; ++i) {
    if (mask & (1 << i)) {
      a.insert(vf[i]);
      b.insert(vs[i]);
    }
  }
  return f == a and s == b;
}

void solve(int cas) {
  cin >> n;
  f.clear();
  s.clear();
  vf.resize(n);
  vs.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> vf[i] >> vs[i];
    f.insert(vf[i]);
    s.insert(vs[i]);
  }
  int res = 0;
  for (int i = 0; i < (1 << n); ++i) {
    if (ok(i)) {
      res = max(res, n - __builtin_popcount(i));
    }
  }
  cout << "Case #" << cas << ": " << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve(i + 1);
}
