#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;


int main() {
  long T;

  long A, B;

  cin >> T;
  for (long i = 1; i <= T; i++) {
    cin >> A >> B;

    double prob[100001] = {0.0};

    for (int i = 1; i <= A; i++) {
      cin >> prob[i];
    }


    double s3 = B + 2;
    double s_best = pow(10.0, 10.0); // worst start

    // x = num to retype, can't be x = A.
    for (long x = 0; x < A; x++) { // num retyped
      double pr = 1.0;
      for (long j = 1; j <= A - x; j++) {
        pr *= prob[j];
      }
      double s = ((B - A + 2.0 * x + 1.0) + (B + 1.0)) * (1.0 - pr);
      s += pr * (B - A + 1.0 + 2.0 * x);

      //printf("s for x = %d: %f\n", (int) x, s);
      if (s < s_best)
        s_best = s;


    }

    double best = min(s3, s_best);

    printf("Case #%d: %.6f\n", i, best);
  }

}