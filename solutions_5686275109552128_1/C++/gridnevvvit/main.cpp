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

const int N = 10000;
int d, p[N];

inline bool read() {
  if (!(cin >> d)) return false;

  forn(i, d) cin >> p[i];
  return true;
}

inline void solve() {
  int ans = INF;
  for(int eat = 1; eat <= 1000; eat++) {
    int tans = 0;
    forn(i, d) {
      tans += max(0, (p[i] - 1) / eat);
    }
    tans += eat;

    ans = min(ans, tans);
  }

  cout << ans << endl;
}

int main() 
{
#ifdef gridnevvvit
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int T;
  cin >> T;
  forn(test, T){
    assert(read());
    cout << "Case #" << test + 1 << ": ";
    solve();
  }

#ifdef gridnevvvit
  cerr << "TIME: " << clock() << "==== " << endl;
#endif
}
