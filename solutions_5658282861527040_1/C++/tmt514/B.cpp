#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())
typedef long long LL;

int cs;
void solve() {
  int a, b, k, ans=0;
  scanf("%d%d%d", &a, &b, &k);
  for(int i=0;i<a;i++) for(int j=0;j<b;j++) ans += ((i&j)<k);
  printf("Case #%d: %d\n", cs, ans);
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
