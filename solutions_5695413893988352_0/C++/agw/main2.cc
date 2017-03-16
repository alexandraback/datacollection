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


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


bool match(const std::string& s, const std::string& t)
{
  assert(s.size() == t.size());
  
  for (int i = 0, size = s.size(); i < size; i ++)
    if (s[i] == '?') {
    }
    else if (s[i] != t[i]) {
      return false;
    }

  return true;
}
  

int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::string C, J;

    std::cin >> C >> J;

    int size = C.size();

    int np = pow(10, size);

    int im = -1, jm = -1, dm = INF, d;

    char buf[256], fmt[256];

    sprintf(fmt, "%%0%dd", size);

    for (int i = 0; i < np; i ++) {
      sprintf(buf, fmt, i);

      if (match(C, buf)) {
        for (int j = 0; j < np; j ++) {
          sprintf(buf, fmt, j);

          if (match(J, buf)) {
            if ((d = std::abs(i - j)) < dm) {
              im = i;
              jm = j;
              dm = d;
            }
          }
        }
      }
    }

    sprintf(fmt, "Case #%%d: %%0%dd %%0%dd\n", size, size);
    
    printf(fmt, t, im, jm);
  }
  
  return 0;
}
