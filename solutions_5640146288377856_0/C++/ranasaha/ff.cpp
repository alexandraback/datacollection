#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#else
#include "header.h"
#include "debug.h"
#endif
#define sz(s) int((s).size())
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair <int,int> pii;
typedef long long LL;
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 20;

int main () {
  #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
  #endif
  cin.sync_with_stdio (0); cin.tie (0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; ++tc) {
    cout << "Case #" << tc << ": ";
    int r, c, w;
    cin >> r >> c >> w;
    if (c == w) {
      cout << c << '\n';
    } else {
      cout << (ceil((c*1.0)/w) -1 + w) << '\n';
    }
  }
}
