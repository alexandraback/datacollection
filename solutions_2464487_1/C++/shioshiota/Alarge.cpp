#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;
typedef long double ld;
using namespace std;


ll BIG = 1000000000000000000LL;


inline ld calcOdd(ld now){
  return now* ( 2*now+1);
}

inline ld calcEven(ld now){
  return now* ( 2*now+3);
}

ld calc(ll base, ld now){
  if(base % 2 == 1){
    base /= 2;
    return (calcOdd(now) - calcOdd(base));
  }
  base--;
  base /= 2;
  return calcEven(now) - calcEven(base);
}

ll ok(ll base, ld now, ll t){
  ld res = calc(base, now);
  if(res > t + 10)return false;
  else return ((ll)res) <= t;
}

int main(){

  int T;
  cin >> T;
  rep(tc, T){
    cout <<"Case #" << tc+1 <<": " << flush;
    ll base, t;
    cin>>base>>t;
    ll left;
    if(base %2)left = base  / 2;
    else {
      left = (base-1)/2;
    }
    ll l = left, r = (1LL<<62);

    while(l+1 < r){
      ll mid = (l+r)/2;
      if(ok(base, mid, t))l = mid;
      else r = mid;
    }
    cout << l - left << endl;
  }
  return 0;
}
