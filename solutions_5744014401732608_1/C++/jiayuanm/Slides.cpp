#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

inline LL bnd(const LL& b) {
	if (b >= 2) {
		return 1L << (b - 2);
	}
	return 1;
}

int G[55][55];

void initG(const int& b) {
	for (int i = 0; i < b-1; ++i) {
		for (int j = 0; j < i; ++j) {
			G[j][i] = 1; 
		}
	}
}

void fillG(const int& b, LL m) {
	int i = 0;
	while (m) {
		if (m & 1) {
			if (i+1 != b-1) {
				G[i+1][b-1] = 1;
			}
		}
		++i;
		m >>= 1;
	}
}

void printG(const int& b) {
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << G[i][j];
		}
		cout << endl;
	}
}

void solve() {
	LL B, M;
	scanf("%lld%lld", &B, &M);
	LL bb = bnd(B);
	if (M > bb) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	memset(G, 0, sizeof(G));
	initG(B);
	if (bb == M) {
		G[0][B-1] = 1;
		--M;
	}
	fillG(B, M);
	cout << " POSSIBLE" << endl;
	printG(B);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:", tt);
		solve();
	}
	return 0;
}
