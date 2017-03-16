#include <iostream>

#define EPSILON 0.0000000001

using namespace std;

int s[200];

int main() {
  int t; cin >> t;
  for (int ii = 1; ii <= t; ++ii) {
    printf("Case #%d:", ii);

    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      sum += s[i];
    }

    for (int i = 0; i < n; ++i) {
      double low = 0.0;
      double high = 1.0;
      while (low + EPSILON < high) {
        double mid = (low + high) / 2;
        double goal = s[i] + mid * sum;
        double left = 1.0 - mid;
        for (int j = 0; j < n; ++j) {
          if (i == j) continue;
          double curr = s[j];
          if (curr >= goal) continue;
          left -= (goal - curr) / sum;
        }
        if (left <= 0) // good
          high = mid;
        else
          low = mid;
      }
      printf(" %f", low * 100);
    }

    printf("\n");
  }
  return 0;
}