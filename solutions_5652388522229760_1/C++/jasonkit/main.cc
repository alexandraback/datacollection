#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <sstream>

namespace mp = boost::multiprecision;

int main(int argc, char** argv) {
  int T;
  std::cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    std::cin >> N;

    if (N == 0) {
      std::cout << "Case #" << t + 1 << ": INSOMNIA" << std::endl;
      continue;
    }

    mp::cpp_int val = 0;

    bool digitsSeen[10] = {false};
    int nDigitSeen = 0;

    while (nDigitSeen < 10) {
      std::ostringstream ss;
      val += N;

      ss << val;
      std::string valInString = ss.str();

      for (int i = 0; i < valInString.length(); i++) {
        if (!digitsSeen[valInString[i] - '0']) {
          digitsSeen[valInString[i] - '0'] = true;
          nDigitSeen++;

          if (nDigitSeen == 10) {
            break;
          }
        }
      }
    }

    std::cout << "Case #" << t + 1 << ": " << val << std::endl;
  }
  return 0;
}
