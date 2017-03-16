#include <bits/stdc++.h>
using namespace std;

#define int long long
int divisor(int x) {
  for (int i = 2; i <= (int) sqrt(x); ++i) {
    if (x % i == 0)
      return i;
  }
  return -1;
}

#undef int
int main() {
#define int long long
  int T;
  cin >> T;
  int N, J;
  cin >> N >> J;
  printf("Case #1:\n");
  for (int i = 0; i < (1 << N-2) && J; ++i) {
    string s(N, '1');
    for (int j = 0; j < N-2; ++j) {
      if (!((1 << j) & i))
        s[j+1] = '0';
    }
    bool good = true;
    vector<int> divs;
    for (int j = 2; j <= 10; ++j) {
      int v = strtoll(s.c_str(), nullptr, j);
      int d = divisor(v);
      if (d == -1)
        good = false;
      divs.push_back(d);
    }
    if (!good)
      continue;
    printf("%s", s.c_str());
    for (auto x : divs) {
      printf(" %lld", x);
    }
    printf("\n");
    J--;
  }
}