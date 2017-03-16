#include <stdio.h>
#include <stdlib.h>

#define P printf
#define S scanf
#define F(i, n) for(I i = 0; i < (n); i++)
#define I int
#define LL long long

I main() {
  I T; S("%d", &T);
  F(t, T) {
    I r, c, w; S("%d %d %d", &r, &c, &w);
    I solution = w + r * (1 + (c - 1) / w) - 1;
    P("Case #%d: %d\n", t + 1, solution);
  }
}
