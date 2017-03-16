#include <bits/stdc++.h>

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;      

#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ft first
#define sc second
#define sz(a) int((a).size())

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline int hasbit(T mask, int b) { return (mask >> b) & 1; }

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i < int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

const int INF = int(1e9);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);

li l, x;
string s;

inline bool read() {
  return (cin >> l >> x >> s);
}

inline int toid(char ch) {
  if (ch == 'i') return 1;
  if (ch == 'j') return 2;
  if (ch == 'k') return 3;
  throw;
}

inline void solve() {
  int tr[8][8] = {
    {0,1,2,3,0,0,0,0},
    {1,4,3,6,0,0,0,0},
    {2,7,4,1,0,0,0,0},
    {3,2,5,4,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
  };

  for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++){
    tr[i][j] = tr[i % 4][j % 4] + (i / 4) * 4 + (j / 4) * 4;
    tr[i][j] %= 8;
  }
  string ns = "";
  forn(i, min(5ll, x)) {
    ns += s;
  }
  li idxi = -1;
  int curid = 0;
  forn(i, sz(ns)) {
    curid = tr[curid][toid(ns[i])];
    if (curid == 1) {
      idxi = i;
      break;
    }
  }
  li idxk = -1;
  curid = 0;
  forn(i, sz(ns)) {
    int idx = sz(ns) - i - 1;
    curid = tr[toid(ns[idx])][curid];

    if (curid == 3) {
      idxk = l * x - i - 1;     
      break;
    }
  }

  if (idxi != -1 && idxk != -1) {
    if (idxi < idxk) {
      curid = 0;
      ns = "";
      forn(i, x % 4) {
        ns += s;
      }

      forn(i, sz(ns))
        curid = tr[curid][toid(ns[i])];

      if (curid == 4) {
        puts("YES");
      } else {
        puts("NO");
      }
    } else{
      puts("NO");
    }
  } else {
    puts("NO");
  }
}

int main() 
{
#ifdef gridnevvvit
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int T;
  cin >> T;
  forn(test, T) {
    cout << "Case #" << test + 1<< ": ";
    assert(read());
    solve();
  }
#ifdef gridnevvvit
  cerr << "TIME: " << clock() << "==== " << endl;
#endif
}
