#include <gmpxx.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "shelly.hpp"

using namespace std;
using namespace shelly;

double solve(double C, double F, double X, int i) {
  double res = 0, rate = 2;
  int k = 0;
  while (i > 0) {
    res += C / rate;
    rate += F;
    i--;
  }
  res += X / rate;
  return res;
}

int binary_search(double C, double F, double X, int l, int h) {
  assert(l < h);
  if (h - l == 1) {
    if (solve(C, F, X, h) > solve(C, F, X, l))
      return l;
    return h;
  }
  int m = (h - l) / 2 + l;
  if (solve(C, F, X, m + 1) < solve(C, F, X, m))
    return binary_search(C, F, X, m, h);
  return binary_search(C, F, X, l, m);
}

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    double C, F, X;
    cin >> C >> F >> X;

    double best = INT64_MAX;
    int r = binary_search(C, F, X, 0, 100000);
    best = solve(C, F, X, r);
    cout.precision(8);
    cout << "Case #" << TT <<": " << fixed << best << endl;
  }
  return 0;
}
