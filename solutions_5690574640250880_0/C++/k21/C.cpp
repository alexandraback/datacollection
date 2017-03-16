#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXD = 60;

char out[MAXD][MAXD];

int main() {
	int T;
	scanf("%d", &T);
	REP(t,T) {
		printf("Case #%d:\n", t+1);
		int R, C, M;
		scanf("%d%d%d", &R, &C, &M);
		bool trans = false;
		if (C < R) {
			swap(C, R);
			trans = true;
		}
		REP(r,R) REP(c,C) out[r][c] = '.';
		out[0][0] = 'c';
		int rr = R, rc = C;
		int lr = R-1, lc = C;
		while (M > 0 && rr > 3) {
			if (M == 1 && lc == 2) {
				lc = C;
				--rr;
				continue;
			}
			--lc;
			if (lc < 0) {
				lc = C;
				--rr;
				continue;
			}
			out[rr-1][lc] = '*';
			--M;
		}
		lr = rr;
		lc = C-1;
		while (M > 0 && rc > 3) {
			if (M == 1 && lr == 2) {
				lr = rr;
				--rc;
				continue;
			}
			--lr;
			if (lr < 0) {
				lr = rr;
				--rc;
				continue;
			}
			out[lr][rc-1] = '*';
			--M;
		}
		bool ok = false;
		//DEBUG(rr);
		//DEBUG(rc);
		if (rr == 3 && rc == 3) {
			ok = M == 0 || M == 1 || M == 3 || M == 5 || M == 8;
			if (M >= 1) {
				out[2][2] = '*';
			}
			if (M >= 3) {
				out[2][1] = '*';
				out[2][0] = '*';
			}
			if (M >= 5) {
				out[1][2] = '*';
				out[0][2] = '*';
			}
			if (M >= 8) {
				out[1][0] = '*';
				out[1][1] = '*';
				out[0][1] = '*';
			}
		} else if (rr == 2 && rc == 3) {
			ok = M == 0 || M == 2 || M == 5;
			if (M >= 2) {
				out[0][2] = '*';
				out[1][2] = '*';
			}
			if (M >= 5) {
				out[0][1] = '*';
				out[1][1] = '*';
				out[1][0] = '*';
			}
		} else if (rr == 1 && rc == 3) {
			ok = true;
			if (M >= 1) {
				out[0][2] = '*';
			}
			if (M >= 2) {
				out[0][1] = '*';
			}
		} else if (rr == 2 && rc == 2) {
			ok = M == 0 || M == 3;
			if (M >= 3) {
				out[0][1] = '*';
				out[1][1] = '*';
				out[1][0] = '*';
			}
		} else if (rr == 1 && rc == 2) {
			ok = true;
			if (M >= 1) {
				out[0][1] = '*';
			}
		} else if (rr == 1 && rc == 1) {
			ok = true;
		}

		if (M != 0 && !ok) {
			printf("Impossible\n");
			continue;
		}

		REP(r,trans ? C : R) {
			REP(c,trans ? R : C) {
				printf("%c", trans ? out[c][r] : out[r][c]);
			}
			printf("\n");
		}
		//DEBUG(M);
	}
	return 0;
}
