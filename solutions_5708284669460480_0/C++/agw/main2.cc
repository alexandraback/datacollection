#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int K, L, S;

std::string k, l;


std::pair<int, double> dfs(std::string s)
{
  int size = s.size();

  int cp = 0;

  double e = 0.0;

  if (size == S) {
    for (int i = 0; i < size; i ++)
      if (s.substr(i, L) == l)
        cp ++;

    return std::make_pair(cp, 1. * cp);
  }

  for (const auto& i : k) {
    std::pair<int, double> x = dfs(s + i);

    cp = std::max(x.first, cp);

    e += x.second / K;
  }

  return std::make_pair(cp, e);
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T;

  std::cin >> T;

  std::cout << std::fixed << std::setprecision(9);
  std::cerr << std::fixed << std::setprecision(9);

  for (int t = 1; t <= T; t ++) {
    std::cin >> K >> L >> S >> k >> l;

    std::pair<int, double> x = dfs("");

    std::cerr << "Case #" << t << ": " << x.first - x.second << std::endl;
    std::cout << "Case #" << t << ": " << x.first - x.second << std::endl;
  }
  
  return 0;
}
