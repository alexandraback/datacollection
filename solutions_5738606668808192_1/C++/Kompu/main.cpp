#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;
#define DEBUG(x) cerr << #x << " = " << x << endl;
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOR(x, b, e) for(int x = (b); x != (e); x += 1 - 2 * ((b) > (e)))
const int INF = 1000000001;
const double EPS = 10e-9;

mpz_class isPrime(mpz_class n) {
	if (n < 2) {
		return -1;
	}
	for (int x = 2; x < 100; ++x) {
		if (n % x == 0) {
			return x;
		}
	}
	return 0;
}

void increment(string& str) {
	for (int i = str.size() - 2; i > 0; --i) {
		if (str[i] == '0') {
			str[i] = '1';
			return;
		} else {
			str[i] = '0';
		}
	}
}

bool testNumber(const string& str) {
	FOR(i, 2, 11) {
		mpz_class num(str, i);
		if (isPrime(num) == 0) {
			return false;
		}
	}
	return true;
}

void printJamcoin(const string& str) {
	cout << str << " ";
	FOR(i, 2, 11) {
		mpz_class num(str, i);
		mpz_class d = isPrime(num);
		cout << d << " ";
	}
	cout << "\n";
}

#ifndef CATCH_TEST
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(o, t) {
		cout << "Case #" << o + 1 << ":\n";
		int n, j;
		cin >> n >> j;

		string number;
		number += '1';
		REP(x, n - 2) {
			number += '0';
		}
		number += '1';

		int found = 0;
		while(found < j) {
			if (testNumber(number)) {
				printJamcoin(number);
				++found;
			}
			increment(number);
		}
	}

	return 0;
}
#endif