#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define reprit(i, v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define to_str(v) #v
using namespace std;
typedef long long ll;

template<class X>
ostream& operator<<(ostream& os, const vector<X> &v) {
  repit(itr, v) cout << *itr << " ";
  cout << " size : " << v.size();;
  return os;
}

ll A, B, K;
ll dp[40][8];

void input() {
  cin >> A >> B >> K;
  //  A--; B--; K--;
}

ll solve2() {
  ll ans = 0;
  rep(i, A) rep(j, B) {
    if((i&j) < K) ans++;
  }
  return ans;
}


ll solve() {
  if(A <= K || B <= K) return A*B;
  int lpos = 0;
  memset(dp, 0, sizeof(dp));
  rep(i, 40) {
    if((A>>i)&1) lpos = max(lpos, i);
    if((B>>i)&1) lpos = max(lpos, i);
    if((K>>i)&1) lpos = max(lpos, i);
  }
  int n = lpos+2;
  vector<int> a(n), b(n), v(n);
  rep(i, n) {
    a[i] = (A>>(n-i-1))&1;
    b[i] = (B>>(n-i-1))&1;
    v[i] = (K>>(n-i-1))&1;
  }
  
  dp[0][7] = 1;
  rep(i, n) {
    rep(ori, 8) rep(val, 4) {
      //      int cond = (v[i]<<2) + (b[i]<<1) + a[i];
      int nk = (val>>1) & val & 1;
      int to = 0;
      if((ori>>2)&1) {
	if(nk > v[i]) continue;
	if(nk == v[i]) to |= 1<<2;
      }
      if((ori>>1)&1) {
	if(((val>>1)&1) > b[i]) continue;
	if(((val>>1)&1) == b[i]) to |= 1<<1;
      }
      if((ori>>0)&1) {
	if(((val>>0)&1) > a[i]) continue;
	if(((val>>0)&1) == a[i]) to |= 1<<0;
      }
      bool ok = true;
      rep(i, 3) if((!((ori>>i)&1)) && ((to>>i)&1)) ok = false;
      if(!ok) continue;
      dp[i+1][to] += dp[i][ori];
    }
  }
  ll ans = 0;

  return dp[n][0];
}

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    input();
    cout << "Case #" << i+1 << ": ";
    cout << solve();
    cout << endl;
    //    break;
  }
  return 0;
}
