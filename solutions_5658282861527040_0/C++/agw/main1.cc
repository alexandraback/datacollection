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
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, A, B, K;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> A >> B >> K;
    
    int c = 0;
    
    for (int i = 0; i < A; i ++)
      for (int j = 0; j < B; j ++)
        if ((i & j) < K)
          c ++;

    std::cout << "Case #" << t << ": " << c << std::endl;
  }

  return 0;
}
