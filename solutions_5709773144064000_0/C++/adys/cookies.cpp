#include <iomanip>
#include <iostream>

double solve(const double C, const double F, const double X)
{
  double time = 0.;
  double slope = 2.;
  for (;;) {
    if (X / slope < C / slope + X / (slope + F))
      return time + X / slope;
    time += C / slope;
    slope += F;
  }
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    double C, F, X;
    std::cin >> C >> F >> X;
    std::cout << std::setprecision(7) << std::fixed;
    std::cout << "Case #" << t << ": " << solve(C,F,X) << std::endl;
  }
  return 0;
}
