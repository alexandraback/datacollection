#include <array>
#include <cassert>
#include <cmath>
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

int n;
int D[1000001];

int flip(int u) {
	string s = to_string(u);
	std::reverse(all(s));
	istringstream S(s); S >> u;
	return u;
}

int go() {
	const int INF = 987987987;
	REP(i, 1000001) D[i] = INF;

	D[1] = 1;
	queue<int> Q;
	Q.push(1);

	while(not Q.empty()) {
		int u = Q.front(); Q.pop();

		array<int, 2> next = {u + 1, flip(u)};
		for(int v : next) {
			if(v > n) continue;
			if(D[u] + 1 < D[v]) {
				D[v] = D[u] + 1;
				Q.push(v);
			}
		}
	}
	return D[n];
}

int main() {
	int T;
	cin >> T;

	for(int t=1; t<=T; ++t) {
		cin >> n;
		printf("Case #%d: %d\n", t, go());
	}
	return 0;
}

