//a Hewr
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define fo(i,a,b) for (int i = a; i <= b; ++i)

const double eps = 1e-9;
const int oo = ~0u >> 2;
const int mn = 210;

int J[mn];
int X, n;

int sgn(double x){
	if (fabs(x) <= eps) return 0;
	if (x > eps) return 1;
	return -1;
}

bool legal(int p, double Y){
	double T = J[p] + X * Y, left = 1 - Y;
	fo (i, 1, n) if (i != p){
		double y = (T - J[i]) / X;
		if (sgn(y) < 0) y = 0;
		if (sgn(y - left) >= 0) return 1;
		left -= y;
	}
	return 0;
}

int main(){
	int Ca;
	cin >> Ca;
	fo (CA, 1, Ca){
		cin >> n;
		X = 0;
		fo (i, 1, n){
			cin >> J[i];
			X += J[i];
		}
		printf("Case #%d:", CA);
		fo (i, 1, n){
			double l(0), r(1), Ans(1);
			while (sgn(r - l) > 0){
				double m = (l + r) / 2;
				if (legal(i, m))
					r = m, Ans = m;
				else	l = m;
			}
			printf(" %.6f", Ans * 100);
		}
		printf("\n");
	}
}
