#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <cstdlib>

int compareChar(char a, char b) {
  if (a < b)
    return -1;
  if (a > b)
    return 1;
  return 0;
}


int main(int argc, char** argv) {
  unsigned int T;
  std::string S;

  std::cin >> T;

  for (int i = 0; i < T; i ++) {
    std::cin >> S;
    std::string result = S.substr(0, 1);
    
    for (int j = 1; j < S.size(); j++) {
      if (S[j] < result[0])
        result.append(S.substr(j, 1));
      else
        result.insert(0, S.substr(j, 1));
    }

    std::cout << "Case #" << i+1 << ": " << result << std::endl;
  }

  return 0;
}

