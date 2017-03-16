#include <bits/stdc++.h>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

typedef long long int int64;

void clear() {
}

void read() {
}

void solve() {
  int k = getInt(), c = getInt(), s = getInt();
  int ans = (k + c - 1) / c;
  if (ans > s) {
    printf("IMPOSSIBLE\n");
    return;
  }
  int ind = 0;
  fori(i,0,ans) {
    int64 cur = 0;
    fori(i,0,c) {
      cur = cur * k + ind;
      ind = min(ind+1, k-1);
    }
    printf("%I64d ", cur + 1);
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
