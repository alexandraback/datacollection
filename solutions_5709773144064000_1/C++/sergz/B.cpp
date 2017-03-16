#include <iostream>

using namespace std;

int
main() {
  int T;

  cin >> T;

  cout.precision(7);
  cout.setf(std::ios::fixed);
  for(int i = 1; i <= T; i++) {
    double C, F, X, p = 2.0, t, tmin;

    cin >> C >> F >> X;

    t = X/p;
    do { 
      tmin = t;
      t = tmin + X/(p+F) + (C-X)/p;
      p += F;
    } while(t < tmin);

    cout << "Case #" << i << ": " << tmin << endl;
  }

  return 0;
}

