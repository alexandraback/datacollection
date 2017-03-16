#include <iostream>
#include <algorithm>

const int kMaxE = 100;
const int kMaxN = 10005;

long long f[kMaxN][kMaxE];

long long solve() {
  int E, R, N, v[kMaxN];
  std::cin >> E >> R >> N;
  for (int i = 0; i < N; ++i) { std::cin >> v[i]; }
  memset(f, 0, sizeof(f));
  for (int i = N - 1; i >= 0; --i) {
    for (int e = std::min(E, R); e <= E; ++e) {
      for (int use = 0; use <= e; ++use) {
        f[i][e] = std::max(f[i][e],f[i + 1][std::min(E, e - use + R)] + v[i] * use);
      }
    }
  }
  return f[0][E];
}

int main(int argc, char *argv[]) {
  int T;
  std::cin >> T;
  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": " << solve() << std::endl;
  }
  return 0;
}
