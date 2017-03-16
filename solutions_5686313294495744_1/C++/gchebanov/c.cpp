#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define fi first
#define se second

using namespace std;

template<typename T>
bool uax(T& a, T b) { if(a<b){a=b;return a;}return b; }

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<string, string> ps;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<ps> vps;

void solve() {
  int q;
  cin >> q;
  vvi a;
  map<string, int> r[2];
  forn(i, q) {
    string e[2];
    int E[2];
    cin >> e[0] >> e[1];
    forn(j, 2) {
      auto it = r[j].find(e[j]);
      if (it == r[j].end())
        it = r[j].insert(psi(e[j], r[j].size())).first;
      E[j] = it->second;
      if (E[0] >= a.size()) a.eb();
      else a[E[0]].eb(E[1]);
    }
  }
  int n = r[0].size(), m = r[1].size();
  vb used(n, false);
  vi rr(m, -1);
  function<bool(int)> dfs = [&] (int i) {
    if (used[i]) return false;
    used[i] = true;
    for (int j: a[i]) if (rr[j] == -1 || dfs(rr[j])) {
      rr[j] = i;
      return true;
    } return false;
  };
  int match = 0;
  forn(i, n) if (!used[i]) {
    if (dfs(i)) {
      fill(all(used), false);
      match += 1;
    }
  }
  int ans = q - (n + m - match);
  cout << ans << '\n';
  // cout << q << ' ' << n << ' ' << m << ' ' << match  << '\n';
}

int main() {
  int T;
  cin >> T;
  forn(t, T) {
    cout << "Case #" << t + 1 << ": ";
    solve();
  }
  return 0;
}
