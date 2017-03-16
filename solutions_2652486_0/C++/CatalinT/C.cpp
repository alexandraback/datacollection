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

#define DEBUG

#ifdef DEBUG
#define debug(args...)            {dbg,args; cerr<<endl;}
#else
#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
  template<typename T> debugger& operator , (const T& v)
  {
  cerr<<v<<" ";
  return *this;
  }
} dbg;

// templates
template<typename T> int size(const T& c) { return int(c.size()); }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }

// misc
#define EPSILON              1e-7

// types
typedef long long            int64;
typedef unsigned long long   uint64;

// shortcuts
#define all(_xx)             _xx.begin(), _xx.end()

#define pb                   push_back
#define vi                   vector<int>
#define vpii                 vector<pair<int,int> >
#define vpdd                 vector<paid<double,double> >

#define pii                  pair<int,int>
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
#define DREP(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)       (lower_bound(all(arr),ind)-arr.begin())

// Code written during the competition below

int sums[50], R, N, K, M;

int test(vi &v1, vi &v2) {
  int match = 0;
  char viz[11];
  memset(viz, 0, sizeof(viz));
  re (i, size(v2)) {
    re (j, size(v1)) {
      if (!viz[j] && v2[i] == v1[j]) {
        match++;
        //viz[j] = 1;
        break;
      }
    }
  }
  
  return match;
}

string solve_small_1() {
  int counts = 0;
  vector<string> sols;
  
  vector<int> given;
  fo (i, 1, K)
    given.pb(sums[i]);
  sort(all(given));
  
  fo (a, 2, M) fo (b, 2, M) fo (c, 2, M) {
    vector<int> brute;
    
    fo (mask, 0, 7) {
      int prod = 1;
      
      if (checkbit(mask, 0)) prod *= a;
      if (checkbit(mask, 1)) prod *= b;
      if (checkbit(mask, 2)) prod *= c;
    
      brute.pb(prod);
      
      //debug(">>", a, b, c, prod);
    }
    
    sort(all(brute));
    int pos = test(brute, given);
    
    if (pos >= K) {
/*
      if (pos == K) {
        //debug("winning");
        SS ss;
        ss << a << b << c;
        return ss.str();
      }
*/
      re (o, 1) {
        counts++;
        SS ss;
        ss << a << b << c;
        sols.pb(ss.str());
      }
      
      //debug("possible sol", a, b, c);
    }
  }
  
  //debug(":( size = ", size(sols));
  
  if (size(sols)) {
    return sols[rand() % counts];
  }
  return "111";
}

void solve_testcase() {
  scanf("%d %d %d %d", &R, &N, &M, &K);
  
  vi a1; a1.pb(1), a1.pb(2);
  vi a2; a2.pb(1), a2.pb(2);
  
  //debug(a1 == a2);
  
  fo (r, 1, R) {
    re (i, K)
      scanf("%d", &sums[i+1]);
  
    if (N == 3) {
      printf("%s\n", solve_small_1().c_str());
    }
  }
  
}

int main() {
  int T; scanf("%d", &T);
  fo (testcase, 1, T) {
    printf("Case #%d:\n", testcase);
    solve_testcase();
    //printf("\n");
  }
  return 0;
}
