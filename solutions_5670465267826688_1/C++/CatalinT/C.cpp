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

int mul[5][5] = {
   {0, 0, 0, 0, 0},
   {0, 1, 2, 3, 4},
   {0, 2, -1, 4, -3},
   {0, 3, -4, -1, 2},
   {0, 4, 3, -2, -1} 
};

inline char val(const char x) {
  if (x == 'i') return 2;
  if (x == 'j') return 3;
  if (x == 'k') return 4;
}

inline int mult(int a, int b) {
  return abs(a*b) / (a*b) * mul[abs(a)][abs(b)];
}

int find_min(const string & S, int64 X, int what) {
  int Y = 0;
  int e = 1;

  re (nr, X) {
    re (i, size(S)) {
      e = mult(e, val(S[i]));
      if (e == what)
        return nr * size(S) + i + 1;
    }

    ++Y;

    if (Y > 100) return -1;
  }

  return -1;
}

int find_min_rev(const string & S, int64 X, int what) {
  int Y = 0;
  int e = -1;

  re (nr, X) {
    re (i, size(S)) {
      e = (-1) * mult(e, val(S[i]));
      if (e == what)
        return nr * size(S) + i + 1;
    }

    ++Y;

    if (Y > 100) return -1;
  }

  return -1;
}

string solve(int64 X, const string & L) {
  string S = L;

  int L_e = 1;
  re (i, size(L))
    L_e = mult(L_e, val(L[i]));

  debug("L_e:", L_e);

  int Y = min(X % 4 + 4, X);

  int total_e = 1;
  re (i, Y)
    total_e = mult(total_e, L_e);

  debug("total_e:", total_e);

  if (total_e != -1)
    return "NO";

  int i_pos = find_min(S, X, 2);
  reverse(all(S));
  int k_pos = find_min_rev(S, X, 4);

  debug("i k:", i_pos, k_pos);

  if (i_pos == -1 || k_pos == -1 || i_pos + k_pos >= (int64)size(L) * X)
    return "NO";

  return "YES";
}

int main() {
  int T;
  scanf("%d", &T);
  
  fo (test, 1, T) {
    int64 X;
    int N;
    string L;

    cin >> N >> X;
    cin >> L;

    /*
    if (N * X <= 100000) {
      string tmp_L = "";
      re (i, X) tmp_L += L;
      L = tmp_L; 
      X = 1;
    }
    */
    
    printf("Case #%d: ", test);

    cout << solve(X, L) << "\n";
  }
  
  return 0;
}