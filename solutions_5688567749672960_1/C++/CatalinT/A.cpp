/*
 Catalin-Stefan Tiseanu
 Pre-written code is assembled from various sources found online.
 Big thanks to the community for that !
 */
// Pre-written code below

using namespace std;

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

//START_CLEAN
// always remove

//START:mandatory
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
//template factorize
template<class T> inline vector<pair<T,int> > factorize(T n) {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));} i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
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

struct Scanner {
  char* curPos;
  
  const static int BUF_SIZE = (2000000);
  char input[BUF_SIZE];
  
  FILE * fin;
  
  void init(FILE * _fin) {
    fin = _fin;
    fread(input, 1, sizeof(input), fin);
    curPos = input;
  }
  
  Scanner() {;}
  
  inline void ensureCapacity() {
    int size = input + BUF_SIZE - curPos;
    if (size < 100) {
      memcpy(input, curPos, size);
      fread(input + size, 1, BUF_SIZE - size, fin);
      curPos = input;
    }
  }
  
  inline int nextInt() {
    ensureCapacity();
    while (!isdigit(*curPos) && *curPos != '-')
      ++curPos;
    int res = 0;
    int sign = 1;
    
    if (*curPos == '-')
      sign = -1,
      ++curPos;
    
    while (*curPos >= '0' && *curPos <= '9')
      res = res * 10 + (*(curPos++) & 15);
    return sign * res;
  }
} Sc;

int dp[(1<<24)];

inline int64 rev(int64 x) {
  int64 rev_x;
  SS ss; ss << x;
  auto repr = ss.str();
  reverse(all(repr));
  SS uu; uu << repr; uu >> rev_x;
  return rev_x;
}
/*
int doit(int x) {
  if (x == 1)
    return dp[1] = 1;

  int & res = dp[x];
  if (res != -1) return res;

  debug(x, rev_x);

  int sol_minus = doit(x - 1);
  int sol_rev = (rev_x != x) ? doit(rev_x) : (1<<30);

  return res = 1 + min(sol_minus, sol_rev);
}
*/

inline int digits(int64 N) {
  SS ss; ss << N; return ss.str().length();
}

int64 fast_solve(int64 N) {
  if (N <= 30)
    return dp[N];

  int nr_dig = digits(N);

  int64 p1 = 1;
  re (i, (nr_dig + 1) / 2)
    p1 *= 10;

  int64 base = N / p1 * p1;

  int64 big_base = 1;
  re (i, nr_dig - 1)
    big_base *= 10;

  //debug(N, base + 1, big_base);

  if (N >= big_base && big_base + p1 / 10 >= N) {
    return (int64) N - (big_base - p1 / 10 + 1) + fast_solve(big_base - p1 / 10 + 1);
  } else {
    if (N % base == 0) {
      if (N == big_base) return (N % p1) - 1 + fast_solve(base + 1);
      else return 1 + fast_solve(N - 1);
    }
    if (N == base + 1) {
      int64 my_rev = rev(N);
      if (my_rev < N) return 1 + fast_solve(rev(N));
      else return 1 + fast_solve(N - 1);
    } else {
      return (N % p1) - 1 + fast_solve(base + 1);
    }
  }

}

void bf() {
  int max_n = 1000;

  dp[1] = 1;

  vector<bool> used(max_n + 1, 0);

  queue<int> q;
  q.push(1);
  used[1] = 1;

  while(!q.empty()) {
    int el = q.front();
    q.pop();

    int rev_el = rev(el);
    int plus_el = el + 1;

    if (rev_el <= max_n && !used[rev_el]) {
      dp[rev_el] = dp[el] + 1;
      q.push(rev_el);
      used[rev_el] = 1; 
    }

    if (plus_el <= max_n && !used[plus_el]) {
      dp[plus_el] = dp[el] + 1;
      q.push(plus_el);
      used[plus_el] = 1; 
    }
  }
}

void test() {
  int max_n = 10000000;

  bf();

  int last_nr = 21, last_at = 13;

  if (fast_solve(max_n) != dp[max_n])
    debug("bad");

  //fout.close();
}

int solve(int N) {
  int ok = dp[N];

  //return fast_solve(N);
/*
  if (N <= 20) return N;

  int nr = 13;
  int at = 21;

  int range_nr = 10;

  while (N > at + range_nr - 1) {
    at += range_nr;
    nr++;
  }
*/
  return ok;
}

int main() {
  //test();
  bf();

  int T;
  scanf("%d", &T);
  
  //fill(dp, -1);
  int64 N;
  
  fo (test, 1, T) {
    cin >> N;
    printf("Case #%d: ", test);

    cout << fast_solve(N) << "\n";
  }
  
  return 0;
}