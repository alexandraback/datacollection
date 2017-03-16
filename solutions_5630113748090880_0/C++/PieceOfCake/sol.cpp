#include "iostream"
#include "string.h"
#include "vector"

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define cs(x) printf("Case #%d: ", x)

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
template <class T> inline void umax(T &x,T y) {if (y > x) x = y;}
template <class T> inline void umin(T &x,T y) {if (y < x) x = y;}

const int N = 2600, B = 0x7fffffff;
int t, n;
int cnt[N];

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    vector <int> v;
    v.clear();
    memset(cnt, 0, sizeof cnt);
    scanf("%d", &n);
    for (int i = 1; i < 2 * n; i++){
      for (int j = 1, x; j <= n; j++){
        scanf("%d", &x);
        cnt[x]++;
      }
    }
    for (int i = 1; i <= N - 10; i++)
      if (cnt[i] != 0 && cnt[i] % 2 == 1) v.pb(i);
    cs(tt);
    for (int i = 0; i < sz(v); i++){
      if (i == sz(v) - 1) printf("%d\n", v[i]);
      else printf("%d ", v[i]);
    }
  }
  return !1;
}
