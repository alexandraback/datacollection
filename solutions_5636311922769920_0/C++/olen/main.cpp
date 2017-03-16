#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;

  unsigned long long K, C, S;
  for (int t=0; t<T; ++t) {
    std::cin >> K;
    std::cin >> C;
    std::cin >> S;

    unsigned long long distance = 1;
    for (int i = 0; i < C-1; ++i)
      distance *= K;

    std::cout << "Case #" << t+1 << ": ";
    unsigned long long tile = 1;
    for (int i = 0; i < K; ++i) {
      std::cout << tile << " ";
      tile += distance;
    }
    std::cout << std::endl;

  }
  return 0;
}
