#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;

bool solve() {
	int X, R, C;
	scanf(" %d %d %d", &X, &R, &C);
	if (R > C) swap(R, C);
	if (C < X) return true;
	if ((R * C) % X) return true;
	int sqSmall = (X - 1) / 2 + 1;
	int sqBig = (X) / 2 + 1;
	if (R < sqSmall) return true;
	if (R == sqSmall && C < sqBig) return true;
	if (X >= 7) return true;
	if (X >= 4 && R == 2) return true;
	if (X == 6 && R == 3) return true;

	return false;
}

int main() {
	int t;
	scanf(" %d", &t);
	REP(i, t) {
		printf("Case #%d: %s\n", i+1, solve() ? "RICHARD" : "GABRIEL");
	}
}