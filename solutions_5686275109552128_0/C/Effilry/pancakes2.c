#include <limits.h>
#include <math.h>
#include <stdio.h>

int optimal_piles[1001] = {0};

void init_optimal_piles(void) {
  for (int P = 1; P <= 1000; P++) {
    int min_cost  = INT_MAX,
        min_index = -1;
    for (int n = 1; n <= P; n++) {
      // Split `P` in `n` piles
      int cost = (int) ceil((float) P / n) + n;
      if (cost < min_cost) {
        min_cost = cost;
        min_index = n;
      }
    }
    optimal_piles[P] = min_index;
  }
}

int desc_comparator(int a, int b) {
  return a - b;
}


int main(void) {
//init_optimal_piles();

  int N;
  scanf("%d", &N);
  getchar();

  for (int n = 1; n <= N; n++) {
    int D;
    scanf("%d", &D);

    // Read pancakes
    int pancakes[1001];
    for (int i = 0; i < D; i++) scanf("%d", &pancakes[i]);

    int max_pancake = 0;
    for (int i = 0; i < D; i++) if (pancakes[i] > max_pancake) max_pancake = pancakes[i];

    int min = 1001;
    for (int target = 1; target < min; target++) {
      int count = 0;
      for (int i = 0; i < D; i++) {
        // To divide `pancakes[i]` into piles of maximum size `target`, we
        // need to divide it `pancakes[i] / target - 1` times.
        count += ceil((float) pancakes[i] / target) - 1;
      }

      if (count + target < min) min = count + target;
    }

    printf("Case #%d: %d\n", n, min);
  }
}
