#include "iostream"
#include "map"

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
map <string, int> m1;
map <string, int> m2;
map <string, int> m3;
map <string, int> m4;
string s1[N], s2[N];

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    int n;
    scanf("%d", &n);
    m1.clear(), m2.clear();
    int ans;
    for (int i = 1; i <= n; i++){
      cin >> s1[i] >> s2[i];
      m1[s1[i]]++;
      m2[s2[i]]++;
    }
    for (int i = 1; i <= n; i++){
      if (m1[s1[i]] == 1) m3[s1[i]] = 1;
      if (m2[s1[i]] == 1) m4[s1[i]] = 1;
    }
    int ppq = 0;
    for (int i = 1; i <= n; i++){
      if (m1[s1[i]] > 1 && m2[s2[i]] > 1){
        ans++;
        if (m3[s1[i]] != 1) ppq++;
        if (m4[s2[i]] != 1) ppq++;
      }
    }
    cs(tt);
    printf("%d\n", ans - ppq);
  }
  return !1;
}
