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

using namespace std;

int main(){
  int T;
  cin >> T;
  rep(tc, T){
    cout <<"Case #" << tc+1 <<": " << flush;
    ll r, t;
    cin>>r>>t;
    ll cnt = 0;
    ll ans = 0;
    ll pre;
    while(t >= 0){
      ll now = r*r;
      if(cnt % 2 == 1){
	if(t < now - pre)break;
	t -= (now - pre);
	ans++;
      }
      r++;
      cnt++;
      pre = now;
    }
    cout << ans << endl;
  }
  return 0;
}
