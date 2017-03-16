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

struct Q {
  bool neg;
  int c; //1ijk
  Q() :neg(false), c(0) {}
  Q(bool neg, int c) :neg(neg), c(c) {}
  bool operator == (const Q&o) const { return neg == o.neg && c == o.c; }
};

Q pmul[4][4] = {
  {
    Q(false,0),
    Q(false,1),
    Q(false,2),
    Q(false,3),
  },
  {
    Q(false,1),
    Q(true,0),
    Q(false,3),
    Q(true,2),
  },
  {
    Q(false,2),
    Q(true,3),
    Q(true,0),
    Q(false,1),
  },
  {
    Q(false,3),
    Q(false,2),
    Q(true,1),
    Q(true,0),
  },
};

Q mul(const Q&a, const Q&b) {
  Q r = pmul[a.c][b.c];
  r.neg ^= a.neg ^ b.neg;
  return r;
}

bool solve() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  bool foundi=false;
  bool foundk=false;
  if (x > 4) { x = 4 + x % 4; }
  string _ = s; s = "";
  forn(i, x) s = s + _;
  Q q;
  forn(i, s.length()) {
    q = mul(q, Q(false,string("1ijk").find_first_of(s[i])));
    if (!foundi && q == Q(false, 1))
      foundi = true;
    if (foundi && !foundk && q == Q(false,3))
      foundk = true;
  }
  return foundi && foundk && q == Q(true, 0);
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
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}

