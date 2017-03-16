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

#define MAX_D 3011

int N, X, Y, max_lev;

double dp[MAX_D][MAX_D];

double doit(int left, int right) {
  double & res = dp[left][right];
  
  if (res != -1)
    return res;

  if (left == 0 && right == 0)
    return res = 1.0;

  res = 0.0;
  int cnt = 0;

  if (left == 0) {
    res = 1.0;
    re (j, right)
      res /= 2;
    return res;
  } else if (right == 0) {
    res = 1.0;
    re (j, left)
      res /= 2;
    return res;
  }

  if (left) {
    if (right == max_lev)
      res += doit(left - 1, right);
    else
      res += doit(left - 1, right) / 2;
  }
  if (right) {
    if (left == max_lev)
      res += doit(left, right - 1);
    else
      res += doit(left, right - 1) / 2;
  }
  
  //res /= cnt;
  
  //debug("doit", left, right, res);
  
  return res;
}

double do_dp(int nr, int lev, int my_y) {
  re (i, lev + 1)
    re (j, lev + 1)
      dp[i][j] = -1.0;

  max_lev = lev;

  double res = 0.0;

  fo (i, my_y, max_lev) {
    int left = nr - i;
    
    if (left <= max_lev && left >= 0) {
      //debug("trying", left, i);
      res += doit(left, i);
    }
    else if (left >= max_lev) {
      return 1.0;
    }
  }
  
  return res;
}

double solve_testcase() {
  X = abs(X);
  
  int64 base = (X + Y) / 2 - 1;
  base = base * 2 + 1;
  
  int64 done = 0;
  fo (i, 1, base)
    done += i;
  
  if (done >= N)
    return 0.0;
  
  N -= done;

  int64 rem_on_level = base + 1 + base + 2;
  if (N >= rem_on_level)
    return 1.0;

  debug(N, rem_on_level);

  if (X == 0) {
    if (N == rem_on_level)
      return 1.0;
    else
      return 0.0;
  }

  int level = X + Y - 1;

  // should be less than 3000

  //debug("do_dp, ", N, level + 1, Y + 1);
  return do_dp(N, level + 1, Y + 1);
}

void do_dbg() {
  X = Y = 10000;
  
  int64 base = (X + Y) / 2 - 1;
}

int main() {
//  run_dbg();
//  return 0;
  
  int T; scanf("%d", &T);
  fo (testcase, 1, T) {
    debug("TEST = ", testcase);
    scanf("%d %d %d", &N, &X, &Y);
    printf("Case #%d: ", testcase);
    printf("%lf", solve_testcase());
    printf("\n");
  }
  return 0;
}
