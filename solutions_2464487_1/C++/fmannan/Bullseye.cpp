#include <iostream>
#include <cmath>

using namespace std;

inline double SQR(double x) { return x * x; }

int main(int argc, char ** argv) {
	int T;

	cin >> T;

	for(int tcases = 1; tcases <= T; tcases++) {
		long long r, t;
		cin >> r >> t;
		double c = sqrt(SQR(2 * r - 1) + 8 * t);
		int res = (int) ((-(2 * r - 1) + c) / 4.0);
		cout << "Case #" << tcases << ": " << res << endl;
	}
	return 0;
}