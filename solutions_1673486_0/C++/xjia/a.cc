#include <iostream>
#include <cstdio>
using namespace std;

double p[100010];

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B; cin >> A >> B;
    for (int i = 1; i <= A; i++) cin >> p[i];
    // keep typing
    double P_1_A = 1;
    for (int i = 1; i <= A; i++) P_1_A *= p[i];
    double e1 = P_1_A * (B+1-A) + (1-P_1_A) * (2*B-A+2);
    // enter
    double e2 = B+2;
    double e = min(e1, e2);
    // delete all
    double e3 = A+B+1;
    e = min(e, e3);
    // leave k (1 <= k <= A-1)
    double P = 1;
    for (int k = 1; k <= A-1; k++) {
      P *= p[k];
      double e4 = P * ((A-k) + (B-k) + 1) + (1-P) * ((A-k) + (B-k) + 1 + (B+1));
      e = min(e, e4);
    }
    // cout << "Case #" << t << ": " << e << endl;
    printf("Case #%d: %0.6f\n", t, e);
  }
  return 0;
}
