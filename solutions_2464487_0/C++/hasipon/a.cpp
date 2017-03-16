#include <iostream>
using namespace std;
int solve() {
	long long r, t;
	cin >> r >> t;
	long long sum = 0;
	for (long long i = 0; ; ++ i) {
		sum += 2 * (r + 2*i) + 1;
		if (sum > t) return i;
	}
	return 0;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
