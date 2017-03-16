#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long int lli;

#define all(c) (c).begin(),(c).end()
#define foreach(name, list)         \
  for (__decltype((list).begin())   \
         name = (list).begin(),     \
         name##_end = (list).end(); \
       name != name##_end; ++name)

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int num_of_testcases; std::cin >> num_of_testcases;
  for (int testcase=1; testcase<=num_of_testcases; ++testcase) {
    std::cout << "Case #" << testcase << ": ";
    
    int n; std::cin >> n;
    std::vector<std::pair<int, std::string> > v(n);
    for (int i=0; i<n; ++i) { std::cin >> v[i].second; v[i].first=i; }
    std::sort(v.begin(), v.end());

    const lli mod = 1000000007;
    lli possibs=0;
    do {
      bool used['z'-'a'+1] = {};
      char last=0;
      for (auto& s : v) {
        //std::cout << s.second << " ";
        for (char c : s.second) {
          if (last!=c) {
            if (last) {
              if (used[last-'a'])
                goto next;
              used[last-'a']=true;
            }
            last=c;
          }
        }
      }
      if (!used[last-'a']) {
        possibs = (possibs+1)%mod;
        //std::cout << "++";
      }
    next:;
      //std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
    std::cout << possibs << '\n';
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -Wno-long-long -std=c++11 b.cc -o b && for f in *.in; do echo \"--- $f -------------\"; ./b <$f; done"
 * end:
 */

