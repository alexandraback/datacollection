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

const int N = 1000, B = 0x7fffffff;
bool vis[N];
int t, n, j;

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    scanf("%d%d", &n, &j);
    cs(tt);
    int hw = 0;
    int lef = 3, rig = 4;
    for (int i = 1; i <= j; i++){
      memset(vis, 0, sizeof vis);
      vis[1] = vis[hw + 2] = vis[31] = vis[32] = 1;
      vis[lef] = vis[rig] = 1;
      for (int q = 1; q <= 32; q++) cout << vis[q];
      cout << ' ';
      for (int q = 3; q <= 11; q++) cout << q << ' ';
      cout << '\n';
      rig += 2;
      if (rig > 30) lef += 2, rig = lef + 1;
      if (lef > 30) hw += 2, lef = hw + 3, rig = lef + 1;
    }
  }
  
  return !1;
}
