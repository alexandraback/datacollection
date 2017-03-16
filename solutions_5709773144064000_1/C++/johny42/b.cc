#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    long double c, f, x;
    cin >> c >> f >> x;

    long double cps = 2;
    long double fact_time = 0;

    long double best = x/cps;  // without factories

    for (int build = 1; build < x+10; ++build) {
      fact_time += c/cps;
      cps += f;

      long double total_time = fact_time + x/cps;
      best = min(best, total_time);
    }

    cout << "Case #" << tt << ": ";
    printf("%.7Lf\n", best);
  }
}
