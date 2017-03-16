#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long gcd(unsigned long long a,  unsigned long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int getPower(unsigned long long a) {
	int curPower = 0;
	while (a != 1) {
		if (a % 2 == 1) return -1;
		curPower++;
		a >>= 1;
	}
	return curPower;
}

void solve(unsigned long long p, unsigned long long q, int curGeneration) {
	if (p > q) {
		cout << "impossible";
	} else if (p == q) {
		cout << curGeneration;
	} else {
		int curPower = getPower(q);
		if (curPower == -1) {
			cout << "impossible";
		} else {
			q >>= 1;
			unsigned long long curP = 1;
			while (curP <= p) {
				curP <<= 1;
			}
			curP >>= 1;
			unsigned long long divisor = gcd(curP, q);
			curP /= divisor, q /= divisor;
			if (q == 1) {
				cout << curGeneration;
			} else solve(curP, q, curGeneration + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	freopen("ProblemA.in", "r", stdin);
	freopen("ProblemA.out", "w", stdout);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		unsigned long long p, q;
		char t;
		cin >> p >> t >> q;
		unsigned long long divisor = gcd(p, q);
		p /= divisor, q /= divisor;
		cout << "Case #" << test + 1 << ": ";
		solve(p, q, 1);
		cout << "\n";
	}

	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
