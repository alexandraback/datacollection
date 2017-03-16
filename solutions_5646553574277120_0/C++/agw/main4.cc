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

  int T, C, D, V, d[111];

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> C >> D >> V;

    assert(C == 1);

    for (int i = 0; i < D; i ++)
      std::cin >> d[i];

    std::sort(d, d + D);

    std::set<int> set;

    for (int i = 0; i < (1 << D); i ++) {
      int x = 0;

      for (int j = 0, b = 1; j < D; j ++, b *= 2)
        if (i & b)
          x += d[j];

      set.insert(x);
    }

    bool visit[111];

    for (int i = 0; i < 111; i ++)
      if (i <= V) {
        visit[i] = false;
      }
      else {
        visit[i] = true;
      }

    for (const auto& i : set)
      visit[i] = true;

    int c = 0;

    for (int i = 1; i <= V; i ++) {
      bool use = false;

      for (int j = 0; j <= V; j ++)
        if (visit[j])
          if (! visit[j + i]) {
            use = true;
            
            break;
          }
      
      if (use) {
        for (int j = V; j >= 0; j --)
          if (visit[j])
            visit[j + i] = true;

        c ++;
      }
    }

    std::cout << "Case #" << t << ": " << c << std::endl;
  }
  
  return 0;
}
