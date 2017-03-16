#include <stdio.h>
#include <inttypes.h>

int main() {
  int T;
  int Q;

  scanf(" %d", &T);

  for (Q = 1; Q <= T; Q++) {
    int K, C, S;

    scanf(" %d %d %d", &K, &C, &S);
    printf("Case #%d:", Q);

    if (S < K) {
      printf(" NYI\n");
    } else {
      int i;
      
      for (i = 0; i < K; i++) {
	int j;
	uintmax_t pos = i;

	for (j = 1; j < C; j++) {
	  pos = pos * K + i;
	}

	printf(" %jd", pos + 1);
      }

      putchar('\n');
    }
  }
}
