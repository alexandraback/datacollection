#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double p[100100];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int a, b; cin >> a >> b;
    for (int i = 0; i < a; i++) cin >> p[i];

    double pr = 1, best = 1000000000;
    for (int i = 0; i <= a; i++) {
      best = min(best, pr * (a-i + b-i + 1) + (1 - pr) * (a-i + b-i + b + 2));
      pr *= p[i];
    }
    best = min(best, b + 2.0);

    cout << fixed << setprecision(8) << "Case #" << c << ": " << best << endl;
  }
  return 0;
}
