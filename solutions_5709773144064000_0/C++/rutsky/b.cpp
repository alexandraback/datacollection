#include <iostream>
#include <iomanip>

double solve(double C, double F, double X)
{
  double cur_opt_time = X / 2.0;
  double stop_time = 0;

  for (size_t i = 0; stop_time < cur_opt_time; ++i)
  {
    stop_time += C / (2.0 + i * F);

    double t = stop_time + X / (2.0 + (i + 1) * F);
    if (t < cur_opt_time)
    {
      cur_opt_time = t;
    }
  }

  return cur_opt_time;
}

int main()
{
  size_t T;

  std::cin >> T;

  for (size_t case_idx = 0; case_idx != T; ++case_idx)
  {
    double C, F, X;
    std::cin >> C >> F >> X;

    std::cout << "Case #" << (case_idx + 1) << ": " <<
        std::fixed << std::setprecision(7) << solve(C, F, X) << "\n";
  }
}
