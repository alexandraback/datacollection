#include "iostream"
#include "string.h"
#include "cmath"

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define cs(x) printf("Case #%d:\n", x)

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
template <class T> inline void umax(T &x,T y) {if (y > x) x = y;}
template <class T> inline void umin(T &x,T y) {if (y < x) x = y;}

const int N = 11, B = 0x7fffffff;
ll de[N], now[N], ans[N];
int t, n, j;

ll checkprime(ll x){
  for (int i = 2; i <= sqrt(x); i++) 
    if (x % i == 0) return i;
  return -1;
}

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    scanf("%d%d", &n, &j);
    cs(tt);
    for (int i = 0; i < (1 << n); i++){
      if (!(i & (1 << (n - 1))) || !(i & (1 << 0))) continue;
      for (int nk = 1; nk <= 11; nk++) de[nk] = 1;
      memset(now, 0, sizeof now);
      memset(ans, 0, sizeof ans);
      for (int k = n - 1; k >= 0; k--){
        for (ll ba = 2; ba <= 10; ba++){
          ll nn = de[ba];
          now[ba] += ll(nn * bool(i & (1 << k)));
          de[ba] = ll(nn * ba);
        }
      }
      int pq = 0;
      for (int k = 2; k <= 10; k++){
        ll ss = checkprime(now[k]);
        if (ss != -1){
          pq++;
          ans[k] = ss;
        }
      }
      if (j <= 0) return 0;
      if (pq == 9 && j > 0){
        for (int k = 0; k < n; k++) cout << bool(i & (1 << k));
        cout << ' ';
        for (int k = 2; k <= 10; k++){
          if (k != 10) cout << ans[k] << ' ';
          else cout << ans[k] << '\n';
        }
        j--;
      }
    }
  }
  
  return !1;
}
