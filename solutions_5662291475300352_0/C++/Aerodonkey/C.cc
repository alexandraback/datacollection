#include <iostream>

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;
    double d1, d2, m1, m2;
    if (n == 1) {
      double d, m;
      int h;
      std::cin >> d >> h >> m;
      d1 = d;
      d2 = d;
      m1 = m;
      m2 = m + 1;
    } else {
      int h1, h2;
      std::cin >> d1 >> h1 >> m1;
      std::cin >> d2 >> h2 >> m2;
    }
    int e = 0;
    double t = (360 - d1) * m1 / 360;
    double p2 = d2 + 360 / m2 * t;
    if (p2 < 360) {
      t = (360 - d2) * m2 / 360;
      double p1 = d1 + 360 / m1 * t;
      if (p1 < 720) {
        e = 0;
      } else {
        e = 1;
      }
    } else if (p2 < 720) {
      e = 0;
    } else {
      e = 1;
    }
    std::cout << "Case #" << i + 1 << ": " << e << std::endl;
  }
}
