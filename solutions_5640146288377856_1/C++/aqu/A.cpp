#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long doit() {
  int R, C, W;
  cin >> R >> C >> W;
  long long res = 0;
  for (int i = 0; i < R-1; ++i) {
    res += C/W;
  }
  res += ceil(1.*C/W)+W-1;
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    printf("Case #%d: %lld\n", t, doit());
  }
}
