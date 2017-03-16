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

int L;
char buf[110000];
PI a[110000];

#define Q_Z 0
#define Q_I 1
#define Q_J 2
#define Q_K 3

PI q_mul(PI p1, PI p2) {
	if (p1.first == Q_Z || p2.first == Q_Z)
		return PI(p1.first + p2.first, p1.second ^ p2.second);

	if (p1.first == p2.first)
		return PI(Q_Z, p1.second ^ p2.second ^ 1);

	int flip = (p1.first == Q_I && p2.first == Q_K) ||
		(p1.first == Q_J && p2.first == Q_I)||
		(p1.first == Q_K && p2.first == Q_J);
	return PI(6 - p1.first - p2.first, p1.second ^ p2.second ^ flip);
}

int solve() {
	int X; GI2(L, X);
	scanf("%s", buf);
	PI res = PI(Q_Z, 0);
	FIR(L) {
		PI p(0, 0);
		switch (buf[i]) {
			case 'i': p.first = Q_I; break;
			case 'j': p.first = Q_J; break;	
			case 'k': p.first = Q_K; break;
		}
		a[i] = p;
		res = q_mul(res, p);
	}
	PI total = PI(Q_Z, 0);
	FIR(X % 8) {
		total = q_mul(total, res);
	}

	if (total != PI(Q_Z, 1))
		return false;

	PI QQ_I = PI(Q_I, 0);
	PI QQ_K = PI(Q_K, 0);
	bool foundI = false;

	X = min(X, 100);
	res = PI(Q_Z, 0);
	FJR(X) FIR(L) {
		res = q_mul(res, a[i]);
		if (foundI && res == QQ_K)
			return true;
		if (!foundI && res == QQ_I)
			foundI = true;
	}

	
	return false;
}

void prepare_input();
int main() {
	prepare_input();
	
	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		int res = solve();
		printf("Case #%d: %s\n", tc, (res ? "YES" : "NO"));
	}
}


void prepare_input()  {
	bool LOCAL = false;
	char TASK = 'C';

	static char in_file[200], out_file[200];
	if (LOCAL) {
		freopen("input.txt", "rt", stdin);
	} else {

		int ATTEMPT = 0;
		bool LARGE = false;

		if (LARGE) {
			sprintf(in_file, "%c-large.in", TASK);
			sprintf(out_file, "%c-large.out", TASK);
		} else {
			sprintf(in_file, "%c-small-attempt%d.in", TASK,  ATTEMPT);
			sprintf(out_file, "%c-small-attempt%d.out", TASK,  ATTEMPT);
		}

		cerr << in_file <<  endl; freopen(in_file, "rt", stdin);
		cerr << out_file << endl; freopen(out_file, "w", stdout);
	}
}
