#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void solve() {
  int N;
  const int MAXN = 210;
  int s[MAXN];
  scanf("%d", &N);
  int S = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &s[i]);
    S += s[i];
  }
  double mean = S * 2.0 / N;
  for (int i = 0; i < N; ++i) {
    double low = 0.0, high = 100.000000;
    double mid = 0.0;
    while (low + 0.0000001 < high) {
      mid = (low + high) / 2;
      double point = s[i] + mid / 100 * S;
      double t = 0.0;
      for (int k = 0; k < N; ++k) 
        if (k != i) {
          t += max(0.0, (point - s[k]) / S);
        }
      if (t * 100 + mid > 100) {
        high = mid;
      } else {
        low = mid;
      }
    }
    printf(" %.7lf", mid);
  }
  printf("\n");
}

int main() {
  int runs;
  scanf("%d", &runs);
  for (int i = 1; i <= runs; ++i) {
    printf("Case #%d:", i);
    solve();
  }
  return 0;
}
