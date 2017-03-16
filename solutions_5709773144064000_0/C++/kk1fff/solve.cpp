#include <iostream>
#include <fstream>

using namespace std;

void run(istream& in, int T) {
  double C, F, X;
  in >> C >> F >> X;
  // cout << "C: " << C << " F: " << F << " X: " << X << endl;
  double k = 2.; // init speed
  double t2w = 0;
  while (1) {
    double Tb, Tw;
    Tb = C/k + X/(k + F);
    Tw = X/k;

    if (Tw <= Tb) {
      t2w += Tw;
      break;
    } else {
      // cout << "buy: " << k << "->" << k + F << " cost: " << C/k << endl;
      t2w += C/k;
      k += F;
    }
  }
  cout.precision(11);
  cout << "Case #" << T << ": " << t2w << endl;
}

int main () {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    run(cin, i + 1);
  }
}
