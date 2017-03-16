#include <iostream>
#include <cstdio>

using namespace std;

double p[100000];

int main() {
  int tc_cnt;
  cin >> tc_cnt;
  for (int tc = 1; tc <= tc_cnt; tc++) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
      cin >> p[i];
    }
    
    double best = (double) (b + 2);
    for (int bsp = 0; bsp <= a; bsp++) {
      double no_err = 1.0;
      for (int i = 0; i < a - bsp; i++) {
        no_err *= p[i];
      }
      double ev = no_err * ((double) b - a + 2*bsp + 1)
                + (1.0 - no_err) * ((double) b - a + 2*bsp + 1 + b + 1);
      if (ev < best) {
        best = ev;
      }
    }
    
    cout << "Case #" << tc << ": ";
    printf("%.6f", best);
    cout << endl;
  }
  
  return 0;
}
