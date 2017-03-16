#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<ld> vld;

template<class T> T sqr(const T& a) { return a * a; }
template<class T> bool uax(T&a, const T& b) { if( a < b ) { a = b; return true; } return false; }
template<class T> bool uin(T&a, const T& b) { if( a > b ) { a = b; return true; } return false; }

#ifdef HOME
#define dbg(v) do {cerr << v << '\n';}while(0)
#else
#define dbg(v) do {;}while(0)
#endif

const i64 inf = 1e18 + 100500;
const int L = 360;

struct cmp {
  bool operator()(const pii& a, const pii&b) {
    return b.se * 1ll * (L - a.fi) < a.se * 1ll * (L - b.fi);
  }
};

void solve() {
  int n;
  cin >> n;
  vpi a;
  forn(i, n) {
    int d, h, m;
    cin >> d >> h >> m;
    forn(j, h) a.pb(mp(d, m + j));
  }
  sort(all(a), cmp());
  i64 ans = 1;
  if (a.size() == 1)
    ans = 0;
  else //a.size() == 2
  {
    forn(i, a.size() + 1) {
      i64 cans = a.size() - i;
      // my x(t) = min(d[j] + t * 360 / v[j]) (j < i)
      // n <= 2
      if (i == 1) {
        // can first join second BEFORE or INTIME second reach end
        // (max(a[1].fi,a[2].fi) < x <= L : (x-a[1].fi)/a[1].se == (L+x-a[0].fi)/a[0].se )
        // x * (a[0].se - a[1].se) = a[1].fi * a[0].s + (L-a[0].fi)*a[1].se

        //if (a[0].se > a[1].se) dbg( L * 1ll * (a[0].se - a[1].se) << ' ' <<  a[1].fi * 1ll * a[0].se + (L-a[0].fi) * 1ll * a[1].se );

        if (a[0].se > a[1].se && L * 1ll * (a[0].se - a[1].se) > a[1].fi * 1ll * a[0].se + (L-a[0].fi) * 1ll * a[1].se ) {
          cans = 1;
        } else cans = 0;
      } else if( i >= 2) {
        cans += inf;
      }
      uin(ans, cans);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  //freopen("input.txt", "r", stdin);
  freopen("C-small-1-attempt1.in", "r", stdin);
  freopen("C-s1.out", "w", stdout);
#endif
  int T;
  cin >> T;
  fore(t, 1, T) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}

