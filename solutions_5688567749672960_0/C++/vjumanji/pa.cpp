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


LL ways[1000000+1];

int rev(int n) {
	int m = 0;
	while (n) {
		m = 10*(m) + n%10;
		n /= 10;
	}
	return m;
}

int main() {
	FOR(i,0,1000000+1) ways[i] = -1;
	ways[1] = 1;
	FOR(i,2,1000000+1) {
		if (ways[i] == -1 || ways[i] > ways[i-1]+1)
			ways[i] = ways[i-1] + 1;
		int r = rev(i);
		if (ways[r] == -1 || ways[r] > ways[i]+1)
			ways[r] = ways[i] + 1;
	}
	// REP(i,40) printf("%d = %lld\n", i, ways[i]);
	int t = rint();
	REP(i,t) {
		int n = rint();
		printf("Case #%d: %lld\n", i+1, ways[n]);
	}
	return 0;
}