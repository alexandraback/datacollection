#include <cstdio>
#include <cstring>
#include <cstdint>

using namespace std;

int d[51][51];

int max2(uint64_t n) {
  uint64_t t = 1;
  int r = 0;
  while (t <= n) { t *= 2; r++; }
  return r-1;
}

void mark(int n, int off) {
  if (n<1) return;
  for (int i=1; i<n; ++i) d[off][off+i]=1;
  mark(n-1, off+1);
}

void line(int to) {
  for (int i=0; i<to; ++i) d[i][i+1]=1;
}

void print(int n) {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) printf("%d", d[i][j]);
    printf("\n");
  }
}

int main() {
  int n; scanf("%d\n", &n);
  for (int i=0; i<n; ++i) {
    int b; uint64_t m; scanf("%d%llu", &b, &m);
    if ((uint64_t(1) << (b-2)) < m) {
      printf("Case #%d: IMPOSSIBLE\n", i+1); continue;
    }
    printf("Case #%d: POSSIBLE\n", i+1);
    memset(d, 0, sizeof(d));
    int maxp2 = max2(m);
    mark(maxp2+2, b-maxp2-2);
    line(b-(maxp2+2));
    for (int i=0; i<maxp2; ++i)
      if ((uint64_t(1) << i) & m)
        d[0][b-1 - i-1]=1;
    print(b);
  }
}
