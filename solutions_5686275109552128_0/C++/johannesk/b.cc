#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int evanize(std::vector<int>& v, int maxlevel) {
  int moves = 0;
  for (auto& i : v)
    moves += (i-1)/maxlevel;
  return moves;
}

int main() {
  int t; std::cin >> t;
  for (int tc=1; tc<=t; ++tc) {
    int d; std::cin >> d;
    std::vector<int> v;
    std::copy_n(std::istream_iterator<int>(std::cin), d, std::back_inserter(v));

    int max = *std::max_element(v.begin(), v.end());
    int best = max;
    for (int i=1; i<=max+1; ++i)
      best = std::min(best, i+evanize(v, i));
    
    std::cout << "Case #" << tc << ": " << best << '\n';
  }
}
