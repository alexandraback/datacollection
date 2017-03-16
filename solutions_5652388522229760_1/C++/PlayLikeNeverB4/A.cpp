#include <bits/stdc++.h>

using namespace std;

bitset<10> f;
int D;

string transf(int n) {
	stringstream ss;
	ss << n;
	string ret;
	ss >> ret;
	return ret;
}

void addDigit(int d) {
	if (f[d] == 0) {
		f[d] = 1;
		D--;
	}
}

int calc(int n) {
	f = 0;
	D = 10;
	int x;
	for (x = n; D > 0; x += n) {
		const string &s = transf(x);
		for (size_t i = 0; i < s.size(); i++) {
			addDigit(s[i] - '0');
		}
	}
	x -= n;
	return x;
}

void solve(int n) {
	if (n == 0) {
		cout << "INSOMNIA\n";
		return;
	}

	int ans = calc(n);
	cout << ans << '\n';
}

int main() {
	assert(freopen("A.in", "r", stdin));
	assert(freopen("A.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		cout << "Case #" << t << ": ";
		solve(N);
	}

	return 0;
}
