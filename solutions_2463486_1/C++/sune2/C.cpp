#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cassert>
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
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef pair<int,int> pii;
typedef long long ll;

bool check(ll a) {
  stringstream ss; ss << a;
  string s = ss.str();
  string t = s;
  reverse(ALL(t));
  return s == t;
}
int main() {
  vector<ll> v;
  for (ll i=1; i*i<=100000000000100; ++i) {
    if (check(i) && check(i*i)) {
      v.push_back(i*i);
    }
  }
  // cout << v.size() << endl;
  // cout << v.back() << endl;
  int T;
  cin >> T;
  REP(cs,T) {
    ll a, b;
    cin >> a >> b;
    ll ans = upper_bound(ALL(v),b) - lower_bound(ALL(v),a);
    printf("Case #%d: %lld\n", cs+1, ans);
  }
}
