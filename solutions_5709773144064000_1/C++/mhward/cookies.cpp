#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// problem case specific values
double F, C, X, b = 2;

int main() {

	int k;
	cin >> k;

	// iterate through cases	
	for (int i = 1; i <= k; ++i) {

		cin >> C >> F >> X;

		// dp table
		// getDP[i] is the min time to get i factories
		vector<double> getDP;
		// base case is at t=0
		getDP.push_back(0);

		double last = X / b;

		while (true) {

			int f = getDP.size()-1;

			// calculate the cost of the next factory
			getDP.push_back( getDP[f] + C / (F*f + b) );
			++f;
			double curr = getDP[f] + X / (F*f + b);

			// check if hill climbing is finished
			if (curr > last) {
				printf("Case #%d: %.8f\n", i, last);
				break;
			}
			else {
				last = curr;
			}


		}
	}

	return 0;
}


