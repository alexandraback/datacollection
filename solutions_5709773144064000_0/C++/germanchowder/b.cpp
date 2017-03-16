#include <iostream>

double solve(double r, double C, double F, double X) {
  double timeToC = C/r;
  double timeToX1 = X/r;
  double timeToX2 = X/(F+r);

  if (timeToX1 < timeToC+timeToX2) {
    return timeToX1;
  }
  else {
    return timeToC + solve(F+r, C, F, X);
  }
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
