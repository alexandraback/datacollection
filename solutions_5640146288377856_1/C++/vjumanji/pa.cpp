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

int solve2(int R, int C, int W) {
	int x = C/W;
	if (C%W == 0) {
		x--;
	}
	int y  = x;
	x *= R;
	x += R-1;
	return x + solve(C-y*W, W);
}

int main() {
	int t = rint();
	REP(i,t) {
		int r = rint(), c = rint(), w = rint();
		printf("Case #%d: %d\n", i+1, solve2(r,c,w));
	}
	return 0;
}