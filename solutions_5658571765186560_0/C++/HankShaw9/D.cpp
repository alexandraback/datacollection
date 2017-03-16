#include <iostream>
#include <cstdio>
#include <vector>       // std::vector
#include <algorithm>    // std::max

using namespace std;

bool IsBlock(int x, int r, int c) {
  // Assumes r <= c
  if ((r * c) % x != 0) {
    // fprintf(stderr, "Not rounded: %d %d %d\n", x, r, c);
    return true;
  }
  if (x >= 7 || x > c) 
    return true;
  if ((x + 1) / 2 > r) {
    // fprintf(stderr, "L block: %d %d %d\n", x, r, c);
    return true;
  }
  if (x <= r)
    return false;
  // Invariant: x <= min(6, r * 2 - 1) && r <= x + 1
  if (x <= 3)
    return false;
  else if (x == 4) {
    // fprintf(stderr, "Undecidable: x = 4, %d %d\n", r, c);
    return (r == 2);
  } else if (x == 5) {
    if (r == 3) {
      // fprintf(stderr, "Undecidable: x = 5, r = 3, %d\n", c);
      return (c <= 5);
    } else {
      // fprintf(stderr, "Undecidable: x = 5, r = 4, %d\n", c);
      return (c <= 5);
    }
  } else if (x == 6) {
    if (r == 3) {
      // fprintf(stderr, "Undecidable: x = 6, r = 3, %d\n", c);
      return true;
    } else if (r == 4) {
      // fprintf(stderr, "Undecidable: x = 6, r = 4, %d\n", c);
      return false;
    } else {
      // fprintf(stderr, "Undecidable: x = 6, r = 5, %d\n", c);
      return false;
    }
    // fprintf(stderr, "Undecidable: x = 6, %d %d\n", r, c);
  }
  return false;
}

int main(int argc, char* argv[]) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int x, r, c;
    scanf("%d %d %d\n", &x, &r, &c);
    // for (int ix = 1; ix <= x; ++ix)
    //   for (int ir = 1; ir <= r; ++ir)
    //     for (int ic = ir; ic <= c; ++ic) {
    //       printf("Case %2d %2d %2d: %s\n", ix, ir, ic,
    //         IsBlock(ix, ir, ic) ? "RICHARD" : "GABRIEL");
    //     }
    printf("Case #%d: %s\n", i + 1, 
      IsBlock(x, std::min(r, c), std::max(r, c)) ? "RICHARD" : "GABRIEL");
  }
}
