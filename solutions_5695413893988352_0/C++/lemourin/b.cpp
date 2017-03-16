#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
typedef long long int LL;
const int MAXN = 1e6;

char buffer1[MAXN], buffer2[MAXN];

int power(int a, int b) {
  int r = 1;
  for (int i = 0; i < b; i++)
    r *= a;
  return r;
}

bool match(LL t, std::string str) {
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] != '?' && t % 10 != str[i] - '0')
      return false;
    t /= 10;
  }
  return true;
}


std::string to_string(LL a, int n) {
  std::string p;
  for (int i = 0; i < n; i++) {
    p += (a % 10) + '0';
    a /= 10;
  }
  std::reverse(p.begin(), p.end());
  return p;
}

std::pair<std::string, std::string> solve(std::string str1, std::string str2) {
  assert(str1.length() == str2.length());
  int n = str1.length();
  int max = power(10, n);
  int best_diff = MAXN, a = -1, b = -1;
  for (int i = 0; i < max; i++)
    for (int j = 0; j < max; j++)
      if (match(i, str1) && match(j, str2)) {
        if (std::abs(i - j) < best_diff) {
          a = i;
          b = j;
          best_diff = std::abs(i - j);
        }
      }

  return {
    to_string(a, n),
    to_string(b, n)
  };
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    scanf("%s%s", buffer1, buffer2);
    auto r = solve(buffer1, buffer2);
    printf("Case #%d: %s %s\n", i, r.first.c_str(), r.second.c_str());
  }
}
