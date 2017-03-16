#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B;
    cin >> A >> B;
    double best = B + 2;
    double curProb = 1;
    for (int a = 0; a < A; a++) {
      double prob;
      cin >> prob;
      curProb *= prob;
      double poss = (A - 1 - a) + (B - 1 - a) + 1 + (1 - curProb) * (B + 1);
      if (poss < best) {
        best = poss;
      }
    }
    cout.precision(8);
    cout << "Case #" << t << ": " << best << '\n';
  }
  return 0;
}
