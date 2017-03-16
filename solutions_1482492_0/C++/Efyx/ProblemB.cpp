// Google Code Jam 2012
// Problem B. Out of Gas

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

inline double square(double x) {
	return x*x;
}

double calculate_best_time(double D, vector< pair<double, double> > &tx, double acc) {
	double T = sqrt(2*D/acc);
	double departure = 0;
	for(size_t i=0; i<tx.size(); i++) {
		double ti = tx[i].first;
		double xi = tx[i].second;

		if(xi > D) {
			if(i==0) break;
			if(tx[i-1].second >= D) break;

			// calculate time car arrives at D
			ti = ti + (ti-tx[i-1].first)/(xi-tx[i-1].second)*(D-xi);
			xi = D;
		}

		if(ti < departure) cout << "Error?" << endl;
		double position = 0.5*acc*square(ti-departure);

		if(position > xi) {
			// gone ahead of other car
			departure = ti - sqrt(2*xi/acc);
		}
	}

	return T + departure;
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;
	for(int t=0; t<T; t++)
	{
		double D;
		cin >> D;
		int N, A;
		cin >> N >> A;

		vector< pair<double, double> > tx(N);
		for(int n=0; n<N; n++) {
			cin >> tx[n].first >> tx[n].second;
		}

		cout << "Case #" << t+1 << ":" << endl;

		for(int a=0; a<A; a++) {
			double acc;
			cin >> acc;

			cout << fixed << setprecision(7)<< calculate_best_time(D, tx, acc) << endl;
		}
	}

	return 0;
}