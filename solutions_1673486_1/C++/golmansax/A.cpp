#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

using namespace std;

int main() {
  int n_test;
  cin >> n_test;
  for (int i_test = 0; i_test < n_test; i_test++) {
    int a, b;
    cin >> a >> b;

    double ans = b + 2;
    double p_right = 1;
    for (int i = 0; i <= a; i++) {
      if (i > 0) {
        double p;
        cin >> p;
        p_right *= p;
      }
      double result = 2*(a-i) + b-a+1 + (1-p_right)*(b+1);
      ans = MIN (ans, result);
      //printf ("%f %f %f\n", p_right, result, ans);
    }
    printf ("Case #%d: %.6f\n", i_test+1, ans);
  }
}
