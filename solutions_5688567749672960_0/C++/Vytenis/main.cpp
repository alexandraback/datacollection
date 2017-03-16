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

const int MAXN = 1000001;
int n;
int d[MAXN];

void read_input() {
	scanf("%d", &n);
}

void precompute() {
	REP(i, MAXN) d[i] = MAXN;
	queue <int> q;
	q.push(1); d[1] = 1;
	while (!q.empty()) {
		int num = q.front(); q.pop();
		if (num + 1 < MAXN && d[num + 1] == MAXN) {
			q.push(num + 1); d[num + 1] = d[num] + 1;
		}
		int rev = 0, tmp = num;
		while (tmp) { rev = rev * 10 + tmp % 10; tmp /= 10; }
		if (rev < MAXN && d[rev] == MAXN) {
			q.push(rev); d[rev] = d[num] + 1;
		}
	}
}


void solve() {
	printf("%d\n", d[n]);
}


int main(int argc, char* argv[]) {
	int nt, single_tc = 0;

	if (argc > 1) {
		sscanf(argv[1], "%d", &single_tc);
	}

	precompute();

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