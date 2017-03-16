#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		int n;
		cin >> n;
		vector<int> s(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
			sum += s[i];
		}
		vector<double> a(n);
		for (int i = 0; i < n; ++i) {
			double lo = 0.0;
			double hi = 1.0;
			while (hi - lo > 1e-9) {
				double mid = (hi + lo) / 2;
				double sj = mid;
				for (int j = 0; j < n; ++j) {
					if (i == j) {
						continue;
					}
					double yj = max(0.0, mid + (s[i] - s[j])*1.0/sum);
					sj += yj;
					if (sj >= 1.0) {
						break;
					}
				}
				if (sj >= 1.0) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
			a[i] = hi;
		}
		cout.precision(6);
		cout << fixed;
		cout << "Case #" << test << ":";
		for (int i = 0; i < n; ++i) {
			cout << " " << a[i]*100;
		}
		cout << endl;
	}
}
