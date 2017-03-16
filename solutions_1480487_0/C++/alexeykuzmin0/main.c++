#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int n;
    cin >> n;
    vector<double> y(n);
    double x = 0.0;
    for (int i = 0; i < n; ++i)
    {
      cin >> y[i];
      x += y[i];
    }
    cout << "Case #" << t << ": ";
    double val = 2.0 * x / n;
    double rem = x;
    vector<double> z(y);
    sort(z.begin(), z.end());
    z.push_back(1e100);
    for (int i = 0; i < n; ++i)
    {
      double add = min(rem / (i + 1), z[i + 1] - z[i]);
      rem -= add * (i + 1);
      z[i] += add;
      if (add > 0.0)
      {
        val = z[i];
      }
    }
    for (int i = 0; i < n; ++i)
    {
      cout << max(0.0, val - y[i]) / x * 100 << ' ';
    }
    cout << "\n";
  }
  return 0;
}
