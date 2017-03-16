#include "algorithm"
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

const int N = 2e5 + 5, B = 0x7fffffff;
int t;
string a[] = {"EIGHT", "SIX", "ZERO", "SEVEN", "THREE", "FOUR", "FIVE", "NINE", "ONE", "TWO"};
int b[] = {8, 6, 0, 7, 3, 4, 5, 9, 1, 2};
int bet[20][1000];

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < sz(a[i]); j++) bet[i][a[i][j] - 'A' + 1]++;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++){
    string s;
    cin >> s;
    vector <int> ans;
    ans.clear();
    int cnt[1000];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < sz(s); i++) cnt[s[i] - 'A' + 1]++;
    cs(tt);
    for (int i = 0; i < 10; i++){
      int mi = B;
      bool ok = 1;
      for (int k = 0; k < sz(a[i]); k++){ 
        if (cnt[a[i][k] - 'A' + 1] < bet[i][a[i][k] - 'A' + 1]) ok = 0;
        else umin(mi, cnt[a[i][k] - 'A' + 1] / bet[i][a[i][k] - 'A' + 1]);
      }
      if (ok == 0) continue;
      for (int k = 0; k < sz(a[i]); k++) cnt[a[i][k] - 'A' + 1] -= mi;
      for (int k = 0; k < mi; k++) ans.pb(b[i]);
    }
    sort(all(ans));
    for (int x : ans) printf("%d", x);
    puts("");
  }
  return !1;
}
