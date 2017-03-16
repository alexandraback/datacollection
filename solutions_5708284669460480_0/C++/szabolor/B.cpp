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

#define INIT_H (1000000)
char h[INIT_H][8] = {0};

void gen_words(int S, int K, char key[8], int max) {
  for (int i=0; i < INIT_H; ++i) {
    h[i][0] = 0;
    h[i][1] = 0;
    h[i][2] = 0;
    h[i][3] = 0;
    h[i][4] = 0;
    h[i][5] = 0;
    h[i][6] = 0;
  }

  for (int i=0; i < max; ++i) {
    int divisor = 1;
    for (int j=0; j < S; ++j) {
      h[i][j] = key[(i/divisor) % K];
      divisor *= K;
    }
    // cout << h[i] << endl;
  }
}

int main() {
  int Tmax, T = 0;

  cin >> Tmax;
  while (T < Tmax) {
    int K, L, S;
    char key[8] = {0}, word[8] = {0};
    cin >> K >> L >> S;
    cin >> key;
    cin >> word;
    
    int MAX_H = 1;
    for (int i=0; i < S; ++i) {
      MAX_H *= K;
    }

    gen_words(S, K, key, MAX_H);

    int max = 0;
    int sum = 0;

    for (int i=0; i < MAX_H; ++i) {
      int curr = 0;
      char *found = strstr(h[i], word);

      while(found) {
        //cout << h[i] << " - " << word << "=" << found << endl;
        curr += 1;
        found = strstr(found+1, word);
      }

      if (curr > max) {
        max = curr;
      }

      sum += curr;
    }
/*
    cout << " - " << sum << endl;
    cout << " - " << max << endl;
    cout << " - " << MAX_H << endl;
*/
    cout.precision(10);
    cout << "Case #" << ++T << ": " << max - ((double) sum) / ((double) MAX_H) << endl << flush;
  }

  return 0;
}