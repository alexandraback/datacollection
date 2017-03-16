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


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, B;

  long long M;

  std::cin >> T;

  long long a[55];

  a[0] = a[1] = 1;

  for (int i = 1; i < 55; i ++)
    a[i + 1] = a[i] * 2;

  for (int t = 1; t <= T; t ++) {
    std::cin >> B >> M;

    bool use[55] = {0};

    for (int i = B - 2; i >= 0; i --) {
#if 0
      std::cout << "  i=" << i << " a[i]=" << a[i] << " M=" << M << std::endl;
#endif

      if (M >= a[i]) {
        use[i] = true;
        
        M -= a[i];
      }
    }

    if (M == 0) {
      std::cout << "Case #" << t << ": POSSIBLE" << std::endl;

      for (int i = 0; i < B; i ++) {
        for (int j = 0; j < B; j ++)
          if (j <= i) {
            std::cout << 0;
          }
          else if (j < B - 1) {
            std::cout << 1;
          }
          else {
            std::cout << (use[i] ? 1 : 0);
          }
        
        std::cout << std::endl;
      }
    }
    else {
      std::cout << "Case #" << t << ": IMPOSSIBLE" << std::endl;
    }
  }

  return 0;
}
