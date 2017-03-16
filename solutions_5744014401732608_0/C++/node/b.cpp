#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int t;
	cin >> t;
	for (int casei = 1; casei <= t; casei++) {
		long long b, m;
		cin >> b >> m;
		b--;
		long required = ceil(log2 (m));
		cout << "Case #" << casei << ": ";
		if (required <= b-1) {
			cout << "POSSIBLE" << endl;
			int result[b+1][b+1];
			for (int i = 0; i <= b; i++) {
				for (int j = 0; j <= b; j++) {
					result[i][j] = 0;
				}	
			}
			int ind = 1;
			while (m != 0) {
				if (m & 1) {
					if (b-ind != 0) {
						result[0][b-ind] = 1;
					}
				}
				for (int i = b; i > (b-ind); i--) {
					result[b-ind][i] = 1;
				}
				m = m >> 1;
				ind++;
			}
			for (int i = 0; i <= b; i++) {
				for (int j = 0; j <= b; j++) {
					cout << result[i][j];
				}
				cout << endl;
			}
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}