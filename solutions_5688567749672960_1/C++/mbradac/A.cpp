#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

int digits(llint x) {
  int ret = 0;
  while (x) {
    x /= 10;
    ++ret;
  }
  return ret;
}

llint solve(llint a, llint b) {
  assert(digits(a) == digits(b));
  string s = to_string(b);
  string s1 = string(s.begin(), s.begin() + digits(b) / 2);
  string s2 = string(s.begin() + digits(b) / 2, s.end());
  reverse(s1.begin(), s1.end());
  llint c, d;
  sscanf(s1.c_str(), "%lld", &c);
  sscanf(s2.c_str(), "%lld", &d);

  if (d == 0) {
    string s1 = string(s.begin(), s.begin() + (digits(b) + 1) / 2);
    string s2 = string(s.begin() + (digits(b) + 1) / 2, s.end());
    reverse(s1.begin(), s1.end());
    sscanf(s1.c_str(), "%lld", &c);
    sscanf(s2.c_str(), "%lld", &d);
  }
  if (d == 0) {
    return solve(a, b-1) + 1;    
  }

  llint ret = c + d;
  if (c == 1) ret -= 1;
  return ret;
}

void solve() {
  llint n;
  scanf("%lld", &n);
  int d = digits(n);

  if (d == 1) {
    printf("%lld\n", n);
    return;
  }

  llint ans = 10;
  llint pot = 10;

  for (int i = 2; i < d; ++i) {
    ans += solve(pot, pot * 10 - 1) + 1;
    pot *= 10;
  }

  if (n != pot)
    ans += solve(pot, n);
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}

