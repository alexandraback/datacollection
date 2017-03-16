#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int A, B;
    cin >> A >> B;
    double p = 1;
    double best = B + 2;
    for (int i = 1; i <= A; ++i) {
      double prob;
      cin >> prob;
      p *= prob;
      double keys = B + A + 1 - 2*i + (1-p)*(B+1);
      if (keys < best) best = keys;
    }
    //cout << "Case #" << t << ": " << best << endl;
    printf("Case #%d: %f\n", t, best);
  }
  return 0;
}