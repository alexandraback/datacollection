#include "iostream"

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

int t;

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < sz(s); i++)
      if (s[i] != s[i - 1]) ans++;
    cs(tt);
    if (s[sz(s) - 1] == '-') printf("%d\n", ans + 1);
    else printf("%d\n", ans);
  }
  return !1;
}
