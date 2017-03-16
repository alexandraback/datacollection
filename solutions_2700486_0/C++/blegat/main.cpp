#include <stdio.h>
#include <math.h>
#include <assert.h>

#define MAXX 100
#define MAXY 100

int N, X, Y, F = 50;
int m[MAXX];
double p;

double rec (int length, int s, int curl, int curr, int left) {
  //fprintf(stderr, "%d %d %d %d %d\n", length, s, curl, curr, left);
  if (curr == s) {
    return 1;
  }
  if (curl == length || curr == length || left == 0) {
    return 0;
  } else {
    return 0.5 * rec(length, s, curl, curr+1, left-1) + 0.5 * rec(length, s, curl+1, curr, left-1);
  }
}

int main (void) {
  int T;
  int scanned = scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    scanf("%d%d%d", &N, &X, &Y);
    if (X < 0) {
      X = -X;
    }
    int n = 0;
    for (n = 0; (2 * (n+1) - 1) * (n+1) <= N; n++);
    //int n = ((int) floor((1+sqrt(1+8*N))/4)); // current
    int b = (2*n-1)*n;
    //fprintf(stderr, "b:%d\n", b);
    int left = N - b;
    int r = (X + Y)/2; // where it should be
    //fprintf(stderr, "n:%d r:%d\n", n, r);
    if (r < n) {
      p = 1;
    } else if (r > n) {
      p = 0;
    } else {
      int length = 2 * n;
      int s = 2*n - X + 1;
      //fprintf(stderr, "l:%d left:%d s:%d\n", length, left, s);
      if (left - length >= s) {
        p = 1;
      } else {
        p = rec(length, s, 0, 0, left);
      }
    }
    printf("Case #%d: %.8f\n", currentcase, p);
  }
  return 0;
}
