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


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, R, C, W;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> R >> C >> W;

    int n = 0;

    while (2 * W <= C) {
      n ++;

      C -= W;
    }

    n += std::min(W + 1, C);

    std::cout << "Case #" << t << ": " << n << std::endl;
  }

  return 0;
}
