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

string solve (string S) {
  vi digits;

  map<char, int> cnt;
  for (auto x : S)
    cnt[x]++;

  // ZERO
  while (cnt['Z']) {
    digits.pb(0);
    cnt['Z']--, cnt['E']--, cnt['R']--, cnt['O']--;
  }

  // TWO
  while (cnt['W']) {
    digits.pb(2);
    cnt['T']--, cnt['W']--, cnt['O']--;
  }

  // SIX 
  while (cnt['X']) {
    digits.pb(6);
    cnt['S']--, cnt['I']--, cnt['X']--;
  }

  // SEVEN, no more S
  while (cnt['S']) {
    digits.pb(7);
    cnt['S']--, cnt['E']--, cnt['V']--, cnt['E']--, cnt['N']--;
  }  

  // FIVE, no more V
  while (cnt['V']) {
    digits.pb(5);
    cnt['F']--, cnt['I']--, cnt['V']--, cnt['E']--;
  }

  // FOUR, no more F
  while (cnt['F']) {
    digits.pb(4);
    cnt['F']--, cnt['O']--, cnt['U']--, cnt['R']--;
  }

  // ONE, no more O
  while (cnt['O']) {
    digits.pb(1);
    cnt['O']--, cnt['N']--, cnt['E']--;
  }  

  // THREE, no more R
  while (cnt['R']) {
    digits.pb(3);
    cnt['T']--, cnt['H']--, cnt['R']--, cnt['E']--, cnt['E']--;
  }

  // NINE, no more N
  while (cnt['N'] >= 2) {
    digits.pb(9);
    cnt['N']--, cnt['I']--, cnt['N']--, cnt['E']--;
  } 

  // EIGHT
  while (cnt['E']) {
    digits.pb(8);
    cnt['E']--, cnt['I']--, cnt['G']--, cnt['H']--, cnt['T']--;
  }  

  for (auto entry : cnt) {
    if (entry.se) {
      debug("remaining", entry.fi, "!");
    }
  }

  sort (all(digits));
  SS ss;
  re (i, size(digits))
    ss << digits[i];
  return ss.str();
}

int main() {
  int T;
  scanf("%d", &T);
  
  fo (test, 1, T) {
    string S;
    cin >> S;
    printf("Case #%d: %s\n", test, solve(S).c_str());
  }
  
  return 0;
}