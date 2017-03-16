#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    int d1, m1, d2, m2;
    for(int i = 0; i < n; i++) {
      int d, h, m; cin >> d >> h >> m;

      if(h == 2) { d1 = d2 = d; m1 = m; m2 = m + 1; }
      else if(i == 0) { d1 = d; m1 = m; }
      else { d2 = d; m2 = m; }
    }

    if(m1 < m2) { // h2 should be always faster
      int tmp = m1; m1 = m2; m2 = tmp;
      tmp = d1; d1 = d2; d2 = tmp;
    }

    double v1 = 360 / (double) m1;
    double v2 = 360 / (double) m2;

    // cerr << "1: d=" << d1 << ",m=" << m1 << ",v=" << v1 << endl;
    // cerr << "2: d=" << d2 << ",m=" << m2 << ",v=" << v2 << endl;

    double t1 = (360 - d1) / v1;
    double x2 = d2 + v2 * t1;

    // cerr << "2: t1=" << t1 << ",x2=" << endl;

    int res = x2 >= 720 ? 1 : 0; 
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
