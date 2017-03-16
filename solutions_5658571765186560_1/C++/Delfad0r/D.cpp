#include <bits/stdc++.h>

using namespace std;

void solve(int t) {
	int X, R, C;
	scanf("%d%d%d", &X, &R, &C);
	if(R > C) swap(R, C);
	if(X >= 7 || X > C || (R * C) % X != 0) {
		printf("Case #%d: RICHARD\n", t);
		return;
	}
	if(X <= 3) {
		if((X + 1) / 2 > R) printf("Case #%d: RICHARD\n", t);
		else printf("Case #%d: GABRIEL\n", t);
		return;
	}
	if(X == 5) {
		if((R == 3 && C >= 10) || R >= 4)
			printf("Case #%d: GABRIEL\n", t);
		else
			printf("Case #%d: RICHARD\n", t);
		return;
	}
	if((X + 1) / 2 >= R) {
		printf("Case #%d: RICHARD\n", t);
		return;
	}
	printf("Case #%d: GABRIEL\n", t);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		solve(t);
}
