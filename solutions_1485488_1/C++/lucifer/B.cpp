#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 1e20
#define maxl 300
using namespace std;

struct node {
	int r, c;
	double d;
	node(int _r, int _c, double _d) : r(_r), c(_c), d(_d) {}
	node() {}
};

struct cmp {
	bool operator()(const node& a, const node& b) {
		return a.d > b.d;
	}
};

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int n, m, up[maxl][maxl], low[maxl][maxl], vis[maxl][maxl];
int h;
double d[maxl][maxl];

priority_queue<node, vector<node>, cmp> pq;

bool can(int r1, int c1, int r2, int c2, double t) {
	if(up[r2][c2] - low[r2][c2] < 50) return 0;
	if(up[r2][c2] - low[r1][c1] < 50) return 0;
	if(up[r1][c1] - low[r2][c2] < 50) return 0;
	return 1;
}

bool can_init(int r1, int c1, int r2, int c2, double t) {
	if(up[r2][c2] - low[r2][c2] < 50) return 0;
	if(up[r2][c2] - low[r1][c1] < 50) return 0;
	if(up[r1][c1] - h < 50) return 0;
	if(up[r2][c2] - h < 50) return 0;
	if(up[r1][c1] - low[r2][c2] < 50) return 0;
	return 1;
}

double calc_w(int r1, int c1, int r2, int c2, double t) {
	double nh = h - t * 10;
	if(nh < low[r1][c1]) nh = low[r1][c1];

	//double t1 = (up[r2][c2] - nh) >= 50 ? 0 : (50 - (up[r2][c2] - nh)) / 10.0;
	//double t2 = 

	if(up[r2][c2] - nh >= 50) {
		if(nh - low[r1][c1] >= 20) return 1;
		else return 10;
	}
	else {
		double wt = (50 - (up[r2][c2] - nh)) / 10.0;
		double hh = nh - wt * 10;
		if(hh - low[r1][c1] >= 20) return wt + 1;
		else return wt + 10;
	}
}

void push(int r, int c, double t) {
	node now(r, c, t);
	pq.push(now);
}

void dfs(int r, int c) {
	vis[r][c] = 1;
	for(int k=0; k<4; ++k) {
		int _r = r + dr[k];
		int _c = c + dc[k];

		if(_r < 0 || _r >= n || _c < 0 || _c >= m) continue;
		if(vis[_r][_c]) continue;
		if(!can_init(r, c, _r, _c, 0)) continue;
		dfs(_r, _c);
	}
}

void solve() {
	while(!pq.empty()) pq.pop();

	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) d[i][j] = INF;
	d[0][0] = 0;
	//push(0, 0, 0);
	//
	memset(vis, 0, sizeof vis);
	dfs(0, 0);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			if(vis[i][j]) {
				d[i][j] = 0;
				//printf("%d %d\n", i, j);
				push(i, j, 0);
			}
		}
	}

	while(!pq.empty()) {
		node now = pq.top();
		pq.pop();
		if(d[now.r][now.c] < now.d) continue;

		for(int k=0; k<4; ++k) {
			int _r = now.r + dr[k];
			int _c = now.c + dc[k];
			if(_r < 0 || _r >= n || _c < 0 || _c >= m) continue;
			if(!can(now.r, now.c, _r, _c, now.d)) continue;

			double w = calc_w(now.r, now.c, _r, _c, now.d);
			if(now.d + w < d[_r][_c]) {
				d[_r][_c] = now.d + w;
				push(_r, _c, d[_r][_c]);
			}
		}
	}
	printf("%.8lf\n", d[n-1][m-1]);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int q=1; q<=t; ++q) {
		scanf("%d%d%d", &h, &n, &m);
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) scanf("%d", &up[i][j]);
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) scanf("%d", &low[i][j]);

		printf("Case #%d: ", q);
		solve();
	}
	return 0;
}

