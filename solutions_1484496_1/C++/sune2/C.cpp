#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

ll a[500];
map<ll,pii> mp;
ll n;
void func(ll now, ll sum1, ll sum2, ll S1, ll S2) {
  if (now == n/2) {
    mp[sum2-sum1] = pii(S1,S2);
    return;
  }
  func(now+1,sum1,sum2,S1,S2);
  func(now+1,sum1+a[now],sum2,S1|1<<now,S2);
  func(now+1,sum1,sum2+a[now],S1,S2|1<<now);
}
ll ans1, ans2;
void func2(ll now, ll sum1, ll sum2, ll S1, ll S2) {
  if (now == n) {
    if (mp.count(sum1-sum2)) {
      pii p = mp[sum1-sum2];
      if (p.first|S1 && p.second|S2) {
        ans1 = p.first|S1;
        ans2 = p.second|S2;
      }
    }
    return;
  }
  func2(now+1,sum1,sum2,S1,S2);
  func2(now+1,sum1+a[now],sum2,S1|1<<now,S2);
  func2(now+1,sum1,sum2+a[now],S1,S2|1<<now);
}


int main() {
  int T;cin>>T;
  REP(t,T) {
    cin >> n;
    REP(i,n) {
      cin >> a[i];
    }
    sort(a,a+n,greater<ll>());
    REP(i,26) {
      a[i] = a[i+46];
    }
    ans1=-1;
    n = min(n,26LL);
    mp.clear();
    func(0,0,0,0,0);
    func2(n/2,0,0,0,0);
    printf("Case #%d:\n", t+1);
    if (ans1 == -1) {
      cout << "Impossible" << endl;
    } else {
      bool f = 0;
      REP(i,n) {
        if (ans1>>i&1) {
          if (f) cout << " ";
          cout << a[i];
          f = 1;
        }
      }
      cout << endl;
      f = 0;
      REP(i,n) {
        if (ans2>>i&1) {
          if (f) cout << " ";
          cout << a[i];
          f = 1;
        }
      }
      cout << endl;
    }
  }
}
