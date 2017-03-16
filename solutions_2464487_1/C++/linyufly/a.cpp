#include <iostream>

typedef long long Int64;

using namespace std;

void Solve() {
	Int64 r, t;
	cin >> r >> t;
	Int64 left = 1, right = t + 1, mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		Int64 N = r + 2 * (mid - 1);
		Int64 A = (2 * r + 1) + (2 * N + 1);
		Int64 B = mid;
		if (A & 1) B /= 2;
		else A /= 2;
		if (A <= t / B) left = mid;
		else right = mid;
	}
	cout << left << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		Solve();
	}
	return 0;
}
