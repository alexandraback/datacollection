#include <stdio.h>
#include <map>

#define MAX(x,y) ((x)>(y)?(x):(y))

using namespace std;

int R, N, M, K;

int input[20];
int numbers[20];

void process() {
  map<int, int> factors;

  for (int i = 2; i <= M; i++) {
    int factored = 0;
    for (int k = 0; k < K; k++) {
      int fact = 0;
      while ((input[k] % i) == 0) {
        input[k] /= i;
        fact++;
      }
      factored = MAX(factored, fact);
    }
    factors[i] = MAX(factors[i], factored);
  }

  int output[N];

  for (int i = 0; i < N; i++) {
    output[i] = 1;
  }

  int curnum = 0;
  for (int i = M; i >= 2; i--) {
    while(factors[i] && curnum < N) {
      output[curnum++] = i;
      factors[i]--;
    }
  }

  for (int i = M; i >= 2; i--) {
    for (int k = 0; k < N; k++) {
      while (factors[i] && output[k] * i <= M) {
        output[k] *= i;
        factors[i]--;
      }
    }
  }

  for (int k = 0; k < N; k++) {
    if (output[k] == 1) {
      output[k] = 2;
    }

    printf("%d", output[k]);
  }
  printf("\n");

  int check = 1;
  for (int i = 2; i < M; i++) {
    while (factors[i]) {
      factors[i]--;
      check *= i;
    }
  }
  if (check > 1) {
    fprintf(stderr, "CHECK FAIL: %d\n", check);
  }
}

int main() {
  int T;
  scanf("%d", &T);

  scanf("%d%d%d%d", &R, &N, &M, &K);

  printf("Case #1:\n");

  for (int r = 0; r < R; r++) {
    for (int k = 0; k < K; k++) {
      scanf("%d", &input[k]);
    }
    process();
  }

  return 0;
}
