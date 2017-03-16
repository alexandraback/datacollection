#include <iostream>
#include <iomanip>

using namespace std;

void run(int t) {
  double C, F, X;
  cin >> C >> F >> X;

  double p = 2.0;
  double time = 0.0;

  double result = 100000;
  double last = result;
  while (true) {
    double next = time + X / p;
    result = min(result, next);
    if (next > last) break;

    last = next;
    time += C / p;
    p += F;
  }

  cout << "Case #" << t << ": " << result << endl;
}

int main() {
  cout << setprecision(7) << fixed;
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    run(t);
  }
}
