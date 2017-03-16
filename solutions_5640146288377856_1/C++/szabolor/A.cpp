#include <bits/stdc++.h>
using namespace std;

// loop, iteration defines
#define SZ(a)           int((a).size())
#define ALL(c)          (c).begin(),(c).end()
#define PRESENT(c,x)    ((c).find(x) != (c).end()) 
#define CPRESENT(c,x)   (find(ALL(c),x) != (c).end()) 
#define FOR(i,a,b)      for(int i = (a); i < (b); ++i)
#define REP(i,a)        FOR(i, 0, (a) - 1)
#define FORD(i,n,a)     for(int (i) = (n); (i) >= a; (i)--)
#define FOREACH(it,c)   for(typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FILL(a, v)      memset(a, v, sizeof(a));
#define DREP(a)         sort(ALL(a)); a.erase(unique(ALL(a)), a.end()) // will make the vector unique and sorted order

// Short-hand defines
#define fi    first
#define se    second
#define pb    push_back
#define mp    make_pair
#define endl  '\n'

// Types
typedef long long           ll;
typedef long double         ld;
typedef vector <int>        vi;
typedef vector <ll>         vll;
typedef vector <double>     vd;
typedef vector <string>     vs;
typedef vector <vi>         vvi;
typedef pair <int, int>     pii;
typedef pair <ll, ll>       pll;
typedef vector <pii >       vpii;
 
// Constants
#define PI 3.1415926535897932384626


// Debugger
#define DEBUG(args...) \
  {                    \
    dbg, args;         \
    cerr << endl;      \
  }
struct debugger {
  template <typename T>
  debugger& operator, (const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;

// speed up cin (but you couldn't use scanf...)
struct _ {
  ios_base::Init i;
  _() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  }
} _;

// cout to handle pair, vector, set and map
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  bool first = true;
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) {
  bool first = true;
  os << "[";
  for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) {
  bool first = true;
  os << "[";
  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii ;
    first = false;
  }
  return os << "]";
}

int compute(int R, int C, int W) {

  return (C / W) * (R-1) + (C-1) / W + W;
}
 
int main() {
  int Tmax, T = 0;

  cin >> Tmax;
  while (T < Tmax) {
    int R, C, W;
    cin >> R >> C >> W;

    cout << "Case #" << ++T << ": " << compute(R, C, W) << endl;
    cout << flush;
  }

  return 0;
}