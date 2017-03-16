#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve() {
  int k, c, s;
  scanf("%d%d%d", &k, &c, &s);
  if (c * s < k)
    puts("IMPOSSIBLE");
  else {
    int d = 0;
    //printf("k = %d, c = %d => %d\n", k, c, (k + c - 1) / k);
    forn(i, (k + c - 1) / c) {
      long long x = 0;
      forn(j, c) {
        //printf("[%d + digit %d = ", x, d);
        x = x * k + (d < k ? d++ : 0);
        //printf("%d]", x);
      }
      printf("%lld ", x + 1);
    }
    puts("");
  }
/*
  if (c >= 2) {
    
  }
*/
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
