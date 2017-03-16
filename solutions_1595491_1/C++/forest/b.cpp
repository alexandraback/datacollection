#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

#define GI(n) scanf("%d", &n)
#define GI2(n,m) scanf("%d %d", &n, &m)

int norm[40], supr[40];

int solve() {
	int res = 0;
	VI v;
	int n, S, p;
	cin >> n >> S >> p;
	int a;
	FI {
		cin >> a; 
		if (supr[a] < 0) {
			if (norm[a] >= p)
				++res;
		} else
			v.push_back(a);
	}
	
	int x = 0;
	FIR(v.size()) {
		if (norm[v[i]] >= p)
			++res;
		else if (supr[v[i]] >= p)
			++x;
	}

	return res + min(x, S);
}


int main() {
freopen("B-large.in", "rt", stdin);
//freopen("B-large.out", "w", stdout);
	
	memset(norm, -1, sizeof norm);
	memset(supr, -1, sizeof supr);
	for (int a = 0; a <= 10; ++a)
	for (int b = a; b <= 10; ++b)
		for (int c = b; c <= 10; ++c) if (a+2 >= c) {
			int s = a+b+c;
			if (a+2 == c)
				supr[s] = max(supr[s], c);
			else
				norm[s] = max(norm[s], c);
		}

	int ntc = 0; GI(ntc);

	FORE(tc, 1, ntc) {
		int res = solve();
		printf("Case #%d: %d\n", tc, res);
	}


}
