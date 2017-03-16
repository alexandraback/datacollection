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

  int T, n, size;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::string s;

    std::cin >> s;

    size = s.size();

    s.push_back('$');

    for (n = 0; ; n ++) {
      int x = -1;

      for (int i = 0; i < size; i ++)
        if (s[i] != s[i + 1]) {
          x = i + 1;

          break;
        }

      if (x == size)
        if (s[size - 1] == '+')
          break;

      char c = s[0] == '+' ? '-' : '+';

      for (int i = 0; i < x; i ++)
        s[i] = c;
    }

    std::cout << "Case #" << t << ": " << n << std::endl;
  }
  
  return 0;
}
