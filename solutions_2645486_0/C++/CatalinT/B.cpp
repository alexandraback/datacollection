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

int _N, _E, _R;
int v[11111];
ll N, E, R;

ll dp[11111], full_dp[11111];

void solve_testcase() {
  scanf("%d %d %d", &_E, &_R, &_N);
  E = _E, R = _R, N = _N;
  
  fo (i, 1, N)
    scanf("%d", v + i);
  


  memset(dp, 0, sizeof(dp));
  memset(full_dp, 0, sizeof(full_dp));
  
  ll best = 0, energy;

  dp[1] = E * v[1];
  full_dp[1] = 0;

  fo (i, 2, N) {
    fo (j, 1, i - 1) {
      energy = min(R * (i - j), E);
      remax(dp[i], dp[j] + energy * v[i]);
      
      remax(full_dp[i], full_dp[j]);
      if (R * (i - j) >= E)
        remax(full_dp[i], dp[j]);
      
      if (R * (i - j) < E) {
        remax(dp[i], full_dp[j] + (R * (i-j) * v[j]) + E * v[i]);
      }
    }
  }

  fo(i, 1, N)
    remax(best, dp[i]);

  cout << best;
}

int main() {
  int T; scanf("%d", &T);
  fo (testcase, 1, T) {
    printf("Case #%d: ", testcase);
    solve_testcase();
    printf("\n");
  }
  return 0;
}
