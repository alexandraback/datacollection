#include <iostream>

double solve(double r, double C, double F, double X) {
  double time = 0;
  double timeToC = C/r;
  double timeToX1 = X/r;
  double timeToX2 = X/(F+r);

  while (timeToX1 > timeToC + timeToX2) {
    time += timeToC;
    r += F;
    timeToC = C/r;
    timeToX1 = X/r;
    timeToX2 = X/(F+r);
  }
  return time + timeToX1;
}

int main() {
  int T;
  double C, F, X;
 
  std::cout.precision(9);
  std::cin >> T;
  for (int ii = 1; ii <= T; ii++) {
    std::cin >> C >> F >> X;
    std::cout << "Case #" << ii << ": " << solve(2, C, F, X) << std::endl;
  }
}
