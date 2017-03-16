#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;
#define LL long long
#define FILES freopen("input.txt" ,"r", stdin); freopen("output.txt", "w", stdout);
#define FASTER ios::sync_with_stdio(0);
#define fr(i, a, b) for(int i = (a); i < (b); ++i)
#define ffr(i, b) fr(i, 0, b)
using namespace std;

LL rev(LL n) {
	LL res = 0;
	while (n > 0) {
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}

bool sameL(LL a, LL b) {
	while (a > 0) {
		if (b == 0) return false;
		a /= 10;
		b /= 10;
	}
	return true;
}

LL dp[123456708];

int numL(LL x) {
	int res = 0;
	while (x > 0) {
		res++;
		x /= 10;
	}
	return res;
}

LL ten(int l) {
	LL res = 1;
	for (int i = 1; i <= l; i++) res *= 10;
	return res;
}


int p[123444];
int main() {
	FILES;
	FASTER;
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		LL n;
		cin >> n;
		LL cnt = 0;
		while (n > 9) {
			int len = numL(n);
			LL tn = ten(len / 2);
			if (n % tn < 1) { cnt += 1; n--; continue; }
			cnt += n % tn - 1;
		    n = n / tn * tn + 1;
			LL tmp = rev(n);
			if (tmp < n) {
				n = tmp;
				cnt++;
			}
			cnt += n % tn + 1;
			n = n / tn * tn - 1;
		}
		cnt += n;
		cout << "Case #" << t << ": " << cnt << endl;
	}
}
