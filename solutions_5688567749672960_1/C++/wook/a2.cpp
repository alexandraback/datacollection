#include <array>
#include <cassert>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

long long n;
int D[10001];

long long flip(long long u) {
	string s = to_string(u);
	std::reverse(all(s));
	istringstream S(s); S >> u;
	return u;
}

void go_small() {
	const int INF = 987987987;
	REP(i, 10001) D[i] = INF;

	D[1] = 1;
	queue<int> Q;
	Q.push(1);

	while(not Q.empty()) {
		int u = Q.front(); Q.pop();

		array<int, 2> next = {u + 1, (int) flip(u)};
		for(int v : next) {
			if(v > 10000) continue;
			if(D[u] + 1 < D[v]) {
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}
	}
}

long long further(long long b, long long n) {
	// 19 -> 91 | 199 -> 991 | 1099 -> 9901 | 10999 -> 99901 |
	// 100998 -> 899001  -> 899999                    ^^^^^^^^ b
	//    y        z           n

	string N = to_string(n);
	if(n % 10 == 0) N = to_string(n - 1);
	long long ans = 1LL << 60;
	for(int i = N.length() - 1; i > 0; -- i) {
		N[i] = (i == (int)N.length() - 1) ? '1' : '0';
		long long z = stoll(N);
		long long y = flip(z);
		if(b <= y && y <= z && z <= n) {
			long long cost = 0;
//			printf(": %lld %lld %lld %lld\n", b, y, z, n);
			cost += y - b;
			cost += (y != z) ? 1 : 0;
			cost += n - z;
			ans = min(ans, cost);
		}
	}
	return ans;
}

long long go() {
	if(n <= 10000) return D[n];

	// 19 91 / 199 991 / 1099 9901 / 10999 99901 / 109999 999901
	//      108       108        1098          10098
	long long a = 1099, b = 9901, p = 1000;
	long long base_cost = 238;

	long long ans = 1LL << 60;

	while(true) {
//		printf("> %lld %lld (%lld) (%lld) \n", a, b, base_cost, further(b, n));
		ans = min(ans, base_cost + further(b, n));

		long long c = b + 98 + p;
		base_cost += c - b;
		long long d = flip(c);
		if(d > n) break;
		base_cost ++;
		a = c, b = d;
		p *= 10;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;

	go_small();

	for(int t=1; t<=T; ++t) {
		cin >> n;
		printf("Case #%d: %lld\n", t, go());
	}
	return 0;
}

