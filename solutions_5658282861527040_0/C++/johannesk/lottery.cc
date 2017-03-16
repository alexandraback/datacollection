#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

void solve() {
  int a, b, k;
  std::cin >> a >> b >> k;
  unsigned long long int cnt=0;
  for (int i=0; i<a; ++i)
    for (int j=0; j<b; ++j)
      if ((i&j) < k)
	cnt++;
  std::cout << cnt;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int num_of_testcases; std::cin >> num_of_testcases;
  for (int testcase=1; testcase<=num_of_testcases; ++testcase) {
    std::cout << "Case #" << testcase << ": ";
    solve();
    std::cout << '\n';
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -std=c++1y lottery.cc -o lottery && for f in *.in; do echo \"--- $f -------------\"; ./lottery <$f; done"
 * end:
 */
