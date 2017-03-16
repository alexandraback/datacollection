#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

#define EPS 1.0e-10
#define ZEROP(x) (abs(x)<EPS)
#define EQ(x,y) ZEROP((x)-(y))
#define LT(x,y) ((x)+EPS<(y))
#define LE(x,y) ((x)-(y)<+EPS)
#define PI 3.141592653589793238462643383279502884197

ll solve(ll r, ll t){
  ll now = 0;
  
  ll ret = 0;
  while(true){
    now += (2LL*r+1LL);
    if(t<now) break;
    ret++;
    r+=2LL;
  }
  return ret;
}

int main(){
  int T;
  cin >> T;

  rep(t,T){
    ll r, tm;
    cin >> r >> tm;
    cout << "Case #" << t+1 << ": " << solve(r, tm) << endl;
  }
  
  return 0;
}
