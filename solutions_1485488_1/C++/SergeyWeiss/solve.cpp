#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef long long lint;
#define row first
#define col second

int W, R, C;

int Ceil[111][111];
int Floor[111][111];
inline int cc(pii p) {
	return Ceil[p.row][p.col];
}
inline int ff(pii p) {
	return Floor[p.row][p.col];
}

const int inf = 1 << 29;

int canGo(pii from, pii to) {
	if(cc(to) - ff(to) < 50) return inf;
	if(cc(to) - ff(from) < 50) return inf;
	if(cc(from) - ff(to) < 50) return inf;
	if(W <= cc(to) - 50) return 0;
	return (W - (cc(to) - 50));// / 10;
}

int Used[111][111];

inline bool valid(pii p) {
	return p.row >= 0 && p.row < R && p.col >= 0 && p.col < C;
}
inline bool used(pii p, int t) {
	return Used[p.row][p.col] == t;
}
inline void use(pii p, int t) {
	Used[p.row][p.col] = t;
}

struct foo {
	int time;
	pii p;
	foo(int time = 0, pii p = mp(0, 0)) : time(time), p(p) {}
};
inline bool operator<(foo a, foo b) {return a.time > b.time;}

priority_queue<foo> Q;

int T[111][111];

bool Solve(int test) {
	printf("Case #%d: ", test);
	scanf("%d %d %d", &W, &R, &C);
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			scanf("%d", Ceil[r] + c);
		}
	}
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			scanf("%d", Floor[r] + c);
		}
	}
	for(int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++) {
			T[r][c] = inf;
		}
	}
	T[0][0] = 0;
	Q.push(foo(0, mp(0, 0)));
	while(!Q.empty()) {
		foo f = Q.top();
		Q.pop();
		if(used(f.p, test)) continue;
		use(f.p, test);
		static int dr[] = {-1, 0, 1, 0};
		static int dc[] = {0, -1, 0, 1};
		for(int k = 0; k < 4; k++) {
			pii p = mp(f.p.row + dr[k], f.p.col + dc[k]);
			if(!valid(p)) continue;
			int time = max(f.time, canGo(f.p, p));
			if(time == 0.0) {
				T[p.row][p.col] = time;
				Q.push(foo(time, p));
			}
			else if(time < inf) {
				int w = W - time;// * 10.0;
				int dt = w - ff(f.p) >= 20 ? 10 : 100;
				if(T[p.row][p.col] > time + dt) {
					T[p.row][p.col] = time + dt;
					Q.push(foo(time + dt, p));
				}
			}
		}
	}
	printf("%.2lf\n", 0.1 * T[R - 1][C - 1]); 
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 0;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
		Solve(i);
	//*/while(Solve(++t));
	return 0;
}