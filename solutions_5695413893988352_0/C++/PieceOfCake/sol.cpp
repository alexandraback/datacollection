#include "iostream"
#include "vector"
#include "cmath"

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

int calc(string s){
  int pq = 1, re = 0;
  for (int i = sz(s) - 1; i >= 0; i--) re += (pq * (s[i] - '0')), pq *= 10;
  return re;
}

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    string c, j2;
    cin >> c >> j2;
    vector <int> inc;
    vector <int> inj;
    inc.clear(), inj.clear();
    string ans1 = "", ans2 = "";
    int ans = B, cc = 0, jj = 0;
    for (int i = 0; i < sz(c); i++) if (c[i] == '?') inc.pb(i);
    for (int i = 0; i < sz(j2); i++) if (j2[i] == '?') inj.pb(i);
    inc.pb(10);
    inc.pb(10);
    inc.pb(10);
    inj.pb(10);
    inj.pb(10);
    inj.pb(10);
    for (int i = 0; i <= 9; i++){
      for (int j = 0; j <= 9; j++){
        for (int k = 0; k <= 9; k++){
          c[inc[0]] = i + '0';
          c[inc[1]] = j + '0';
          c[inc[2]] = k + '0';
          for (int i1 = 0; i1 <= 9; i1++){
            for (int j1 = 0; j1 <= 9; j1++){
              for (int k1 = 0; k1 <= 9; k1++){
                j2[inj[0]] = i1 + '0';
                j2[inj[1]] = j1 + '0';
                j2[inj[2]] = k1 + '0';
                if (abs(calc(c) - calc(j2)) < ans) ans = abs(calc(c) - calc(j2)), cc = calc(c), jj = calc(j2), ans1 = c, ans2 = j2;
                if (abs(calc(c) - calc(j2)) == ans){
                  if (calc(c) < cc) ans = abs(calc(c) - calc(j2)), cc = calc(c), jj = calc(j2), ans1 = c, ans2 = j2;
                  if (calc(c) == cc){
                    if (calc(j2) < jj) ans = abs(calc(c) - calc(j2)), cc = calc(c), jj = calc(j2), ans1 = c, ans2 = j2;
                  }
                }
              }
            }
          }
        }
      }
    }
    cs(tt);
    cout << ans1 << ' ' << ans2 << '\n';
  }
  return !1;
}
