#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    double C, F, X;
    cin >> C >> F >> X;
    double g = 2;
    double r = 0;
    while (X / g > ((C / g) + (X / (g + F)))) {
      r += C / g;
      g = g + F;
    }
    r += X / g;
    printf("Case #%d: ", t);
    printf("%.10f\n", r);
  }
}