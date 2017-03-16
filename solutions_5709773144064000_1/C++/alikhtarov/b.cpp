#include <iostream>
using namespace std;

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    double cost, extra, need;
    cin >> cost >> extra >> need;
    
    int mn = 0, mx = 1000000;

    auto solve = [&](int x) {
      double speed = 2.0;
      double t = 0.0;
      for (int i = 0; i < x; ++i) {
	t += cost/speed;
	speed += extra;
      }
      return t + need/speed;  // vroom vroom
    };

    while (mx - mn > 2) {
      auto a = (mx + mn)/2;
      if (solve(a) < solve(a + 1)) mx = a + 1;
      else mn = a;
    }

    double ans = min(solve(mn), min(solve(mn + 1), solve(mx)));

    cout.setf(ios::fixed);
    cout.precision(7);
    cout << "Case #" << ncase << ": " << ans << endl;
  }
}
