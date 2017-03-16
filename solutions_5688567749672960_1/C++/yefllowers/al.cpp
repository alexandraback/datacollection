#include <iostream>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define REP(i, n) for(int i(0); (i)<(int)(n); i++)
#define FOR(i, a, b) for (int i(a); i <= int(b); i++)


const int N = (int)1e6 + 10;
int n, d[N];

long long rev(long long x) {
	if (!x) return x;
	long long q = 0;
	while (x) {
		q = q * 10 + x % 10;
		x /= 10;
	}
	return q;
}

long long solve(long long x) {
	int s[55];
	int len = 0;
	memset(s, 0, sizeof(s));
	if (x <= 19) return x;
	long long y = x;
	while (x) s[len++] = x % 10, x /= 10;
	x = y;
	long long p = 1;
	REP(i, len / 2) p *= 10;
	long long now = x / p * p + 1;
	if (now > x) {
		now = (x / p - 1) * p + 1;
	}
//	cout << x << ' ' << now << ' ' << len << ' ' << p << endl;
	long long ans = x - now;
	long long tmp = rev(now);
	if (now <= x && tmp < x) {
		ans += solve(tmp);
		if (now != tmp) ans++;
	} else
		ans += solve(now - 1) + 1;
	return min(x, ans);
}

int main() {
	d[1] = 1;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty()) {
		int i = Q.front();
		Q.pop();
		int t = i + 1;
		if (t < N && !d[t]) {
			d[t] = d[i] + 1;
			Q.push(t);
		}
		t = rev(i);
		if (t < N && !d[t]) {
			d[t] = d[i] + 1;
			Q.push(t);
		}
	}
	int CNT;
	cin >> CNT;
	FOR(T, 1, CNT) {
		long long x;
		cin >> x;
		cout << "Case #" << T << ": " << solve(x) << endl;
	}
	return 0;
}

