#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int z, N, A;
double D;
double t[1050], x[1050], a[1050];

double findu(double t1, double s1, double t2, double s2) {
	return (s2 - s1) / (t2 - t1);
}

double findt(double s, double a) {
	return sqrt(2.0 * s / a);
}

int main() {
	cin >> z;
	
	for (int C = 1; C <= z; C++) {
		cin >> D >> N >> A;
		
		for (int i = 0; i < N; i++)
			cin >> t[i] >> x[i];
		for (int i = 0; i < A; i++)
			cin >> a[i];
		
		printf("Case #%d:\n", C);
		
		for (int i = 0; i < A; i++) {
			if (N == 1) {	// always with the highest velocity
				printf("%.6f\n", findt(D, a[i]));
			}
			else if (N == 2) {
				double vo = findu(t[0], x[0], t[1], x[1]);
				double tofin = (D - x[0]) / (vo + 0.0);
				
				//double timet = (x[0] + 0.0) / (a[i] - (t[1] / (x[1] - x[0])));
				
				double tmp = (2 * x[0] - 2 * x[1]) / (t[1] + 0.0);
				
				double delta = sqrt(tmp * tmp + 8.0 * a[i] * x[0]);
				double t1 = (-tmp + delta) / (2.0 * a[i]);
				//double t2 = (-tmp - delta) / (2.0 * a[i]);
				double tstar = sqrt(2.0 * D / (a[i] + 0.0));
				
				if (t1 >= tstar) {	// nothing
					printf("%.6f\n", findt(D, a[i]));
				}
				else {
					//printf("%.6f\n", t1 + tofin - ((D - t1 * vo) / vo));
					printf("%.6f\n", tofin);
				}
			}
		}
	}
	
	return 0;
}
