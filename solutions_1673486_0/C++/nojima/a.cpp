#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double p[100010];
double p_correct[100010];

int main() {
  int T; scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int A, B; scanf("%d%d", &A, &B);
    for (int i = 0; i < A; ++i) { scanf("%lf", p+i); }

    p_correct[0] = log(p[0]);
    for (int i = 1; i < A; ++i) { p_correct[i] = p_correct[i-1] + log(p[i]); }
    for (int i = 0; i < A; ++i) { p_correct[i] = exp(p_correct[i]); }
    double e_keep = p_correct[A-1]*(B-A+1) + (1-p_correct[A-1])*(2*B-A+2);
    double e_enter = B + 2;
    double e_backspace = HUGE_VAL;
    for (int i = 1; i < A; ++i) {
      e_backspace = min(e_backspace,
          p_correct[A-i-1]*(B-A+2*i+1) + (1-p_correct[A-i-1])*(2*B-A+2*i+2));
    }
    printf("Case #%d: %f\n", t, min(e_keep, min(e_enter, e_backspace)));
  }
}
