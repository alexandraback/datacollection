#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second

using namespace std;

template<typename T>
bool uin(T& a, T b) { if(b<a){a=b;return true;}return false; }
template<typename T>
bool uax(T& a, T b) { if(a<b){a=b;return true;}return false; }

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<string, string> ps;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<ps> vps;

void solve() {
  string a, b;
  cin >> a >> b;
  pair<int, pii> ans(1e9, pii(1e9, 0));
  function<void(int, int, int)> g = [&] (int y, int x, int i) {
    if (i == b.size()) {
      uin(ans, mp(abs(x - y), pii(y, x)));
    } else for (int j = 0; j < 10; ++j) {
      if (b[i] == '?' || b[i] == '0' + j) {
        g(y, x * 10 + j, i + 1);
      }
    }
  };
  function<void(int, int)> f = [&] (int x, int i) {
    if (i == a.size())
      g(x, 0, 0);
    else for (int j = 0; j < 10; ++j) {
      if (a[i] == '?' || a[i] == '0' + j) {
        f(x * 10 + j, i + 1);
      }
    }
  };
  f(0, 0);
  cout << setfill('0') << setw(a.size()) << ans.se.fi << ' ' << setw(b.size()) << ans.se.se << endl;
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
