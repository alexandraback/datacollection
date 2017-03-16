#include <iostream>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    double C, F, X; cin >> C >> F >> X;
    double best = 1e99;
    double time = 0;
    double rate = 2;
    for (int farms = 0; ; farms++) {
      if (time + X/rate < best) {
        best = time + X/rate;
      } else {
        printf("Case #%d: %.7lf\n", t, best);
        break;
      }
      time += C / rate;
      rate += F;
    }
  }
}
