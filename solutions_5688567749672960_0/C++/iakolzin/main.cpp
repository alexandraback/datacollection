#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long rev(long long x) {
	if (x % 10 == 0)
		return 1e18;
	long long res = 0;
	while (x > 0) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}
	return res;
}

long long solve(long long n) {
	if (n == 0)
		return 0;
	if (rev(n) == n || n % 10 == 0)
		return 1 + solve(n - 1);
	int d = 0;
	long long now = n;
	while (now) {
		d++;
		now /= 10;
	}
	d = d / 2 + d % 2;
	now = 0;
	long long cur = n;
	long long p = 1;
	while (d) {
		d--;
		now += (cur % 10) * p;
		cur /= 10;
		p *= 10;
	}
	now -= 1;

	n = n - now;
	if (n == rev(n))
		return now + solve(n);
	else
		return now + solve(rev(n)) + 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		long long n;
		cin >> n;
		cout << "Case #" << t + 1 << ": " << solve(n) << endl;
	}

	return 0;
}