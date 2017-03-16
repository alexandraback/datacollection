#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		long long B, M;
		cin >> B >> M;
		vector<string> out(B, string(B, '0'));
		vector<long long> r(B, 1);
		for (int i = 0; i < B-1; ++i) {
			out[i][i + 1] = '1';
		}
		long long sum = 1;
		for (int i = B-3; i>=0; --i) {
			for (int j = i + 2; j < B; ++j) {
				if (r[0] + r[j] <= M) {
					for (int k = 0; k <= i; ++k) r[k] += r[j];
					out[i][j] = '1';
				}
			}
		}

		cout << "Case #" << q << ": ";
		if (r[0] == M) {
			cout << "POSSIBLE" << endl;
			for (auto& o : out) cout << o << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}