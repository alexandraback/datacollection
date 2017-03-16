#include <bits/stdc++.h>
using namespace std;

long long rev(long long n) {
	long long r = 0;
	if (n % 10) {
		while (n) {
			r *= 10;
			r += n % 10;
			n /= 10;
		}
	}
	return r;
}

int mem[1000001];
int solve(int n) {
	if (mem[n]) {
		return mem[n];
	}
	int c = solve(n - 1), r;
	if ((r = rev(n)) != n && r < n) {
		c = min(c, solve(r));
	}
	return mem[n] = 1 + c;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < 11; i++) {
		mem[i] = i;
	}
	for (int i = 11; i < 1000001; i++) {
		solve(i);
	}
	for (int t = 0; t++ < T;) {
		int N;
		cin >> N;
		cout << "Case #" << t << ": " << solve(N) << endl;
	}
	return 0;
}
