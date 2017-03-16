#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas) {
    cout << "Case #" << cas << ": ";
    double c, f, x;
    cin >> c >> f >> x;
    cout.setf(ios::fixed);
    cout.precision(7);
    double minim = x/2;
    double aux = 0;
    for (int N = 1; N < x/c + 0.5; ++N) {
      aux += c/(2 + (N - 1)*f);
      double act = aux + x/(2 + N*f);
      if (act < minim) minim = act;
      else break;
    }
    cout << minim << endl;
  }
}
