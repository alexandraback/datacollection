#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cinttypes>
#include <algorithm>
#include <cassert>
using namespace std;

const int maxn = 1010;
int d;
int p[maxn];

inline int divup(int a, int b) {
	return (a + b - 1) / b;
}

bool go(int t) {
	int sendTime = 0;
	for (; sendTime < t; ++sendTime) {
		int bound = t - sendTime;
		int req = 0;
		for (int i = 0; i < d; ++i) if (p[i] > bound) {
			assert(bound > 0);
			req += divup(p[i], bound) - 1;
		}
		if (req <= sendTime) break;
	}
	if (sendTime >= t) return false;
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int TT; cin >> TT;
	for (int T = 1; T <= TT; ++T) {
		cin >> d;
		for (int i = 0; i < d; ++i) cin >> p[i];

		int l = 0, r = 1010;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (go(m))
				r = m;
			else
				l = m;
		}

#if 0
		for (int i = 1; i < r; ++i) if (go(i)) {
			assert(false);
		}
#endif

		cout << "Case #" << T << ": " << r << endl;
	}
	return 0;
}