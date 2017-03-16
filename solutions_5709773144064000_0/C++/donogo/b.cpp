#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

double solve(double C, double F, double X) {
  double x, xold;
  double f0 = 2;
  double harm;
  int k, mink;

  k = 0;
  mink = 0;
  x = xold = X / f0;
  harm = 1/f0;
  //  cout << k << ":" << x << endl;

  for (k = 1; ; k++) {
    x = X / (f0 + k * F) + C * harm;
    //    cout << k << ":" << x << endl;
    if (x > xold) break;
    xold = x;
    mink = k;
    harm = harm + 1/(f0 + k * F);
  }
  return xold;

}

double solve2(double C, double F, double X) {
  double x1, x2, x, xold, harm, f0;
  int i, mink, k;

  f0 = 2;
  k = floor(X - C * f0 / F - 1);

  if (k < 0) {
    mink = 0;
    x = X / f0;
  } else {
    harm = 0;

    for (i = k; i >= 0; i--) {
      harm += 1/(f0 + i * F);
    }

    x1 = X / (f0 + (k+1)*F)  + C*harm;

    harm = 0;
    for (i = k-1; i >= 0; i--) {
      harm += 1/(f0 + i * F);
    }
    x2 = X / (f0 + k*F)  + C*harm;

    if (x1 < x2) {
      mink = k+1;
      x = x1;
    } else {
      x = x2;
      mink = k;
    }
  }
  //  cout << mink << ":" << x << endl;
    
  return x;

}




int main(void) {
  int T, t;
  double C, F, X, x;

  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> C;
    cin >> F;
    cin >> X;
    x = solve(C, F, X);
    printf( "Case #%d: %15.7f\n", t, x);
  }


  return 0;
}
