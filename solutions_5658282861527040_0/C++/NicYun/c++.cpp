#include <string>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

const int N = 35;

long long p2[N];
long long f[N][2][2][2];

int a, b, c;

bool getBit(int n, int k) {
	return n & (1 << k);
}

int getMaxBitPos(int n) {
	int res = 0;
	REP(i, 31) {
		if (getBit(n, i)) {
			res = i;
		}
	}
	return res;
}

long long dfs(int k, bool fa, bool fb, bool fc) {
	if (k == -1) return 1;
	if (f[k][fa][fb][fc] != -1) return f[k][fa][fb][fc];
	bool ba = getBit(a, k) | fa;
	bool bb = getBit(b, k) | fb;
	bool bc = getBit(c, k) | fc;
	long long res = 0;
	if (ba) {
		res += dfs(k - 1, fa, bb, bc);
	}
	if (bb) {
		res += dfs(k - 1, ba, fb, bc);
	}
	res += dfs(k - 1, ba, bb, bc);
	if (bc == true) {
		if (ba && bb) {
			res += dfs(k - 1, fa, fb, fc);
		}
	}
	f[k][fa][fb][fc] = res;
	return res;
}

int main() {
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	int T;
	cin >> T;
	memset(p2, -1, sizeof(p2));
	p2[0] = 1;
	for (int i = 1; i < N; i++) p2[i] = p2[i-1] * 2;
	REP(t, T) {
		cin >> a >> b >> c;
		a--, b--, c--;
		int n = 0;
		n = max(n, getMaxBitPos(a));
		n = max(n, getMaxBitPos(b));
		n = max(n, getMaxBitPos(c));
		memset(f, -1, sizeof(f));
		long long res = dfs(n, false, false, false);
		cout << "Case #" << t + 1 << ": " << res << endl;
	}
	return 0;
}
