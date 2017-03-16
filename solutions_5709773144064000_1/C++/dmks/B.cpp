#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;


double go(double C, double F, double X) {
  double ret = X / 2;
  vector<double> t(1, 0.0);
  for (int i = 1; ;i++) {
    double temp = t[i-1] + C / (F * (i - 1) + 2);
    if (temp >= ret) break;
    t.push_back(temp);
    double cur = temp + X / (F * i + 2);
    if (ret > cur) ret = cur;
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    double C, F, X;
    cin >> C >> F >> X;
    printf("Case #%d: %0.7f\n", t, go(C, F, X));
  }
  return 0;
}
