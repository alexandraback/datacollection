#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N, M; cin >> N >> M;

    double p = 1.0;
    double res = M + 2;
    for(int i = 1; i <= N; i++) {
      double x; cin >> x;
      p *= x;
      res = min(res, 1 + 2 * (N - i) + (M - N) + (1 - p) * (M + 1));
    }
    printf("Case #%d: %.6f\n", t, res);
  }
}
