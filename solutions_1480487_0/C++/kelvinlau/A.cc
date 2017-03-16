#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 256;
const double EPS = 1E-9;

int n;
int s[N];

int main() {
  int T, tc = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &s[i]);
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += s[i];
    printf("Case #%d:", ++tc);
    for (int i = 0; i < n; i++) {
      double l = 0.0, r = 1.0;
      while (l + EPS < r) {
        double mid = (l + r) / 2.0;
        double need = 0.0;
        for (int j = 0; j < n; j++)
          need += max(0.0, 1.0 * (s[i] - s[j]) / sum + mid);
        if (need > 1.0)
          r = mid;
        else
          l = mid;
      }
      printf(" %.10lf", r * 100.0);
    }
    puts("");
  }
  return 0;
}
