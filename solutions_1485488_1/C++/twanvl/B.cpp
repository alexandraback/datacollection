#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N=101, MAX_M=101;
int floor  [MAX_N][MAX_M];
int ceiling[MAX_N][MAX_M];
int reached[MAX_N][MAX_M];//time when reached
int n,m;
int h0;
struct Point {
	int x,y;
	int t;
	Point(){}
	Point(int x,int y, int t):x(x),y(y),t(t){}
	inline bool operator < (Point const& that) const {
		return t > that.t; // pq is maxheap
	}
};
priority_queue<Point> reach;

void read() {
	scanf("%d %d %d",&h0,&n,&m);
	for (int y=0 ; y<n ; ++y) {
		for (int x=0 ; x<m ; ++x) {
			scanf("%d",&ceiling[y][x]);
		}
	}
	for (int y=0 ; y<n ; ++y) {
		for (int x=0 ; x<m ; ++x) {
			scanf("%d",&floor[y][x]);
		}
	}
}

int height(int t) {
	if (t <= 0) return h0;
	return max(0,h0 - t);
}
void rp(int x, int y, int t) {
	if (reached[y][x] > t) {
		reached[y][x] = t;
		reach.push(Point(x,y,t));
	}
}
void move(int x0,int y0,int t0, int x1,int y1) {
	// ..
	if (floor[y1][x1] > ceiling[y0][x0]-50) return;
	if (floor[y0][x0] > ceiling[y1][x1]-50) return;
	if (floor[y1][x1] > ceiling[y1][x1]-50) return;
	// needed water level
	int l = min(ceiling[y0][x0]-50, ceiling[y1][x1]-50);
	int tm = max(t0, h0-l);
	int t1;
	//fprintf(stdout," Level at (%d,%d) = %d vs %d\n",x0,y0,h0-tm, floor[y0][x0]+20);
	if (tm <= 0) {
		t1 = 0; // before
	} else {
		tm = max(0,tm);
		if (h0-tm >= floor[y0][x0]+20) {
			t1 = tm+10;
		} else {
			t1 = tm+100;
		}
	}
	rp(x1,y1,t1);
}

int solve() {
	// clear
	for (int y=0 ; y<n ; ++y) {
		for (int x=0 ; x<m ; ++x) {
			reached[y][x] = INT_MAX;
		}
	}
	reach = priority_queue<Point>();
	rp(0,0,0);
	
	// go
	while (!reach.empty()) {
		Point p = reach.top();
		reach.pop();
		//fprintf(stderr,"Reached (%d,%d) at %d  [%d/%d | %d = %d]\n",p.x,p.y,p.t, floor[p.y][p.x],h0-p.t, ceiling[p.y][p.x], ceiling[p.y][p.x]-max(floor[p.y][p.x],h0-p.t));
		if (p.y == n-1 && p.x == m-1) return max(0,p.t);
		if (reached[p.y][p.x] < p.t) continue;
		if (p.x-1>=0) move(p.x,p.y,p.t, p.x-1, p.y);
		if (p.x+1< m) move(p.x,p.y,p.t, p.x+1, p.y);
		if (p.y-1>=0) move(p.x,p.y,p.t, p.x, p.y-1);
		if (p.y+1< n) move(p.x,p.y,p.t, p.x, p.y+1);
	}

	fprintf(stderr,"FAILED\n");

	return 0;
}

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0 ; i < n ; ++i) {
		read();
		int s = solve();
		printf("Case #%d: %d.%d\n",i+1,s/10,s%10);
	}
}

