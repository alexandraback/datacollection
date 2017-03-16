#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAX 100
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int A, N;
int m[MAX];

int rec (int k, int s) {
  if (k == N) {
    return 0;
  }
  if (m[k] < s) {
    return rec(k+1, s+m[k]);
  }
  if (s == 1) { // or IL
    return N - k;
  }
  int i = 0;
  while (s <= m[k]) {
    s += s-1;
    i++;
  }
  return MIN(i+rec(k+1, s+m[k]), N-k);
}

int main (void) {
  int T;
  int scanned = scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    scanf("%d%d", &A, &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &m[i]);
    }
    std::sort(m, m+N);
    printf("Case #%d: %d\n", currentcase, rec(0, A));
  }
  return 0;
}
