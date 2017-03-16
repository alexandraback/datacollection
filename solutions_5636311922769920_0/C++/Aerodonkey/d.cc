#include <iostream>

int main() {
  int T;
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    int K, C, S;
    std::cin >> K >> C >> S;
    std::cout << "Case #" << (i + 1) << ":";
    for (int j = 0; j < K; j++) {
      std::cout << ' ' << (j + 1);
    }
    std::cout << std::endl;
  }
}
