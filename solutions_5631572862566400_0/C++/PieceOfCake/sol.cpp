#include "iostream"
#include "algorithm"

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
int a[20];
int b[20];
int n;
int ma;
int tt;

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++){
    scanf("%d", &n);
    ma = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = i;
    do{
      bool ok1 = 0, ok4 = 0, ok2 = 0, ok3 = 1;
      for (int l = 1; l <= n; l++){
        ok1 = ok2 = 0;
        ok3 = 1;
        if (a[b[l]] == b[l + 1]) ok1 = 1;
        for (int r = l + 1; r <= n; r++){
          ok2 = ok4 = 0;
          if (ok1 == 0){
            if (a[b[l]] == b[r]) ok4 = 1;
          }
          else ok4 = 1;
          if (a[b[r]] == b[r - 1] || a[b[r]] == a[b[l]]) ok2 = 1;
          if (a[b[r]] != b[r - 1] && a[b[r]] != b[r + 1]) ok3 = 0;
          if (ok4 && ok2 && ok3) umax(ma, r - l + 1);
        }
      }
    }while (next_permutation(b + 1, b + n + 1));
    cs(t);
    printf("%d\n", ma);
  }
  return !1;
}
