#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long r, t;

long long solve() {
	for (long long i = 1; ; ++i) {
		long long need = 2 * r * i + i + 2 * i * (i - 1);
		if (need > t) return i - 1;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; ++c) {
		cin >> r >> t;
		cout << "Case #" << c << ": " << solve() << endl;
	}
}
