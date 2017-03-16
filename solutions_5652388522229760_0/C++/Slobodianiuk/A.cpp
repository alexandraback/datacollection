#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

long long solve(const long long &n) {
  long long ret = 0;
  set<int> digits;
  for (int d = 0; d < 10; ++d) {
    digits.insert(d);
  }
  while (digits.size() > 0) {
    ret += n;
    long long x = ret;
    while(x > 0) {
      int dig = x % 10;
      digits.erase(dig);
      x /= 10;
    }
  }
  return ret;
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    long long n;
    cin >> n;
    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", line+1);
    } else {
      long long ans = solve(n);
      printf("Case #%d: %d\n", line+1, ans);
    }
  }

  return 0;
}
