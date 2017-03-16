#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fi first
#define se second

using namespace std;

template<typename T>
bool uax(T& a, T b) { if(a<b){a=b;return a;}return b; }

typedef vector<int> vi;
typedef pair<string, string> ps;
typedef vector<ps> vps;

void solve() {
  int n;
  cin >> n;
  vps a(n);
  forn(i, n) cin >> a[i].fi >> a[i].se;
  int ans = 0;
  forn(m, 1<<n) {
    set<string> l, r;
    forn(i, n) if ((m>>i)&1) {
      l.insert(a[i].fi);
      r.insert(a[i].se);
    }
    bool ok = true;
    forn(i, n) if (!((m>>i)&1)) {
      if (!l.count(a[i].fi) || !r.count(a[i].se)) {
        ok = false;
        break;
      }
    }
    if (ok) uax(ans, n - __builtin_popcount(m));
  }
  cout << ans << '\n';
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
