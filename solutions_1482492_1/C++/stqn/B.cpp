#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int T;
  cin >> T;
  for (int c = 1; c <= T; ++c) {
    double D;
    int N, A;
    cin >> D >> N >> A;
    vector<double> t(N), x(N);
    for (int i = 0; i < N; ++i)
      cin >> t[i] >> x[i];
    vector<double> a(A);
    for (int i = 0; i < A; ++i)
      cin >> a[i];
    cout << "Case #" << c << ':' << endl;
    for (int i = 0; i < A; ++i) {
      bool flg = false;
      double ans = sqrt(2.0 * D / a[i]);
      for (int j = 1; j < N; ++j) {
        double v = (x[j] - x[j - 1]) / (t[j] - t[j - 1]);
        if (!flg && x[j] >= D) {
          flg = true;
          double _ans = t[j] - (x[j] - D) / v;
          ans = max(ans, _ans);
        }
        else {
          v = max(v, sqrt(2.0 * a[i] * x[j]));
          double _ans =
            (sqrt(v * v + 2.0 * a[i] * (D - x[j])) - v) / a[i] + t[j];
          ans = max(ans, _ans);
        }
      }
      printf("%.8f\n", ans);
    }
  }

  return 0;

}
