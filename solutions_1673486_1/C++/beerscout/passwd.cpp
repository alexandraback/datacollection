#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>


double best(int A, int B, std::vector<double> const &P)
{
  double best = std::min(A + B + 1, B + 2);
  double prob = 1;
  int c1 = B - A + 1;
  int c2 = 2*B + 2 -A;
  int idx = 0;
  for ( int k = A - 1; k >= 0; --k )
  {
    prob *= P[idx++];
    double nk = (c1 + 2*k)*prob + (c2 + 2*k)*(1 - prob);
    best = fmin(nk, best);
  }
  return best;
}


int main()
{
  std::cout.precision(15);
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int A, B;
    std::cin >> A >> B;
    std::vector<double> P(A);
    for ( int a = 0; a < A; ++a )
      std::cin >> P[a];
    std::cout << "Case #" << t << ": "
      << best(A, B, P) << '\n';
  }
  return 0;
}
