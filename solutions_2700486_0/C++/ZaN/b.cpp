#include <iostream>
#include <vector>
using namespace std;

const int maxn = 500;
double c[500][500];

int main() {
	c[0][0] = 1;
	for (int i = 1; i < maxn; ++i) {
		c[i][0] = c[i][1] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}

	cout.flags(cout.flags() | ios::fixed);
	cout.precision(6);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n, x, y;
		cin >> n >> x >> y;

		int side = 1;
		while (side*(side + 1)/2 <= n) {
			side += 2;
		}

		int num = n - (side - 2)*(side - 1) / 2;

		int tside = abs(x) + y + 1;
		if (tside < side) {
			cout << "Case #" << test << ": " << 1.0 << endl;
		} else if (tside > side || x == 0) {
			cout << "Case #" << test << ": " << 0.0 << endl;
		} else {
			double sum = 0.0;
			double bad = 0.0;
			//cout << side << " " << num << endl;
			for (int i = 0; i <= num / 2; ++i) {
				int j = num - i;
				if (j >= side) {
					continue;
				}
				//cout << num << " " << i << " " << c[num][i] << endl;
				sum += c[num][i];
				if (i < j) {
					sum += c[num][i];
				}
				if (i <= (y + 1) / 2) {
					bad += c[num][i];
				}
			}
			cout << "Case #" << test << ": " << (sum - bad) / sum << endl;
		}
	}
}
