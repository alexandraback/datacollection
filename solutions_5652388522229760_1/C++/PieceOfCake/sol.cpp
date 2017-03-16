#include "iostream"
#include "string.h"

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

const int N = 2e5 + 5, B = 0x7fffffff;
int cnt[20];
int n, t;
int now, hm;

void seedigit(int x){
  int pq = x;
  while (pq){
    cnt[pq % 10]++;
    now += cnt[pq % 10] == 1;
    pq /= 10;
  }
}

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    memset(cnt, 0, sizeof cnt);
    hm = now = 0;
    bool ok = 0;
    scanf("%d", &n);
    cs(tt);
    if (n == 0){puts("INSOMNIA"); continue;}
    for (ll i = n; ; i += n){
      seedigit(i);
      if (now == 10){
        printf("%lld\n", i);
        ok = 1;
        break;
      }
    }
    if (!ok) puts("INSOMNIA");
  }
  return !1;
}
