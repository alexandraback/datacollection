#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

void solveTest()
{
	double dist;
	int n, tn;
	cin >> dist >> n >> tn;
	vector<double> x(n);
	vector<double> times(n);
	for( int i = 0; i < n; i++ ) {
		cin >> times[i] >> x[i];
	}
	for( int i = 0; i < tn; i++ ) {
		double a;
		cin >> a;
		double t0 = 0;
		double tmax = 1e20;
		while( (tmax - t0) / std::max(1.0, tmax + t0) > 1e-9 ) {
			double tmed = (tmax + t0) / 2;
			bool crush = false;
			double curT = 0;
			for( int i = 1; i < n; i++ ) {
				double xx = x[i] > dist ? dist : x[i];
				double ti = times[i-1] + (xx - x[i-1]) / (x[i] - x[i-1]) * (times[i] - times[i-1]);
				double tacc = tmed + sqrt(2 * xx / a);
				if( tacc < ti ) {
					crush = true;
					break;
				}
			}
			if( crush ) {
				t0 = tmed;
			} else {
				tmax = tmed;
			}
		}
		cout << setprecision(9) << sqrt(2 * dist / a) + tmax << endl;
	}
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tn = 0;
	cin >> tn;
	for( int tc = 1; tc <= tn; tc++ ) {
		cerr << "case" << tc << endl;
		cout << "Case #" << tc << ":" << endl;
		solveTest();
	}
	return 0;
}
