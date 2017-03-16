#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calc(const vector<pair<double, double> >& positions,
            double acceleration,
            double D) {

	if (positions.size() == 1 || positions[0].second >= D) {
		return sqrt(D/(0.5*acceleration));
	}
	else {
		double free = sqrt(D/(0.5*acceleration));
		
		double carspeed = (positions[1].second-positions[0].second)/
			(positions[1].first-positions[0].first);

		double cartime = (D-positions[0].second)/carspeed;

		return max(cartime, free);
	}
}

void handle_case(int case_nbr) {
	cout << "Case #" << case_nbr << ":" << endl;

	double D;
	int N, A;
	cin >> D >> N >> A;
	
	vector<pair<double, double> > positions(N);
	
	for (int i = 0; i < N; i++) {
		cin >> positions[i].first >> positions[i].second;
	}

	for (int i = 0; i < A; i++) {
		double acceleration;
		cin >> acceleration;
		cout << calc(positions, acceleration, D) << endl;
	}

}

int main(void) {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		handle_case(i+1);
	}

	return 0;
}
