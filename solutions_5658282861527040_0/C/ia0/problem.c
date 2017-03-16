#include <stdio.h>

void read_int(int *x) {
  if (scanf("%d", x) != 1)
    perror(__FUNCTION__);
}

int main(void) {
  int T, t;
  read_int(&T);
  for (t = 1; t <= T; t++) {
    int A, B, K;
    printf("Case #%d: ", t);
    read_int(&A);
    read_int(&B);
    read_int(&K);

    int a, b, res;
    res = 0;
    for (a = 0; a < A; a++)
      for (b = 0; b < B; b++)
        if ((a & b) < K)
          res++;

    printf("%d\n", res);
  }
  return 0;
}
