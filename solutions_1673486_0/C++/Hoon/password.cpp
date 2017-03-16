#include <iostream>
#include <cmath>

double p[100000];

using namespace std;
int main() {
  int N; cin >> N;
  for (int i = 1; i <= N; i++) {
    int A, B; cin >> A >> B;
    for (int j = 1; j <= A; j++) cin >> p[j];

    double ans = B + 2; 
    for (int k = 1; k <= A; k++) {
      double t1, t2, t3;
      t1 = B - k + A - k + 1;
      t2 = B - k + A - k + 1 + B + 1;
      t3 = B - k + A - k + 1 + B + 1;
      for (int kk = 1; kk <= k; kk++) {
        t1 *= p[kk];
        t3 *= p[kk];
      } 
      double ans2 = t1 + t2 - t3;
      ans = min(ans, ans2);
    }
    printf("Case #%d: %.6f\n", i, ans);
  }
}
