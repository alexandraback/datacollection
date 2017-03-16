#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

long double T[3000], X[3000];

int main () {
  int tc;
  scanf ("%d", &tc);
  for (int tn = 1; tn <= tc; tn++) {
    long double D;
    int N, A;
    scanf ("%Lf%d%d", &D, &N, &A);
    for (int i = 0; i < N; i++) {
      scanf ("%Lf%Lf", &T[i], &X[i]);
    }
    printf ("Case #%d:\n", tn);
    for (int j = 0; j < A; j++) {
      long double C;
      scanf ("%Lf", &C);
      long double x = 0, v = 0, t = 0;
      for (int i = 0; i < N; i++) {
	//printf ("%d: %Lf (of %Lf) %Lf %Lf\n", i, x, D, v, t);
	assert (x < D);
	long double nx = X[i], nt = T[i], cv;
	if (nx >= D) {
	  nx = D;
	  nt = (i == 0) ? 0 : ((T[i] - T[i - 1]) / (X[i] - X[i - 1]) * (D - X[i - 1]) + T[i - 1]);
	  cv = 0;
	} else {
	  cv = (X[i + 1] - X[i]) / (T[i + 1] - T[i]);
	}
	long double XB = v;
	long double XA = C * .5;
	long double XC = x - nx;
	//printf ("--> %Lf %Lf %Lf\n", XA, XB, XC);
	assert (XC <= 0);
	long double XD = XB * XB - 4 * XA * XC;
	long double ct = (-XB + sqrtl (XD)) / C;
	//printf ("XD = %.20Lf, ct = %.20Lf\n", XD, ct);
	assert (ct >= 0);
	x = nx;
	if (t + ct >= nt * (1-1e-14)) {
	  v += C * ct;
	  t += ct;
	} else {
	  v = min (cv, v + C * ct);
	  t = nt;
	}
	if (x == D) break;
      }
      printf ("%.20Lf\n", t);
    }
  }
  return 0;
}
