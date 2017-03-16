#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int cs;
char s[10005];
void solve() {
  int m, q = 0, ans = 0;
  scanf("%d%s", &m, s);
  for (int i = 0; i <= m; i++) {
    int p = s[i]-'0';
    q += p;
    --q;
    if (q < 0) {
      q = 0;
      ++ans;
    }
  }
  printf("Case #%d: %d\n", cs, ans);
}

int main(void) {
  int T;
  scanf("%d", &T);
  for (cs=1;cs<=T;cs++) solve();
  return 0;
}
