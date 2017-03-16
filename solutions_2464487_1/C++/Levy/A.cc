#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long r, t;

int check(long long n) {
	long long need = 2 * r * n + n + 2 * n * (n - 1);
	return need <= t;
}

long long solve() {
	long long l = 1, r = 1;
	while (check(r)) r *= 2; 
	while (l + 1 < r) {
		long long m = (l + r) / 2;
		if (check(m)) l = m;
		else r = m;
	}
	return l;
}

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; ++c) {
		cin >> r >> t;
		cout << "Case #" << c << ": " << solve() << endl;
	}
}
