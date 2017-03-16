#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fi first
#define se second

using namespace std;

template<typename T>
bool uin(T& a, T b) { if(b<a){a=b;return true;}return false; }
template<typename T>
bool uax(T& a, T b) { if(a<b){a=b;return true;}return false; }

typedef long long i64;
typedef vector<i64> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<string, string> pss;
typedef pair<i64, i64> pii;
typedef pair<string, i64> psi;
typedef pair<i64, pss> pipss;
typedef vector<pipss> vpipss;
typedef vector<pss> vpss;

vpipss d[20];
string a, b;
i64 p10[20];

vpipss f(int i) {
  if (i < 0) return vpipss(1, pipss(0, pss("", "")));
  if (!d[i].empty()) return d[i];
  vpipss res;
  auto nf = f(i - 1);
  for (int p = 0; p < 10; ++p) if (a[i] == '?' || a[i] == p + '0') {
    for (int q = 0; q < 10; ++q) if (b[i] == '?' || b[i] == q + '0') {
      for (auto e: nf) {
        string pa = string(1, '0' + p) + e.second.first;
        string qb = string(1, '0' + q) + e.second.second;
        i64 pq = stoll(pa) - stoll(qb);
        res.eb(pq, pss(pa, qb));
      }
    }
  }
  sort(all(res));
  int j = 0;
  if (j < res.size()) d[i].pb(res[j]);
  j = (int)res.size() - 1;
  if (j >= 0) d[i].pb(res[j]);
  j = 0; while (j < res.size() && res[j].fi < 0) ++j;
  if (j >= 0 && j < res.size()) d[i].pb(res[j]);
  --j;
  while (j >= 0 && res[j-1].fi == res[j].fi) --j;
  if (j >= 0 && j < res.size()) d[i].pb(res[j]);
  d[i].erase(unique(all(d[i])), d[i].end());
  // cerr << i << ':'; for(auto e: d[i]) {
  //   cerr << e.fi << ' ' << e.se.fi << ':' << e.se.se << '|';
  // } cerr << '\n';
  return d[i];
}

void solve() {
  cin >> a >> b;
  reverse(all(a));
  reverse(all(b));
  pair<i64, pss> ans(3e18, pss("", ""));
  int n = a.size();
  forn(i, n) d[i].clear();
  auto r = f(n-1);
  for (auto e: r) {
    uin(ans, pipss(abs(e.fi), e.se));
  }
  cout << setfill('0') << setw(a.size()) << ans.se.fi << ' ' << setw(b.size()) << ans.se.se << endl;
}

int main() {
  p10[0] = 1;
  forn(i, 20) if(i) {
    p10[i] = 10 * p10[i-1];
  }
  int T;
  cin >> T;
  forn(t, T) {
    cout << "Case #" << t + 1 << ": ";
    solve();
  }
  return 0;
}
