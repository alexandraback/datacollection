/*
 Catalin-Stefan Tiseanu
 Pre-written code is assembled from various sources found online.
 Big thanks to the community for that !
 */
// Pre-written code below

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <unordered_map>
#include <unordered_set>

using namespace std;

#define DEBUG

#ifndef NDEBUG
#   define assert_msg(condition, message) \
do { \
if (! (condition)) { \
std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
<< " line " << __LINE__ << ": " << message << std::endl; \
std::exit(EXIT_FAILURE); \
} \
} while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

template<class T> std::ostream&  operator <<(std::ostream& stream, const vector<T> & v) {
  for (auto el : v)
    stream << el << " ";
  return stream;
}

template<class T> std::ostream&  operator <<(std::ostream& stream, const vector<vector<T>> & v) {
  for (auto line : v) {
    for (auto el : line)
      stream << el << " ";
    stream << endl;
  }
  return stream;
}

template<class T, class U> std::ostream&  operator <<(std::ostream& stream, const pair<U, T> & p) {
  stream << "( " << p.first << ", " << p.second << " )";
  return stream;
}

class debugger {
public:
  template<class T> void output (const T& v) {
    cerr << v << " ";
  }
  
  template<class T> debugger& operator , (const T& v) {
    output(v);
    return *this;
  }
} dbg;
//END:mandatory

////////////////
// templates  //
////////////////

// general
//template size
template<typename T> int size(const T& c) { return int(c.size()); }
//template abs
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
//template sqr
template<typename T> T sqr(T x) { return x*x; }
//template remin
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
//template remax
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }
//template toStr
template<typename T> string toStr(T x) { stringstream ss; ss << x; return ss.str(); }

// other
string maskToStr(long long x, int len) {stringstream ss; for (int i = 0; i < len; ++i) if (x >> i & 1) ss << "1"; else ss << "0"; return ss.str();}

// misc
#define EPS             1e-5

// types
//template int64
typedef long long            int64 ;
//template uint64
typedef unsigned long long   uint64 ;

// shortcuts
#define all(_xx)             _xx.begin(), _xx.end()

#define pb                   push_back
#define vi                   vector<int>
#define vs                   vector<string>
#define vvi                  vector<vector<int>>
#define vd                   vector<double>
#define vpii                 vector<pair<int,int> >
#define vpdd                 vector<pair<double,double> >

#define pii                  pair<int,int>
#define pll                  pair<long long, long long>
#define pdd                  pair<double, double>
#define mp(XX, YY)           make_pair(XX, YY)
#define fi                   first
#define se                   second

#define ll                   long long
#define SS                   stringstream

// for loops
#define re(II, NN)           for (int II(0), _NN(NN); (II) < (NN); ++(II))
#define fod(II, XX, YY)      for (int II(XX), _YY(YY); (II) >= (_YY); --(II))
#define fo(II, XX, YY)       for (int II(XX), _YY(YY); (II) <= (_YY); ++(II))
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

// Useful hardware instructions
#define bitcount             __builtin_popcount
#define gcd                  __gcd

// Useful all around
#define checkbit(n,b)        ( (n >> b) & 1)
#define DREP(a)              sort(a.begin(), a.end());a.erase(unique(a.begin(), a.end()),a.end())
#define INDEX(arr,ind)       (lower_bound(arr.begin(), arr.end(),ind)-arr.begin())
#define PAUSE cerr << "Press any key to continue ..."; char xxxx; scanf("%c", &xxxx);
#define fill(xx,val) memset(xx, val, sizeof(xx))

#define MAX_N 1000
/*
int answer[MAX_N][MAX_N];

void build() {  
  re (i, MAX_N) re (j, MAX_N) {
    re (k, MAX_N) {
      if (abs())
    }
  }
}
*/

