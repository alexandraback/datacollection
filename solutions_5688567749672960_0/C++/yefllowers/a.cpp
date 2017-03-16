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

int rev(int x) {
	if (!x) return x;
	int q = 0;
	while (x) {
		q = q * 10 + x % 10;
		x /= 10;
	}
	return q;
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
	int n;
	cin >> n;
	FOR(T, 1, n) {
		long long x;
		cin >> x;
		printf("Case #%d: %d\n", T, d[x]);
	}
	return 0;
}

