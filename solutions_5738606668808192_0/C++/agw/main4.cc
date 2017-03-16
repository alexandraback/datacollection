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


int test(long long n)
{
  std::vector<int> a;
  
  for (long long i = 2; i * i <= n; i ++) {
    for ( ; n % i == 0; n /= i)
      a.push_back(i);

    if (! a.empty()) {
      assert(a.front() != n);
      
      return a.front();
    }
  }

  return 0;
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);


  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cout << "Case #" << t << ':' << std::endl;

    
    int N, J, j = 0;

    std::cin >> N >> J;


    for (int i = 0, size = 1 << (N - 2); i < size; i ++) {
      std::string s;

      for (int k = 0, ii = i; k < N - 2; k ++, ii >>= 1)
        s.push_back(ii & 1 ? '1' : '0');

      std::reverse(ALL(s));

      s.insert(std::begin(s), '1');
      s.push_back('1');

      int a[11] = {0};

      for (int b = 2; b <= 10; b ++) {
        long long n = 0, B = 1;

        std::string ss(s);

        for ( ; ! ss.empty(); B *= b) {
          n += (ss.back() - '0') * B;
      
          ss.pop_back();
        }

        if ((a[b] = test(n))) {
          ;
        }
        else {
          goto failed;
        }
      }

      std::cout << s;

      for (int b = 2; b <= 10; b ++)
        std::cout << ' ' << a[b];

      std::cout << std::endl;

      if (++ j == J)
        break;

    failed:
      ;
    }
  }
  
  return 0;
}