/*
int64 C_greater (string & C, string & S) {
  int comparison = 0;


  re (i, size(C)) {
    if (comparison) {
      if (comparison > 0) {
        if (C[i] == '?') C[i] = '0';
        if (S[i] == '?') S[i] = '9';
      } else {
        if (C[i] == '?') C[i] = '9';
        if (S[i] == '?') S[i] = '0';
      }
    }

    if (C[i] == '?' && S[i] == '?') {
      C[i] = S[i] = '0';
    } else if (C[i] == '?' && S[i] != '?') {
      C[i] = S[i];
    } else if (C[i] != '?' && S[i] == '?') {
      S[i] = C[i];
    } else if (C[i] != '?' && S[i] != '?') {
      if (C[i] != S[i] && !comparison) {
        comparison = (C[i] > S[i] ? 1 : -1);
      }
    }
  }

  //debug ("end loop");

  int64 C_nr, S_nr;
  SS ssC, ssS;
  ssC << C_nr;
  ssS << S_nr;

  ssC >> C_nr;
  ssS >> S_nr;

  return abs (C_nr - S_nr);
}
*/

int64 best_difference;
string best_C, best_S;

void check_result (const string& C, const string& S) {
  //debug ("checking", C, S);

  SS sC, sS;
  sC << C; sS << S;
  int64 nC, nS;
  sC >> nC; sS >> nS;

  int64 difference = abs (nC - nS);

  if (best_difference == -1 || difference < best_difference) {
    best_difference = difference;
    best_C = C;
    best_S = S;
  } else if (difference == best_difference && C < best_C) {
    best_difference = difference;
    best_C = C;
    best_S = S;
  } else if (difference == best_difference && C == best_C && S < best_S) {
    best_difference = difference;
    best_C = C;
    best_S = S;
  }
}

inline int new_comparison (char c, char s, int comparison) {
  if (comparison) return comparison;
  if (c == s) return 0;
  return (c > s ? 1 : -1);
}

void rec (int i, string C, string S, int comparison) {
  if (i == size(C)) {
    check_result(C, S);
    return;
  }

  //debug (i, C, S, comparison);


  if (comparison) {
    if (comparison > 0) {
      if (C[i] == '?') C[i] = '0';
      if (S[i] == '?') S[i] = '9';
      rec (i + 1, C, S, comparison);
    } else {
      if (C[i] == '?') C[i] = '9';
      if (S[i] == '?') S[i] = '0';
      rec (i + 1, C, S, comparison);
    }
    return;
  }

  if (C[i] != '?' && S[i] != '?') {
    rec (i + 1, C, S, new_comparison(C[i], S[i], comparison));
    return;
  } else if (C[i] == '?' && S[i] != '?') {
    fo (delta, -1, 1) {
      if (S[i] + delta >= '0' && S[i] + delta <= '9') {
        C[i] = S[i] + delta;
        rec (i + 1, C, S, new_comparison(C[i], S[i], comparison));        
      }
    }
  } else if (C[i] != '?' && S[i] == '?') {
    fo (delta, -1, 1) {
      if (C[i] + delta >= '0' && C[i] + delta <= '9') {
        S[i] = C[i] + delta;
        rec (i + 1, C, S, new_comparison(C[i], S[i], comparison));        
      }
    }
  } else if (C[i] == '?' && S[i] == '?') {
    C[i] = '0'; S[i] = '0';
    rec (i + 1, C, S, comparison);
    C[i] = '1'; S[i] = '0';
    rec (i + 1, C, S, new_comparison(C[i], S[i], comparison));
    C[i] = '0'; S[i] = '1';
    rec (i + 1, C, S, new_comparison(C[i], S[i], comparison));
  }
}

vs solve (string C, string S) {
  best_difference = -1;
  best_C = "", best_S = "";

  rec (0, C, S, 0);

  return vs {best_C, best_S};
}

int main() {
  int T;
  scanf("%d", &T);
  
  fo (test, 1, T) {
    string C, S;
    cin >> C >> S;
    
    auto result = solve(C, S);
    printf("Case #%d: %s %s\n", test, result[0].c_str(), result[1].c_str());
  }
  
  return 0;
}