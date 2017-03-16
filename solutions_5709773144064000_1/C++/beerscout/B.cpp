#include <algorithm>
#include <iostream>


double solve_case(double C, double F, double X)
{
  double best = X/2;
  int max_f = int(X);
  double s = C/2;
  for ( int i = 1; i <= max_f; ++i )
  {
    double t = X/(2 + i*F) + s;
    best = std::min(best, t);
    s += C/(2 + i*F);
  }
  return best;
}


int main()
{
  int T;
  std::cout.precision(15);
  std::cin >> T;
  for ( int i = 1; i <= T; ++i )
  {
    double C, F, X;
    std::cin >> C >> F >> X;
    std::cout << "Case #" << i << ": " << solve_case(C, F, X) << '\n';
  }
  return 0;
}
