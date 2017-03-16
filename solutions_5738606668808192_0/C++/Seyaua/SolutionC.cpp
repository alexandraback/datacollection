#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

int getDivisor(int n, long long mask, int base) {
	int lim = 1LL << min(15, (n - 1));

	for (int i = 2; i <= lim; ++i) {
		int rem = 0;

		for (int j = n - 1; j >= 0; --j) {
			bool isSet = (mask & (1LL << j));
			rem *= base;
			rem += isSet;
			rem %= i;
		}
		if (rem == 0) {
			return i;
		}
	}
	return 0;
}

void coinjam(int n, int m) {
	set<long long> used;

	while (m > 0) {
		long long mask = 0;
		mask |= 1LL;
		mask |= (1LL << (n - 1));

		for (int i = 1; i + 1 < n; ++i) {
			int isSet = rand() % 2;
			if (isSet) {
				mask |= 1LL << i;
			}
		}

		if (used.count(mask)) {
			continue;
		}

		bool isGood = true;
		for (int i = 2; i <= 10; ++i) {
			if (!getDivisor(n, mask, i)) {
				isGood = false;
				break;
			}
		}
		if (isGood) {
			--m;
			cerr << m << endl;
			for (int i = n - 1; i >= 0; --i) {
				if (mask & (1LL << i)) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
			for (int i = 2; i <= 10; ++i) {
				cout << " " << getDivisor(n, mask, i);
			}
			cout << endl;
			used.insert(mask);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int n, j;
		cin >> n >> j;
		cout << "Case #" << i + 1 << ":" << endl;
		coinjam(n, j);
	}

	return 0;
}