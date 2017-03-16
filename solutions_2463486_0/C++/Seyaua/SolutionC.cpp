#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxL = 20000000;

bool Nice(long long n) {
	long long res = 0, m = n;
	while (m) {
		res = res * 10 + (m % 10);
		m /= 10;
	}
	return (n == res);
}

int s[maxL];

long long calc(long long n) {
	long long m = (long long)(sqrt((double)(n)));
	
	long long p = -1;
	for (long long i = m - 3; i <= m + 3; ++i) {
		if (i > 0 && i * i <= n) {
			p = i;
		}
	}
	return s[p];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (long long i = 1; i < maxL; ++i) {
		s[i] = s[i - 1];
		if (Nice(i) && Nice(i * i)) {
			++s[i];
		}
	}

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		long long l, r;
		cin >> l >> r;
		cout << "Case #" << test << ": " << calc(r) - calc(l - 1) << endl;
	}
	return 0;
}