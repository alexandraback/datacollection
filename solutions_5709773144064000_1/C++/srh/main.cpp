#include <iostream>
#include <cstdio>

int main() {
  int T;
  std::cin >> T;
  for (int casenum = 1; casenum <= T; ++casenum) {
    double C, F, X;
    std::cin >> C >> F >> X;

    double rate = 2;
    double mintime = X / rate;
    double t = 0;
    do {
      mintime = std::min(mintime, t + X / rate);
      t += C / rate;
      rate += F;
    } while (t < mintime);

    std::cout << "Case #" << casenum << ": ";
    std::printf("%.20g", mintime);
    std::cout << std::endl;
  }
}
