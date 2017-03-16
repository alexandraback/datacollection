#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

double solve(double C, double F, double X) {
	double s = 0.0;
	double r = 2.0;
	double p = (1<<29);
	for (int i = 0;; i++) {
		double t = s + X/r;
		if (t > p)
			return p;
		s += C/r;
		r += F;
		p = t;
	}
}

int main() {
	int T;
	cin >> T;
	cout.precision(14);
	for (int i = 0; i < T; i++) {
		double C, F, X;
		cin >> C >> F >> X;
		double ans = solve(C, F, X);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
