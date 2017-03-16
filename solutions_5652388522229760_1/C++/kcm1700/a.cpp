#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; testcase++)
  {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", testcase);
      continue;
    }
    set<char> digits;
    long long ans = n;
    for (long long i = 1; ; i++) {
      auto s = to_string(ans = i*n);
      for (auto d : s) digits.insert(d);
      if (digits.size() == 10)
        break;
    }
    printf("Case #%d: %lld\n", testcase, ans);
  }
  return 0;
}