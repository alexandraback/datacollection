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
int a[1005], b[1005];
void solve() {
  int n, mxd=0;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    scanf("%d", &a[i]);
    mxd = max(mxd, a[i]);
  }
  int ans = mxd;
  for(int i=1;i<=mxd;i++) {
    int p=0;
    for(int j=0;j<n;j++)
      if(a[j]>i) {
        p += (a[j]-1) / i;
      }
    ans = min(ans, i + p);
  }
  printf("Case #%d: %d\n", cs, ans);
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
