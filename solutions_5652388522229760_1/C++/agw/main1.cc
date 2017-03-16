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

  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    long long N, NN = 0;

    std::cin >> N;

    int c = 0, n;

    bool used[11] = {0};

    for (int i = 1; i < 111111; i ++) {
      char buf[256];

      sprintf(buf, "%lld", NN += N);

      for (char* p = buf; *p != '\0'; p ++)
        if (! used[n = *p - '0']) {
          used[n] = true;

          c ++;

          if (c == 10)
            goto endloop;
        }
    }

  endloop:

    if (c == 10) {
      std::cout << "Case #" << t << ": " << NN << std::endl;
    }
    else {
      std::cout << "Case #" << t << ": INSOMNIA" << std::endl;
    }
  }

  return 0;
}
