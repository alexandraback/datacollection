#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define ABS(X) ((X) < 0 ? -1 * (X) : (X))

double quad_p(double a, double b, double c) {
  return (-1 * b + sqrt(b * b - 4 * a * c)) / 2 / a;
}
double quad_m(double a, double b, double c) {
  return (-1 * b - sqrt(b * b - 4 * a * c)) / 2 / a;
}

long long comb(long long n, long long k) {
  if (k > n) return 0;
  long long ans = 1;
  for (long long i = 1; i <= k; i++) {
    ans *= n--;
    ans /= i;
  }
  return ans;
}

long long my_pow(long long x, long long d) {
  long long ans = 1;
  for (long long i = 0; i < d; i++) ans *= x;
  return ans;
}

long long on_level(int l) {
  return 2 * l * l - l;
}

double compute(int throws, int k) { 
  // comb / pow
  if (k > throws) return 0;

  int pows = throws;
  //cout << throws << " " << pows << endl;
  double ans = 1;
  for (long long i = 1; i <= k; i++) {
    ans *= throws--;
    ans /= i;
    while (ans > 1) {
      ans /= 2;
      pows--;
    }
  }
  //if (pows == 5) cout << ans << " " << pows << endl;
  
  if (pows > 50) return 0;
  else return ans / my_pow(2, pows);
}

int main() {
  int n_tests;
  cin >> n_tests;
  for (int i_test = 0; i_test < n_tests; i_test++) {
    int n, x, y;
    cin >> n >> x >> y;
    x = ABS(x);
    y = ABS(y);

    // figure out level
    int my_level = (x + y) / 2;
    int level = floor(quad_p(2, -1, -1 * (n - 1)));

    //printf ("me: %d and %d\n", my_level, level);

    double ans;
    if (my_level < level) ans = 1;
    else if (my_level > level) ans = 0;
    else {
      int throws = n - on_level(level);

      if (throws == 4 * (level + 1) - 3) ans = 1;
      else if (y == 2 * level) ans = 0;
      else {
        //printf ("throws: %d, y: %d\n", throws, y);

        long long sum = 0;
        //long long denom = my_pow(2, throws);
        //printf ("%d %lld\n", throws, denom);
        ans = 0;
        for (int i = 0; i <= throws; i++) {
          //cout << (i < (throws - y)) << " " << ((i - 2 * level - 1) >= y) << endl;
          if (i < (throws - y) || (i - 2 * level - 1 + (throws - i)) >= y) { 
            double frac = compute(throws, i);
            ans += frac;
          }
        }
      }
    }

    printf("Case #%d: %f\n", i_test+1, ans);
  }
}
