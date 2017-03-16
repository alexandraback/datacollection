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

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    double C, F, X;
    cin >> C >> F >> X;

    double best = INT64_MAX;
    for (int i = 0; i <= 2000; i++) {
      best = min(solve(C, F, X, i), best);
    }
    cout.precision(8);
    cout << "Case #" << TT <<": " << fixed << best << endl;
  }
  return 0;
}
