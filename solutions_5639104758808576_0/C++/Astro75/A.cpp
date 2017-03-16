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
	int total = 0;
	int res = 0;
	REP(i, n+1) {
		char c;
		scanf(" %c", &c);
		int cur = c - '0';
		if (cur > 0 && total < i) {
			res += i - total;
			total = i;
		}
		total += cur;
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