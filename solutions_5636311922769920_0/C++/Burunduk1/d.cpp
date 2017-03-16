#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve() {
  int k, c, s;
  scanf("%d%d%d", &k, &c, &s);
  assert(k == s);
  forn(i, k)
    printf("%d ", i + 1);
  puts("");
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
