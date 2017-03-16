#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 100010;

int a, b, tt;
double p[MAX];

double prob[MAX];

double solve() {
  prob[0] = 1.0;
  for (int i = 1; i <= a; i++) {
    prob[i] = prob[i-1] * p[i];
  }

  double expected = b + 2.0; // option 3

  double chars_left = b - a + 1.0; // option 1
  double finish = prob[a] * chars_left
                  + (1.0 - prob[a]) * (chars_left + b + 1);
  //printf("%lf %lf\n", expected, finish);
  if (finish < expected) {
    expected = finish;
  }

  // option 2 = backspace
  for (int i = 0; i < a; i++) {
    chars_left = b - i + 1.0;
    double backspace = (a - i)
                       + prob[i] * chars_left
                       + (1.0 - prob[i]) * (chars_left + b + 1);

    if (backspace < expected) {
      expected = backspace;
    }
  }

  return expected;
}

int main () {
  scanf("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    scanf("%d %d", &a, &b);
    //printf("%d %d\n", a, b);
    for (int i = 1; i <= a; i++) {
      scanf("%lf", &p[i]);
      //printf("%lf\n", p[i]);
    }

    printf("Case #%d: %lf\n", t, solve());
  }

  return 0;
}
