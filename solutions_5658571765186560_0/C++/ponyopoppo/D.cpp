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

int main() {
  int t;
  cin >> t;
  rep(_, t) {
    ll x, r, c;
    cin >> x >> r >> c;
    bool ans = true;
    bool ov = false;
    if(x >= 7) ans = false;
    if(max(r, c) < x) ans = false;
    if(x%2 == 1 && min(r, c) < (x+1)/2) ans = false;
    if(x%2 == 0) {
      if(r == x/2 && c == x/2) ans = false;
      if(min(r, c) < x/2) ans = false;
    }
    if((r*c)%x != 0) ans = false;
    
    int len = max(r, c);
    if(min(r, c) == 2 && x == 4) {
      bool ok = false;
      rep(i, len-2) {
	if((2*i + 1)%x == 0) ok = true;
      }
      if(!ok) ans = false;
    }
    if(min(r, c) == 3) {
      if(x == 5) {
	repi(k, 1, 3+1) {
	  bool ok = false;
	  rep(i, len-2) {
	    if((3*i + k)%x == 0) ok = true;
	  }
	  if(!ok) ans = false;
	}
      } else if(x == 6) {
	repi(k, 1, 5+1) {
	  bool ok = false;
	  rep(i, len-3) {
	    if((3*i + k)%x == 0) ok = true;
	  }
	  if(!ok) ans = false;
	}
      }      
    }
    
    if(x <= 2) ov = true;
    //cout << x << " " << r << " " << c << " ";
    cout << "Case #" << _+1 << ": ";
    if(ans) cout << "GABRIEL" << endl;
    else cout << "RICHARD" << endl;
  }
  return 0;
}
