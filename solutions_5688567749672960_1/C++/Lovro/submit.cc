#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
typedef long long int64;
#define ALL(x) (x).begin(), (x).end()

string reversed(string s) {
  reverse(ALL(s));
  return s;
}

int64 solve(int64 n) {
  int64 ans = 1;
  while (n > 1) {
    if (n % 10 == 0) {
      --n;
      ++ans;
    }

    int64 next;
    {
      string str = to_string(n);
      str[0] = '1';
      fill(str.begin() + 1, str.end(), '0');
      next = stoll(str);
    }

    int64 best = n - next;
    string str = to_string(n);
    for (int i=str.size()-1; i>0; --i) {
      str[i] = i < (int)str.size()-1 ? '0' : '1';
      int64 cost =
                   (n - stoll(str)) + (stoll(reversed(str)) - next) + 1;
      makemin(best, cost);
    }
    ans += best;
    n = next;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int64 n;
    cin >> n;
    printf("Case #%d: %lld\n", tt, solve(n));
  }
}
