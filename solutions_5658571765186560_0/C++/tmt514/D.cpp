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

int cs=0;
void solve() {
  int X, R, C;
  scanf("%d%d%d", &X, &R, &C);
  printf("Case #%d: ", cs);
  if (X >= 7 || R*C%X != 0) { 
    puts("RICHARD");
    return;
  }
  if (R > C) swap(R, C);
  if (X <= 2) {
      puts("GABRIEL");
      return;
  }
  if (X == 3) {
    if (R > 1) {
      puts("GABRIEL");
      return;
    }
    if (R == 1) {
      puts("RICHARD");
      return;
    }
  }
  if (X == 4) {
    if (R <= 2) {
      puts("RICHARD");
      return;
    }
    if (R > 2) {
      puts("GABRIEL");
      return;
    }
  }
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
