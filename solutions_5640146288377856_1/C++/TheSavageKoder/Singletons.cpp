#include <bits/stdc++.h>

#define INF 1000000

using namespace std;
int R, C, W;
/*
bool vis[1<<20];
int f[1<<20];
int F(int msk) {
	int res = 0;
	bool possible = false;
	for(int i = 0; i < C; i++) {
		if((1<<i)&msk) continue;
		int L = 0, R = 0;
		for(int j = i-1; j >= 0; j--, L++)
			if((1<<j)&msk) break;
		for(int j = i+1; j < C; j++, R++)
			if((1<<j)&msk) break;
		possible |= L+R+1 >= W;
		if(L+R+1 == W) res = max(res, W); // all out hits
		if(L+R+1 > W) res = max(res, W+1); // hit, then at most one miss

	}
	return possible ? res : -INF;
}
*/

int G() {
	if(C%W == 0)
		return C/W + W - 1;
	return C/W + W;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int cse = 1; cse <= T; cse++) {
		cin >> R >> C >> W;
//		memset(vis, 0, sizeof vis);
//		int res = (C/W)*(R-1) + F(0);
		int res = (C/W)*(R-1) + G();
		printf("Case #%d: %d\n", cse, res);
	}
	return 0;
}
