#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int test;
  cin >> test;
  for (int t = 1; t <= test; t++) {
    double c, f, x;
    cin >> c >> f >> x;

    double build_time = 0, res = x;
    for (int build = 0; build <= x / c; build++) {
      double rate = 2.0 + f * build;
      res = min(res, build_time + x / rate);
      build_time += c / rate;
    }
    cout.precision(10);
    cout  << "Case #" << t << ": " << fixed <<  res << endl;
  }

  return 0;
}
