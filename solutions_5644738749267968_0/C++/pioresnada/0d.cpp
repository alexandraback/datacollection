#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; ++i) {
		int n; cin >> n;
		vector<double> d, k;
		double a;
		for (int j = 0; j < n; ++j) {
			cin >> a; d.push_back(a);
		}
		for (int j = 0; j < n; ++j) {
			cin >> a; k.push_back(a);
		}
		sort(d.begin(), d.end());
		sort(k.begin(), k.end());
		int dw = 0, w = 0;
		int i1 = 0, i2 = 0, f2 = n-1;
		while (i1 < n) {
			while (i1 < n && d[i1] < k[i2]) { ++i1; --f2; }
			if (i1 < n) { ++i1; ++i2; ++dw; }
		}
		//for (int j = 0; j < n; ++j)
			//if (k[n-1-j] < d[j]) ++dw;
		for (int j = 0; j < n; ++j) {
			bool y = true;
			for (int h = 0; y && h < n; ++h)
				if (k[h])
					if (k[h] > d[j]) {
						k[h] = 0;
						y = false;
					}
			if (y) { w = n - j; break; }
		}
		cout << "Case #" << i+1 << ": " << dw << ' ' << w << endl;
	}
}
