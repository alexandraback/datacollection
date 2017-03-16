#include <iostream>
using namespace std;
int solve() {
	long long r, t;
	cin >> r >> t;
	long long a = 0, b = 1000000000;
	while (a+1 < b) {
		long long c = (a+b+1)/2;
		if ((double)(c+1)*(2*c + 2*r+1) <= t) {
			a = c;
		} else {
			b = c;
		}
	}
	return a+1;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
