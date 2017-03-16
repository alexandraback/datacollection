#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
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
#define dbg(v) do {cerr << #v << "->" << v << '\n';}while(0)
#else
#define dbg(v) do {;}while(0)
#endif

const int inf = 1e9 + 100500;
const int MAXN = 100500;

bool DBG = false;

bool solve(int x, int r, int c) {
  DBG = false;
  if (r > c) swap(r, c);
  if (r * c < x) return true;
  if (r * c % x != 0) return true;
  if (r * c == x) return true;
  if (x > c) return true;
  if (x >= r * 2 + 1) return true;
  if (x >= 7) return true;
  if (x == 1) return false;
  if (r == 1) return true;
  if (x == 2) return false;

  //DBG = true;

  if (r == 2) return x >= 4;
  /*
  $$$ $$$
  ##$ $$$
  $## $#$
  $$# ###
  $$$ #$#
  */
  if (r == 3) {
    if (x <= 4) return false;
    if (x == 5) return c < 10;
    // x == 6
    return true;
  }
  /*
  $$$$
  $$$$
  $$$#
  $$##
  ###$ alway can be rotated
  */
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  freopen("input.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  fore(t, 1, T) {
    cout << "Case #" << t << ": ";
    int x, r, c;
    cin >> x >> r >> c;
    bool res = solve(x, r, c);
    cout << (res ? "RICHARD" : "GABRIEL") << '\n';
    if (DBG) { dbg(x << " " << r << " " << c << " " << "=" << res); }
  }
  return 0;
}

