#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int d;
		cin >> d;
		vector<int> p(d);
		int mp = -1;
		for (int i = 0; i < d; ++i) {
			cin >> p[i];
			if (mp == -1 || mp < p[i]) {
				mp = p[i];
			}
		}

		int best = mp;
		for (int m = 1; m < mp; ++m) {
			int sp = 0;
			for (int i = 0; i < d; ++i) {
				sp += (p[i] - 1) / m;
			}
			if (m + sp < best) {
				best = m + sp;
			}
		}
		
		cout << "Case #" << test << ": " << best << endl;
	}
}
