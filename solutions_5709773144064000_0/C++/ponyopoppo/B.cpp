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
typedef long double ld;
template<class X>
ostream& operator<<(ostream& os, const vector<X> &v) {
  repit(itr, v) cout << *itr << " ";
  cout << " size : " << v.size();;
  return os;
}

ld C, F, X;
const ld INF = 1e10;

ld solve() {
  cin >> C >> F >> X;
  ld ans = INF;
  ld A = 2.0;
  ld tmp = 0;
  rep(k, 2000000) {
    if(k) tmp += C/(A+(k-1)*F);
    ans = min(ans, X/(A+k*F) + tmp);
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    ld ans = solve();
    printf("%.7Lf\n", ans);
  }
  return 0;
}
