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

int w[1100];
int n;

int vis[1100];
VI back[1100];

int maxloop(int from) {
	memset(vis, 0, sizeof vis);
	vis[from] = 1;
	int v = w[from];
	int res = 1;
	while (!vis[v]) {
		++res;
		vis[v] = true;
		v = w[v];
	}

	if (v == from)
		return res;
	return 0;
}


int dfs_back(int v) {
	int mx = 0;
	for (int c : back[v])
		mx = max(mx, dfs_back(c));

	return 1 + mx;
}

int best(int v) {
	int r1 = 0;
	for (int c : back[v]) if (w[v] != c)
		r1 = max(r1, dfs_back(c));
	
	return r1;
}

int solve() {
	GI(n);
	FI GI(w[i]); FI --w[i];
	FI back[i].clear();
	FI back[w[i]].push_back(i);

	int res = 0;
	FI res = max(res, maxloop(i));

	int res2 = 0;
	FI if (w[w[i]] == i)
		res2 += 1 + best(i);

	return max(res, res2);
}

void prepare_input();
int main() {
	prepare_input();
	
	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		int res = solve();
		
		printf("Case #%d: %d\n", tc, res);
		
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
		bool LARGE = true;

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
