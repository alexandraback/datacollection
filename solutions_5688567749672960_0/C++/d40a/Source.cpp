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

LL dp[12345678];
int main() {
	FILES;
	FASTER;
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		LL n;
		cin >> n;
		LL cnt = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = 1e15;
		for (LL i = 2; i <= n; i++) {

			dp[i] = min(dp[i - 1] + 1, dp[i]);
			LL tmp = rev(i);
			dp[tmp] = min(dp[tmp], dp[i] + 1);
		//	cout << i << ' ' << dp[i] << endl;
		}

		cout << "Case #" << t << ": " << dp[n] << endl;	
	}
} 
