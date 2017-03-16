#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <array>

typedef int real_int;
#define int long long

real_int main()
{
  int t; std::cin >> t;
  for (int i=0; i<t; ++i) {
    int r, c, w; std::cin >> r >> c >> w;
    int rowmiss = (r-1)*(c/w);
    int rowhit = c/w + w-1 + !!(c%w);
    std::cout << "Case #" << i+1 << ": " << rowmiss + rowhit << '\n';
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 brattleship.cc -o brattleship && for f in *.in; do echo \"--- $f -------------\"; ./brattleship <$f; done"
 * end:
 */

