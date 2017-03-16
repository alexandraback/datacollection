#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

typedef long long int lld;

bool isvovel(char c)
{
  switch (c) {
  case 'a': case 'e': case 'i': case 'o': case 'u':
    return true;
  default:
    return false;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
  int testcases = 0; std::cin >> testcases;

  std::string s;
  std::vector<int> v;

  for (int case_nr=1; case_nr<=testcases; ++case_nr) {
    std::cout << "Case #" << case_nr << ": ";    

    std::cin >> s; int n; std::cin >> n;
    v.resize(0); v.reserve(s.size());
    { int cnt = 0;
      for (char c : s) {
        cnt = !isvovel(c) ? cnt+1 : 0;
        v.push_back(cnt);
      }
    }

    lld nvalue = 0;
    int last_nspot = -1;
    for (int i=0; i<(signed)s.size(); ++i) {
      if (v[i] < n)
        continue;

      nvalue += ((lld)i - n+1 - last_nspot)*(s.size() - i);

      last_nspot = i-n+1;
    }
    std::cout << nvalue;
    std::cout << '\n';
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"rm -f fast-consonants && g++ -Ofast -flto -march=native -std=c++11 consonants.cc -o fast-consonants >/dev/null &; g++ -g -ggdb3 -O0 -D_GLIBCXX_DEBUG -Wall -Wextra -pedantic -Wno-long-long -std=c++11 consonants.cc -o consonants && for f in *.in; do echo \"--- $f -------------\"; ./consonants <$f; done"
 * end:
 */
