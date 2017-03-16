#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int d;
    cin >> d;
    vector<int> p(d);
    int pmax = 0;
    for (int i = 0; i < d; ++i) {
      cin >> p[i];
      pmax = max(pmax, p[i]);
    }
    int best = pmax;
    for (int eat = 1; eat < pmax; ++eat) {
      int cur = eat;
      for (int i = 0; i < d; ++i) {
        cur += (p[i] + eat - 1) / eat - 1;  // p[i] > 0.
      }
      if (cur < best) {
        best = cur;
      }
    }
    cout << "Case #" << ca << ": " << best << endl;
  }
}

