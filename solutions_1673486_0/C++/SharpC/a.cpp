#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main()
{
	int tests;
	cin >> tests;
	cout.precision(20);
	for (int test = 1; test <= tests; ++test) {
		double result = numeric_limits<double>::max();
		int a, b;
		cin >> a >> b;
		vector<double> p(a);
		for (int i = 0; i < a; ++i) {
			cin >> p[i];
		}
		vector<double> q(a + 1);
		q[0] = 1.0;
		for (int i = 1; i <= a; ++i) {
			q[i] = q[i - 1] * p[i - 1];
		}
		result = min(result, ((b - a) + 1) + (1 - q[a]) * (b + 1));
		result = min(result, 1.0 + b + 1);
		for (int i = 0; i < a; ++i) {
			result = min(result, ((a - i) + (b - i) + 1) + (1 - q[i]) * (b + 1));
		}
		cout << "Case #" << test << ": " << result << endl;
	}
}
