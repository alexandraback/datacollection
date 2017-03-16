#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <array>
#include <deque>

typedef int real_int;
#define int long long

real_int main()
{
  int t; std::cin >> t;
  for (int i=0; i<t; ++i) {
    int c, d, v; std::cin >> c >> d >> v;
    std::deque<int> coins;
    std::copy_n(std::istream_iterator<int>(std::cin), d,
                std::back_inserter(coins));
    std::sort(coins.begin(), coins.end());
    std::vector<int> finalcoins;
    int min_impossible = 1;
    while (min_impossible <= v) {
      int new_coin = min_impossible;
      if (!coins.empty() && coins.front() <= new_coin) {
        new_coin = coins.front();
        coins.pop_front();
      }
      finalcoins.push_back(new_coin);
      min_impossible += c*new_coin;
    }    
    std::cout << "Case #" << i+1 << ": "
              << finalcoins.size() - (d - coins.size()) << '\n';
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 money.cc -o money && for f in *.in; do echo \"--- $f -------------\"; ./money <$f; done"
 * end:
 */

