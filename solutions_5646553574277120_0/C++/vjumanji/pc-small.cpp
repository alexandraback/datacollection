#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
#define REP(i,a) FOR(i,0,a)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)

typedef long long int LL;
typedef vector<int> vi;

int rint() { int x; scanf("%d", &x); return x;}
int rLL() { LL x; scanf("%lld", &x); return x;}

bool possible[101];
vi deno;
int C,D,V;
void checkpossible (int mask) {
	int sum = 0;
	for(int i = 1, j=0; i <= mask; i = i<<1, j++) {
		if (mask & i) {
			sum += deno[j];
		}
	}
	if (sum <= V) {
		possible[sum] = true;
		// printf("possible %d\n", sum);
	}
}

int solve () {
	deno.clear();
	C = rint(), D = rint(), V = rint();
	REP(i,D) deno.push_back(rint());
	REP(i,V+1) possible[i] = false;
	FOR(i,0,1<<D) checkpossible(i);

	int ans = 0;
	REP(i,V+1) if (!possible[i]) {
		ans ++;
		vi newpossible;
		REP(j,V+1) if (j - i >= 0 && possible[j-i] && !possible[j]) {
			// printf("now possible %d\n", j);
			newpossible.push_back(j);
		}
		REP(j,newpossible.size()) possible[newpossible[j]] = true;
	}
	return ans;
}

int main() {
	int t = rint();
	REP(i,t) {
	  printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}