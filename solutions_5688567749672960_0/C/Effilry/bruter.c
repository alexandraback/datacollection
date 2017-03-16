#include <limits.h>
#include <stdio.h>
#include <string.h>

long reverse(long n) {
  long r = 0;
  while (n > 0) {
    r = r * 10 + n % 10;
    n /= 10;
  }
  return r;
}

long solve(long n) {
  long v;
  long dist[n + 1];
  for (int i = 0; i < n; i++) dist[i] = LONG_MAX;
  dist[n] = 0;

  for (v = n; v > 0; v--) {
    long r = reverse(v);
    if (v % 10 != 0 && r < v && dist[r] > dist[v] + 1) {
      dist[r] = dist[v] + 1;
    }
    if (dist[v - 1] > dist[v] + 1) {
      dist[v - 1] = dist[v] + 1;
    }
  }

  return dist[0];
}

int main(void) {
  int T; scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    long n; scanf("%ld", &n);
    printf("Case #%d: %ld\n", t, solve(n));
  }
}

