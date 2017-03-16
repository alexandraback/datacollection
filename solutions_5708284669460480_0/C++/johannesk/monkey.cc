#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <array>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>

typedef int real_int;
#define int long long

real_int main()
{
  int t; std::cin >> t;
  std::cout << std::fixed << std::setprecision(20);
  for (int i=0; i<t; ++i) {
    int k, l, s; std::cin >> k >> l >> s;
    std::string keyboard, target; std::cin >> keyboard >> target;
    std::array<int, 26> hist{{}};
    for (char c : keyboard)
      hist[c-'A']++;
    bool possible = true;
    for (char c : target)
      if (hist[c-'A'] == 0)
        possible = false;
    if (!possible) {
      std::cout << "Case #" << i+1 << ": " << 0. << '\n';
      continue;
    }
    
    double expectation = [&](){
      double p = 1;
      for (char c : target)
        p *= hist[c-'A']/static_cast<double>(keyboard.size());
      return (s - target.size() + 1)*p;
    }();
    std::size_t z_value = [&](){
      for (std::size_t i=1; i<=target.size(); ++i)
        if (std::equal(target.begin()+i, target.end(), target.begin()))
          return i;
      assert(false);
    }();
    int worstcase = 1 + (s - target.size())/z_value;
    std::cout << "Case #" << i+1 << ": " << worstcase - expectation << '\n';
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 monkey.cc -o monkey && for f in *.in; do echo \"--- $f -------------\"; ./monkey <$f; done"
 * end:
 */

