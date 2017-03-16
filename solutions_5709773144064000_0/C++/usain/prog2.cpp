#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double solve(double c, double f, double x) {
  double r = 2.0;
  double t = 0.0;

  while (x/r > (c/r + x/(r + f))) {
    t += c/r;
    r += f;
  }

  return t + x/r;
}

int main() {
  ifstream in("B-small-attempt0.in");
  ofstream out("B-small-attempt0.out");

  out << std::setprecision(7) << std::fixed;
  int tests;
  in >> tests;
  for (int i = 1; i <= tests; i++) {
    double c, f, x;
    in >> c >> f >> x;

    out << "Case #" << i << ": " << solve(c, f, x) << endl;
  }

  in.close();
  out.close();

  return 0;
}
