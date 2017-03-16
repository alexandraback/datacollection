#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;

  for (int i=0; i<T; ++i) {
    std::string S;
    std::cin >> S;
    char currentChar = S.front();
    long long nFlips = 0;
    for (int i = 1; i < S.size(); ++i) {
      char nextChar = S.at(i);
      if (nextChar != currentChar)
        nFlips++;
      currentChar = nextChar;
    }
    if (currentChar == '-')
      nFlips++;

    std::cout << "Case #" << i+1 << ": " << nFlips << std::endl;
  }
}
