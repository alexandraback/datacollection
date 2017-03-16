#include <iostream>
#include <string>

using namespace std;

const int N = 100000;

double p[N];

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    int a, b; cin >> a >> b;
    p[0] = 1;
    for (int i = 1; i <= a; i++) {
      double pp; cin >> pp;
      p[i] = p[i-1] * pp;
    }

    double res = ((b-a) + 1) + (1-p[a]) * (b+1);
    res = min(res, 2.0 + b);
    for (int i = 0; i < a; i++) {
      double presses = (a-i) + (b+1-i) + (1-p[i]) * (b+1);
      res = min(res, presses);
    }

    printf("Case #%d: %.6lf\n", caseNo, res);
  }
  return 0;
}

