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

int H, W;

VI res;


void rect(int h, int w) {
	FIR(h) res.push_back(w);
}

int solve() {
	GI2(H, W);
	int bombs; GI(bombs);
	int empty = H*W - bombs;
	res.clear();

	if (empty == 1) {
		rect(1, 1);
		return true;
	}

	if (H == 1) {
		rect(1, empty);
		return true;
	}
	if (W == 1) {
		rect(empty, 1);
		return true;
	}


	FORE(h, 2, H) FORE(w, 2, W) {
		int t = h*w;
		if (t > empty) continue;
		
		if (t == empty) {
			rect(h, w);
			return true;
		}

		if (h < H) {
			int top = empty - t;
			if (top >= 2 && top < w) {
				rect(h, w);
				res.push_back(top);
				return true;
			}
		}

		if (w < W) {
			int side = empty - t;
			if (side >= 2 && side < h) {
				rect(h, w);
				FIR(side) ++res[i];
				return true;
			}
		}

		if (h+1 < H) {
			int delta = empty - t;
			int top1 = (delta+1)/2;
			int top2 = delta - top1;
			if (top1 >= 2 && top1 < w && top2 >= 2 && top2 < w) {
				rect(h, w);
				rect(1, top1);
				rect(1, top2);
				return true;
			}
		}

		if (w+1 < W) {
			int delta = empty - t;
			int side1 = (delta+1)/2;
			int side2 = delta - side1;
			if (side1 >= 2 && side1 < h && side2 >= 2 && side2 < h) {
				rect(h, w);
				FIR(side1) ++res[i];
				FIR(side2) ++res[i];
				return true;
			}
		}
	}


	return false;
}

void prepare_input();
int main() {
	prepare_input();
	
	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		printf("Case #%d:\n", tc);
		if (solve()) {
			rect(H, 0);
			string s(W, '!');
			REP(r, H) {
				FIR(res[r]) s[i] = '.';
				FOR(i, res[r], W) s[i] = '*';
				if (r == 0) s[0] = 'c';
				cout << s << endl;
			}
			
		} else puts("Impossible");
	}
}


void prepare_input()  {
	bool LOCAL = false;
	char TASK = 'C';

	static char in_file[200], out_file[200];
	if (LOCAL) {
		freopen("input.txt", "rt", stdin);
	} else {

		int ATTEMPT = 1;
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
