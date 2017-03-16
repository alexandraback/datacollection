#include <iostream>
#include <vector>

class TilePositionGenerator {
 public:
  static unsigned long long generate(const std::vector<int> indices, unsigned long long K) {
    unsigned long long index = 0;
    for (unsigned i = 0; i < indices.size(); ++i) {
      index *= K;
      index += indices[i];
    }
    return index;
  }
};

int main() {
  int T;
  std::cin >> T;

  unsigned long long K, C, S;
  for (int t=0; t<T; ++t) {
    std::cin >> K;
    std::cin >> C;
    std::cin >> S;

    int toTreat = K;
    unsigned long long nextToTreat = 0;
    std::vector<unsigned long long> positions;
    while (toTreat > 0) {
      std::vector<int> indices;
      for (unsigned i = 0; i< C; ++i) {
        if(nextToTreat == K)
          nextToTreat = 0;
        indices.push_back(nextToTreat);
        nextToTreat++;
        --toTreat;
      }
      positions.push_back(TilePositionGenerator::generate(indices,K));
    }

    std::cout << "Case #" << t+1 << ":";
    if (positions.size() > S)
      std::cout << " IMPOSSIBLE";
    else {
      for (auto p : positions)
        std::cout << " " << p+1;
    }
    std::cout << std::endl;
  }
  return 0;
}
