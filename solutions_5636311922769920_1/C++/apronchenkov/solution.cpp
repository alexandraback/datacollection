#include <cstdint>
#include <iostream>
#include <vector>

using Integer = uint64_t;
using IntegerList = std::vector<Integer>;

IntegerList GenerateCriticalPositions(Integer baseLength, Integer complexity) {
  IntegerList result;
  for (Integer start = 0; start < baseLength;) {
    Integer position = 0;
    for (Integer i = 0; i < complexity; ++i) {
      position *= baseLength;
      if (start < baseLength) {
        position += start;
        ++start;
      }
    }
    result.push_back(position);
  }
  return result;
}

int main() {
  int numberOfCases;
  std::cin >> numberOfCases;
  for (int caseNo = 0; caseNo < numberOfCases; ++caseNo) {
    Integer baseLength, complexity, scientists;
    std::cin >> baseLength >> complexity >> scientists;
    const auto criticalPositions =
        GenerateCriticalPositions(baseLength, complexity);
    std::cout << "Case #" << caseNo + 1 << ":";
    if (criticalPositions.size() <= scientists) {
      for (auto position : criticalPositions) {
        std::cout << ' ' << position + 1;
      }
    } else {
      std::cout << " IMPOSSIBLE";
    }
    std::cout << '\n';
  }
  return 0;
}
