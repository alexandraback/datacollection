#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

double prob[100001] = {0.0};
int T;

int A, B;

int i, j, x;

double s_best;

double pr;

double s;

int main() {
  scanf("%d", &T);

  for (i = 1; i <= T; i++) {
    scanf("%d", &A);
    scanf("%d", &B);

    for (j = 1; j <= A; j++) {
      cin >> prob[j];
    }

    s_best = 100000000.0; // worst start

    // x = num to retype, can't be x = A.
    for (x = 0; x < A; x++) { // num retyped
      pr = 1.0;
      for (j = 1; j <= A - x; j++) {
        pr *= prob[j];
      }
      s = ((B - A + 2.0 * x + 1.0) + (B + 1.0)) * (1.0 - pr) + pr * (B - A + 1.0 + 2.0 * x);

      //printf("s for x = %d: %f\n", (int) x, s);
      if (s < s_best)
        s_best = s;


    }

    double best = min(B + 2.0, s_best);

    printf("Case #%d: %.6f\n", i, best);
  }

}