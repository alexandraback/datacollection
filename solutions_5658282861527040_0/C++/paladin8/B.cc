#include <iostream>
#include <cmath>
using namespace std;

int x[32], y[32], z[32];
long long dp[32][2][2][2];

long long solve(int i, int xu, int yu, int zu) {
  if (i == -1) return xu * yu * zu;
  if (dp[i][xu][yu][zu] >= 0) return dp[i][xu][yu][zu];

  long long res = 0;
  for (int j = 0; j <= max(x[i], xu); j++)
    for (int k = 0; k <= max(y[i], yu); k++) {
      if (zu == 1 || j * k <= z[i]) {
        res += solve(i - 1, xu || (j < x[i]), yu || (k < y[i]), zu || (j * k < z[i]));
      }
    }
  return dp[i][xu][yu][zu] = res;
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    long long a, b, k; cin >> a >> b >> k;
    for (int i = 0; i < 32; i++) {
      x[i] = a % 2; a /= 2;
      y[i] = b % 2; b /= 2;
      z[i] = k % 2; k /= 2;
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          for (int l = 0; l < 2; l++)
            dp[i][j][k][l] = -1;
    }
    cout << "Case #" << c << ": " << solve(31, 0, 0, 0) << endl;
  }
  return 0;
}
