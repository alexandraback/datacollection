#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const ll INF = (ll)(2e9);
ll A, B, K;
long long rec(ll a, ll b, ll k, ll bit) {
  if (a < 0 || b < 0 || k < 0) {
    return 0;
  }
  long long to_ret = 0;
  ll bound = max(0ll, 2 * bit - 1);
  if (a >= bound) {
    a = INF;
  }
  if (b >= bound) {
    b = INF;
  }
  if (k >= bound) {
    return min(a + 1, bound + 1) * min(b + 1, bound + 1);
  }
  if (a == INF && b == INF) {
    return 3 * rec(a, b, k, bit / 2) + rec(a, b, k - bit, bit / 2);
  } else if (a == INF) {
    return 2 * rec(a, b, k, bit / 2) + rec(a, b - bit, k, bit / 2) + rec(a, b - bit, k - bit, bit / 2);
  } else if (b == INF) {
    return 2 * rec(a, b, k, bit / 2) + rec(a - bit, b, k, bit / 2) + rec(a - bit, b, k - bit, bit / 2);
  } else {
    return rec(a, b, k, bit / 2) + rec(a - bit, b, k, bit / 2) + rec(a, b - bit, k, bit / 2) +
        rec(a - bit, b - bit, k - bit, bit / 2);
  }
  
//   REP (a_bit, 1) {
//     if (a_bit && a == INF) {
//       continue;
//     }
//     REP (b_bit, 1) {
//       if (b_bit && b == INF) {
//         continue;
//       }
//       a_bit *= bit;
//       b_bit *= bit;
//       ll new_a, new_b;
//       if ((a & bit) && a_bit == 0) {
//         new_a = INF;
//       } else {
//         new_a = a - a_bit;
//       }
//       if ((b & bit) && b_bit == 0) {
//         new_b = INF;
//       } else {
//         new_b = b - b_bit;
//       }
//       ll aband = (a_bit & b_bit);
//       to_ret += rec(new_a, new_b, k - aband, bit / 2);
//     }
//   }
//   if (a == INF) {
//     to_ret += 
//   return to_ret;
}
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, tt);
  RE (ttt, tt) {
    cout<<"Case #"<<ttt<<": ";
    cin>>A>>B>>K;
    A--;
    B--;
    K--;
    long long BIT = 1ll << 30;
    //cerr<<BIT<<endl;
    cout<<rec(A, B, K, BIT)<<endl;
  }
   
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}
