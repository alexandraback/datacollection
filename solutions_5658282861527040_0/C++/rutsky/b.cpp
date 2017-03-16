/*
 * CodeJam 2014. Round 1B. Problem B
 * Vladimir Rutsky
 * 03.05.2014
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>
#include <cstdio>

using namespace std;

std::string solve(size_t A, size_t B, size_t K)
{
  size_t res = 0;

  for (size_t a = 0; a != A; ++a)
    for (size_t b = 0; b != B; ++b)
    {
      if ((a & b) < K)
        ++res;
    }

  return std::to_string(res);
}

int main()
{
  size_t T;

  //FILE * res = std::freopen("small.in", "rt", stdin);
  //FILE * res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //FILE * res = std::freopen("A-large.in", "rt", stdin);
  //assert(res);

  std::cin >> T;

  for (size_t idx = 0; idx != T; ++idx)
  {
    size_t A, B, K;
    std::cin >> A >> B >> K;

    std::cout << "Case #" << (idx + 1) << ": " << solve(A, B, K) << "\n";
  }
}
