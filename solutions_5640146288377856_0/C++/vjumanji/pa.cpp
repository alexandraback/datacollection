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

int solve(int R, int W) {
	int x = R/W;
	if (R%W == 0) x = x - 1 + W;
	else x += W;
	return x;
}

int main() {
	int t = rint();
	REP(i,t) {
		int r = rint(), c = rint(), w = rint();
		printf("Case #%d: %d\n", i+1, solve(c,w));
	}
	return 0;
}