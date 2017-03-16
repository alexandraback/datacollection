#include <bits/stdc++.h>
using namespace std;

int c, d;
long long v;

int main() {
	ifstream in ("coins.in");
	ofstream out("coins.out");

	int t;
	in >> t;
	for (int tc = 1; tc <= t; tc++) {
		out << "Case #" << tc << ": ";
		in >> c >> d >> v;
		long long denoms[d];
		for (int i = 0; i < d; i++) {
			in >> denoms[i];
		}

		sort(denoms, denoms + d);
		int ans = 0;
		long long sum = 0;
		for (long long p = 1; p < denoms[0]; p *= c + 1) {
			ans++;
			sum += p;
		}
		for (int i = 0; i < d - 1; i++) {
			for (long long p = denoms[i]; sum * c < denoms[i + 1] - 1 || p == denoms[i]; p = sum * c + 1) {
				ans++;
				sum += p;
			}
		}
		for (long long p = denoms[d - 1]; sum * c < v || p == denoms[d - 1]; p = sum * c + 1) {
			ans++;
			sum += p;
		}
		out << ans - d << endl;
	}

	return 0;
}
