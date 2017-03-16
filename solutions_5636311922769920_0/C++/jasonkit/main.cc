#include <iostream>

int main(int argc, char** argv) {
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    int K, C, S;
    std::cin >> K;
    std::cin >> C;
    std::cin >> S;

    std::cout << "Case #" << t << ":";

    if (K == 1) {
      std::cout << " 1" << std::endl;
      continue;
    }

    if (C == 1) {
      if (K == S) {
        for (int i = 1; i <= K; i++) {
          std::cout << " " << i;
        }
        std::cout << std::endl;
      } else {
        std::cout << " IMPOSSIBLE" << std::endl;
      }
    } else {
      if (S >= K - 1) {
        for (int i = 2; i <= K; i++) {
          std::cout << " " << i;
        }
        std::cout << std::endl;
      } else {
        std::cout << " IMPOSSIBLE" << std::endl;
      }
    }
  }
  return 0;
}
