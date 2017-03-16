#include <cassert>
#include <iostream>

int main() {
  int numberOfCases;
  std::cin >> numberOfCases;
  for (int caseNo = 0; caseNo < numberOfCases; ++caseNo) {
    int k, complexity, scientists;
    std::cin >> k >> complexity >> scientists;
    assert (k == scientists);
    std::cout << "Case #" << caseNo + 1 << ":";
    for (int i = 0; i < scientists; ++i) {
      std::cout << ' ' << i + 1;
    }
    std::cout << '\n';
  }
  return 0;
}
