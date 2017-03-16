#include <cstdio>
#include <iostream>

using namespace std;

double p[100000];
double q[100000];

int main() {
  int T; scanf("%d\n", &T);
  for (int tt = 1; tt <= T; ++tt) {
  	int a, b; scanf("%d %d", &a, &b);
  	double r1 = 1.0, r2 = 1.0;
  	q[0] = 1;
  	for (int i = 0; i < a; ++i) {
  		scanf("%lf", &p[i]);
  		q[i + 1] = q[i] * p[i];
  		r1 *= p[i];
  		r2 *= 1 - p[i];
  	}
  	double p1 = r1 * (b - a + 1) + (1 - r1) * (b - a + 1 + b + 1);
  	double p2 = b + 2;
  	double R = p1;
  	if (p2 < R) R = p2;
  	for (int i = 1; i <= a; ++i) {
  		double r = q[a - i] * (i + b - (a - i) + 1) + (1 - q[a - i]) * (i + b - (a - i) + 1 + b + 1);
  		if (r < R) R = r;
  	}
    printf("Case #%d: %.7lf\n", tt, R);
  }
  return 0;
}

