#include <algorithm>
#include <cassert>
#include <cstdio>
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


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int T, K, C, S;


long long dfs(int n, int d, long long x)
{
  assert(0 <= n && n < K);
  
  if (d == C)
    return x;
  
  return dfs(std::min(n + 1, K - 1), d + 1, x * K + n);
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cout << "Case #" << t << ':';
    
    std::cin >> K >> C >> S;

    int n = 1. * K / C + 0.999;

    if (S < n) {
      std::cout << " IMPOSSIBLE" << std::endl;
      
      continue;
    }

    std::vector<long long> a;

    for (int i = 0, j = 0; i < n; i ++, j += C)
      a.push_back(dfs(j, 0, 0) + 1);

    for (const auto& i : a)
      std::cout << ' ' << i;

    std::cout << std::endl;
  }

  return 0;
}
