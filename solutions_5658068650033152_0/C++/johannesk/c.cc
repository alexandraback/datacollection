#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
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
    auto tria = [](int i){return i*(i+1)/2;};

    int n, m, k; std::cin >> n >> m >> k;
    if (n > m) std::swap(n, m);
    assert(m >= n);

    int minstones=n*m;

    for (int h=0; h<n; ++h) {
      for (int w=0; w<m; ++w) {
        if (w<h) continue;
        for (int a=0; a<=w; ++a) {
          for (int b=0; a+b<=w; ++b) {
            for (int c=0; b+c<=h; ++c) {
              for (int d=0; c+d<=w; ++d) {
                assert(h<=w);
                if (a+d <= h) {
                  int outside=tria(a)+tria(b)+tria(c)+tria(d);
                  //if (a+b==w) --outside;
                  //i (b+c==h) --outside;
                  //if (c+d==w) --outside;
                  //if (d+a==h) --outside;
                  int inside=(w+1)*(h+1)-outside;

                  int stones=2*(w+1)+std::max(0,(h+1-(a+1)-(d+1)))
                    + std::max(0,(h+1-(b+1)-(c+1)));
                  if (a+d==h) --stones;
                  if (b+c==h) --stones;
                  if (h==0) {
                    assert(a==0&&b==0&&c==0&&d==0);
                    stones=w+1;
                    inside=w+1;
                  }
                  //std::cout << w<<'/'<<h<<": " << a << " " << b << " " <<c << " " <<d << " inside: " << inside << " stones: "<<  stones << std::endl;
                  if (inside >= k)
                    minstones = std::min(minstones, stones);
                }
              }
            }
          }
        }
      }
    }
    std::cout << minstones << '\n';
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -Wno-long-long -std=c++11 c.cc -o c && for f in *.in; do echo \"--- $f -------------\"; ./c <$f; done"
 * end:
 */

