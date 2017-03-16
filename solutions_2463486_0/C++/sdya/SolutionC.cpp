#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

bool isPalindrome(long long n) {
	long long m = 0, k = n;
	while (k) {
		m = m * 10LL + (k % 10LL);
		k /= 10LL;
	}
	return n == m;
}

long long calculate(long long n) {
	if (n == 0) {
		return 0;
	}

	long long res = 0;
	for (long long i = 1; i * i <= n; ++i) {
		if (isPalindrome(i) && isPalindrome(i * i)) {
			++res;
		}
	}
	return res;
}

void solve(int test) {
	long long left, right;
	cin >> left >> right;
	cout << "Case #" << test << ": " << calculate(right) - calculate(left - 1) << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
	}
	return 0;
}