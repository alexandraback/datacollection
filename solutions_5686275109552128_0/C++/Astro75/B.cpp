#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;

int solve() {
	int n;
	scanf(" %d", &n);
	int s[1001] = {};
	int res = 1<<23;
	REP(i, n) {
		int cur;
		scanf(" %d", &cur);
		s[cur]++;
	}
	FOR(i, 1, 1000) {
		int cur = 0;
		FOR(j, 2, 1000) {
			cur += (j - 1) / i * s[j];
		}
		res = min(res, i + cur);
		// cout << i << ' ' << res << ' ' << cur << endl;
	}
	return res;
}

int main() {
	int t;
	scanf(" %d", &t);
	REP(i, t) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}