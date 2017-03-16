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

int R, C, W;

int go() {
	int best = 987987;
	for(int st = 0; st < W; ++ st) {
		int t = 0, lj;
		for(int j = st; j < C; j += W) {
			t ++;
			lj = j;
		}
		if(lj == 0 || lj == C - 1);
		else t ++ ;; //fake step
//		printf("> %d %d\n", st, t+W-1);
		best = min(best, t + W - 1 );
	}
	return best;
}

int main() {
	int T;
	cin >> T;

	for(int t=1; t<=T; ++t) {
		cin >> R >> C >> W;
		//small
		assert(R == 1);

		printf("Case #%d: %d\n", t, go());
	}
	return 0;
}

