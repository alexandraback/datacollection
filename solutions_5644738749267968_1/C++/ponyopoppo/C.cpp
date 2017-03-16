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

int a1, a2;

void solve() {
  int n;
  cin >> n;
  deque<double> a(n), b(n), ta, tb;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  
  sort(all(a));
  sort(all(b));
  vector<pair<double, int> > v;
  repit(itr, a) v.pb(mp(*itr, 0));
  repit(itr, b) v.pb(mp(*itr, 1));

  a1 = 0;
  while(a.size()) {
    if(a.back() > b.back()) {
      a.pop_back();
      b.pop_back();
      a1++;
    } else {
      a.pop_front();
      b.pop_back();
    }
  }

  sort(all(v));
  int tmp = 0;
  a2 = n;
  rep(i, v.size()) {
    if(v[i].second == 0) {
      tmp++;
    } else {
      if(tmp > 0) {
	tmp--;
	a2--;
      }
    }
  }

}

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
    cout << a1 << " " << a2 << endl; 
  }
  
  return 0;
}
