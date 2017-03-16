#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

vector<ll> v;
ll e, r;
int n;

ll solve() {
  ll cur = e;
  ll ans = 0;
  for ( int i=0;i<n;++i) {
    int better = -1;
    for (int j=i+1; j <n;++j) {
      if (v[j] > v[i]) {
        better = j;
        break;
      }
    }

    if (better == -1) {
      ans += cur * v[i];
      cur = r;
      continue;
    }

    ll gg = cur + ((ll)better-(ll)i)*r;
    if (gg <= e) {
      cur += r;
      continue;
    }

    ll tmp = min(gg - e, cur);
    ans += tmp * v[i];
    cur = cur - tmp + r;
  }

  return ans;
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    cin >> e >> r >> n;
    v.clear();
    v.resize(n);
    for (int i = 0; i< n; ++i){
      int tt;
      scanf("%d", &tt);
      v[i] = (ll)tt;
    }

    cout<<"Case #"<<it<<": " << solve()<<endl;
  }
  return 0;
}
