#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	double T,N,x;
	cin >> T;
	for ( int i = 1; i <= T; i++ ) {
		cin >> N;
		vector<double> number;
		double sum = 0.0;
		for ( int j = 0; j < N; j++ ) {
			cin >> x;
			number.push_back(x);
			sum+=x;
		}
		// sum has sum of all the numbers;
		double f,dsum,dN;
		double avg;
		dsum = sum;dN= N;
		cout << "Case #" << i << ": ";
		for ( int j = 0; j < N; j++) {
			f = 2.0*sum - number[j]*N;
			if ( f < 0.0 ) {
				dsum = dsum - number[j];
				dN--;
			}
		}
		avg = dN * sum;
		for ( int j = 0; j < N; j++ ) {
			f = (dsum + sum) - number[j]*dN;
			f = f/avg;f = f*100.0;
			if ( f < 0.0 ) {
				f = 0.0;
			}
			printf("%.6f ",f);
		}
		cout << endl;
	}
}