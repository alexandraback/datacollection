#include <bits/stdc++.h>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())
#define X first
#define Y second

using namespace std;

typedef long long int int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

void clear() {
}

void read() {
}

void solve() {
  int n = getInt();
  map<int, int> cnt;
  fori(tt,0, n * (n * 2 - 1)) {
    int x = getInt();
    cnt[x]++;
  }
  vector<int> ans;
  for (auto p : cnt) {
    if (p.Y % 2 != 0) {
      ans.pb(p.X);
    }
  }
  sort(all(ans));
  for (auto x : ans) {
    printf("%d ", x);
  }
  printf("\n");
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);
    solve();
  }
  return 0;
}
