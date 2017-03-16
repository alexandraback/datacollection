#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <gmpxx.h>
//typedef long long int lli;
typedef mpz_class lli;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int num_of_testcases; std::cin >> num_of_testcases;
  for (int testcase=1; testcase<=num_of_testcases; ++testcase) {
    std::cout << "Case #" << testcase << ": ";
    lli p, q; { char c; std::cin >> p >> c >> q; assert(c=='/'); }

    lli gcd = std::__gcd(p, q); p/=gcd; q/=gcd;
    lli depth(1); depth<<=40;
    assert(q>1 && q<=depth);
    if ((q&(q-1))!=0) {
      std::cout << "impossible\n";
    } else {
      int gen=0;
      for (lli xpq=1; p*xpq < q; xpq <<= 1) {
        if (++gen == 41) {
          std::cout << "impossible\n";
          break;
        }
      }
      assert(gen>0);
      if (gen<41)
        std::cout << gen << '\n';
    }
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -Wno-long-long -std=c++11 a.cc -o a && for f in *.in; do echo \"--- $f -------------\"; ./a <$f; done"
 * end:
 */

