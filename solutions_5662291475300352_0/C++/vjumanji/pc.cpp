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

int main() {
	int t = rint();
	REP(T,t) {
		int n = rint(), fast = -1, slow = -1, sd;
		REP(i, n) {
			int d, h, m;
			cin >> d >> h >> m;
			if (slow < m) {
				slow = m;
				sd = d;
			}
			if (h > 1) {
				if (slow < m+1) {
					slow = m+1;
					sd = d;
				}
			}
			if (fast == -1 || fast > m) fast = m;
		}
		if (slow == fast) {
			printf("Case #%d: 0\n", T+1);
			continue;
		}
		double del = slow*fast/(slow - fast);
		del *= sd / 360.0;

		if (del < fast)
			printf("Case #%d: 1\n", T+1);
		else
			printf("Case #%d: 0\n", T+1);
	}
	return 0;
}