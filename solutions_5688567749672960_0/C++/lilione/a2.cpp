#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

const int MAXN = 10000001;

int f[MAXN];

int GetR(int x) {
  if (x % 10 == 0) return x;
  int ret = 0;
  for ( ; x; x /= 10) {
    ret = ret * 10 + x % 10;
  }
  return ret;
}

void Prepare() {
  memset(f, 63, sizeof(f));
  f[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    f[i] = f[i - 1] + 1;
    f[i] = std::min(f[i], f[GetR(i)] + 1);
  }
}

int main() {
	freopen("a.out", "w", stdout);
  Prepare();
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    int t;
    assert(scanf("%d", &t) == 1);
    printf("Case #%d: %d\n", i, f[t]);
  }
  return 0;
}

