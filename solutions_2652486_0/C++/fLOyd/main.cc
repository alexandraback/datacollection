#include <iostream>

int T, R, N, M, K;

int probability[200];
int products[10], product_count[200];

void solve() {
  std::cin >> T >> R >> N >> M >> K;
  for (int i = 0; i < R; ++i) {
    bool failure = false;
    memset(product_count, 0, sizeof(product_count));
    for (int j = 0; j < K; ++j) {
      std::cin >> products[j];
      if (++product_count[products[j]] > 1) {
        products[j] = 0;
      }
    }
    int current, best = 10000, ans[3];
    for (int n0 = 2; n0 <= M; ++n0) {
      for (int n1 = n0; n1 <= M; ++n1) {
        for (int n2 = n1; n2 <= M; ++n2) {
          failure = false;
          memset(probability, 0, sizeof(probability));
          probability[1]++;
          probability[n0]++;
          probability[n1]++;
          probability[n2]++;
          probability[n0 * n1]++;
          probability[n0 * n2]++;
          probability[n1 * n2]++;
          probability[n0 * n1 * n2]++;
          current = 0;
          for (int j = 0; j < K; ++j) {
            if (products[j] != 0) {
              if (probability[products[j]] <= 0) { failure = true; break; }
              current += abs(probability[products[j]] - product_count[products[j]]);
            }
          }
          if (failure) continue;
          if (current < best) {
            best = current;
            ans[0] = n0;
            ans[1] = n1;
            ans[2] = n2;
          }
        }
      }
    }
    for (int j = 0; j < N; ++j) { std::cout << ans[j]; }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
