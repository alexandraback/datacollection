#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)

const int MAXN = 11;

int n;
long long pos[MAXN], speed[MAXN];

void read_input() {
	int m, a, b, c;

	n = 0;
	scanf("%d", &m);
	REP(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		REP(j, b) {
			pos[n] = a;
			speed[n++] = c + j;
		}
	}

}


void solve() {
	if (n < 2) {
		printf("0\n");
		return;
	}

	if (n == 2) {
		if (speed[0] == speed[1]) {
			printf("0\n");
			return;
		}

		if (speed[0] < speed[1]) {
			swap(speed[0], speed[1]);
			swap(pos[0], pos[1]);
		}

		// 0 - is slow
		if ((360 - pos[0])*speed[0] >= (360 + 360 - pos[1])*speed[1])
			puts("1");
		else puts("0");
	}
	else {
		puts("-1");
	}
}


int main(int argc, char* argv[]) {
	int nt, single_tc = 0;

	if (argc > 1) {
		sscanf(argv[1], "%d", &single_tc);
	}

	scanf("%d", &nt);
	for (int t = 1; t <= nt; ++t) {
		fprintf(stderr, "Case #%d ", t);
		read_input();
		if (single_tc == 0 || single_tc == t) {
			printf("Case #%d: ", t);
			solve();
		}
		fprintf(stderr, "done.\n");
	}

	return 0;
}