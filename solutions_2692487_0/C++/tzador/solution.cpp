#include <algo/macros.hpp>

long M[1000];

int cmp(const void *a, const void *b) {
  const long *aa = (const long *)a;
  const long *bb = (const long *)b;
  if (*aa > *bb)
    return 1;
  if (*aa < *bb)
    return -1;
  return 0;
}

int best(int N, long A) {
  int cnt = 0;
  int i = 0;
  while (i < N) {
    if (M[i] < A) {
      A += M[i];
      i++;
    } else {
      if (A == 1)
        return N;
      A += A - 1;
      cnt += 1;
    }
  }
  return cnt;
}

int main() {
  FREOPEN("small0.in");
  FREOPEN_OUT("small0.out");
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    int A, N;
    scanf("%d %d", &A, &N);
    for (int i = 0; i < N; i++)
      scanf("%ld", &M[i]);
    qsort(M, N, sizeof(long), cmp);

    int sol = N;
    for (int n = 0; n <= N; n++) {
      int cur = N - n + best(n, A);
      if (cur < sol)
        sol = cur;
    }
    printf("Case #%d: %d\n", t, sol);
  }
}
