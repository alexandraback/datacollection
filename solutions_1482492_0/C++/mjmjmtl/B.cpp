// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

struct Nod {
	double t, x;
} nods[2010];
double D;
int N, A;

double testA() {
	double a;
	scanf("%lf", &a);

	double v0 = 0;
	double s0 = 0;

	for(int i = 1; i < N; i ++) {
		double ta = nods[i-1].t;
		double tb = nods[i].t;
		double xa = nods[i-1].x;
		double xb = nods[i].x;

		v0 = min(v0, (xb-xa)/(tb-ta));

		double t = tb-ta;
		if(s0 + v0*t+0.5*a*t*t <= xb) {
			if(i==N-1) {
				return ta + 
					(-v0+sqrt(v0*v0-4*s0/2*a))/2
					;
			}
			v0 = v0 + a * t;
			s0 = s0 + v0*t+0.5*a*t*t;
		} else {
			if(i == N-1) {
				return nods[i].t;
			}
			double tmpV0 = (xb-s0-0.5*a*t*t) / t;
			if(tmpV0 >= 0) {
				v0 = tmpV0 + a * t;
			} else {
				double tmpT = sqrt( 2*(xb-s0)/a  );
				v0 = a * tmpT;
			}
			s0 = xb;
		}
	}





}

void test() {
	scanf("%lf%d%d", &D, &N, &A);
	for(int i = 0; i < N; i ++) {
		scanf("%lf%lf", &nods[i].t, &nods[i].x);
	}
	if(nods[0].t != 0) {
		printf("err0\n");
	}
	if(nods[N-1].x < D) {
		printf("err!!!\n");
	}
	for(int i = 0; i < N; i ++) {
		if(nods[i].x >= D) {
			if(i == 0) {
			} else {
				double ta = nods[i-1].t;
				double tb = nods[i].t;
				double xa = nods[i-1].x;
				double xb = nods[i].x;
				nods[i].t = (D-xa)*(tb-ta)/(xb-xa) + ta;
			}
			nods[i].x = D;
			N = i+1;
			break;
		}
	}
	for(int i = 0; i < A; i ++) {
		printf("%.12f\n",testA());
	}
}

int _tmain(int argc, _TCHAR* argv[]) {

	freopen("B-small-attempt0 (1).in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int idx = 1; idx <= t; idx ++) {
		printf("Case #%d:\n", idx);
		test();
	}
	return 0;
}

