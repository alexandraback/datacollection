#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)
#define range(i,a,b) for(int i=(a),_n=(b); i<_n; ++i)


const int MAX_R = 1000, MAX_C = 1000;
bool grid[MAX_R][MAX_C], seen[MAX_R][MAX_C];
int R, C, K, k, best;

int count(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C || grid[r][c] || seen[r][c]) return 0;
	seen[r][c] = true;
	return 1 + count(r+1,c) + count(r-1,c) + count(r,c+1) + count(r,c-1);
}

void go() {
	fo(r,R) fo(c,C) seen[r][c] = false;
	if (R * C - count(0,0) >= K) {
		best = min(best, k);
	}
}

void gen(int r = 1, int c = 1) {
	if (c > C - 2) {
		if (r == R - 2) {
			go();
		} else {
			gen(r + 1);
		}
	} else {
		gen(r, c+1);
		grid[r][c] = true;
		++k;
		gen(r, c+1);
		grid[r][c] = false;
		--k;
	}
}

int main() {
	int tests;
	cin >> tests;
	range(test, 1, tests+1) {
		cin >> R >> C >> K;
		R += 2;
		C += 2;
		best = R * C;
		k = 0;
		gen();
		cout << "Case #" << test << ": " << best << endl;
	}
}