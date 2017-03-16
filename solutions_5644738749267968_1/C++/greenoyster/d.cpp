#include <stdio.h>
#include <algorithm>
#include <deque>

using std::sort;
using std::deque;

int cheat(double* x, double* y, int n) {
  deque<double> v(y, y+n);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (x[i] > v.front()) {
      ++ret;
      v.pop_front();
    } else {
      v.pop_back();
    }
  }
  return ret;
}

int no_cheat(double* x, double* y, int n) {
  deque<double> v(y, y+n);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    bool matched = false;
    for (deque<double>::iterator it = v.begin(); it != v.end(); ++it) {
      if (*it > x[i]) {
        // printf("%lf %lf\n", x[i], *it);
        v.erase(it);
        matched = true;
        break;
      }
    }
    if (!matched) {
      // printf("%lf %lf\n", x[i], v.front());
      ++ret;
      v.pop_front();
    }
  }
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int N = 1; N <=T; ++N) {
    int n;
    double x[1000], y[1000];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%lf", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%lf", &y[i]);
    }
    sort(x, x+n);
    sort(y, y+n);
    printf("Case #%d: %d %d\n", N, cheat(x, y, n), no_cheat(x, y, n));
  }
  return 0;
}
