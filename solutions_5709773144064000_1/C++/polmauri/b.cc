#include <iostream>
using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(7);
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    double c, f, x;
    cin >> c >> f >> x;
    double best = x/2.0;
    double a = 0.0;
    for (int n = 0; true; ++n) {
      a += c/(2.0 + n*f);
      double t = a + x/(2.0 + (n + 1)*f);
      if (t < best) best = t;
      else break;
    }
    cout << "Case #" << cas << ": " << best << endl;
  }
}
