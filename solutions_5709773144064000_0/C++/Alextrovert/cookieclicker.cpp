#include <iostream>
#include <fstream>
using namespace std;

int T;
double C, F, X;

int main() {
  ifstream cin("B-small-attempt0.in");
  ofstream cout("B-small-attempt0.out");

  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> C >> F >> X;
    double cookies = 0, rate = 2, t = 0;
    while (true) {
      //time until next farm buyable
      double dt_f = (C - cookies) / rate;
      //time until we reach X cookies
      double dt_x = (X - cookies) / rate;
      if ((dt_f + X/(rate + F)) < dt_x) {
        cookies = 0;
        rate += F;
        t += dt_f;
      } else {
        t += dt_x;
        break;
      }
    }
    cout.precision(12);
    cout << "Case #" << Case << ": ";
    cout << fixed << t << "\n";
  }
  return 0;
}
