#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <time.h>
using namespace std;
typedef long long llong;

inline int bit(int x, int i){ return (x>>i) & 1;}
inline int setb(int x, int i){ return x | (1 << i);}
inline int clrb(int x, int i){ return x & (~(1 << i));}
inline int lowb(int x){return x & (-x);}

int x[200], y[200];
int nx, ny;

struct Point{
	int x, y;
	Point(){}
	Point(int x, int y):x(x), y(y){}
};
struct cmp{
	bool operator ()(const Point &p, const Point &q){
		if(p.x == 0 && p.y == 0) return q.x || q.y;
		bool sp = p.y > 0 || (p.y == 0 && p.x >= 0);
		bool sq = q.y > 0 || (q.y == 0 && q.x >= 0);
		if(sp != sq) return sp;
		else return p.x * q.y - p.y * q.x > 0;
	}
};

int solve(int L, int R, int U, int D, int dist){
	nx = 0;
	x[nx++] = 0;
	int xx = -L;
	for(int i = 0; abs(xx) <= dist; ++i){
		x[nx++] = xx;
		if(i % 2 == 0) xx -= R;
		else xx -= L;
	}
	xx = R;
	for(int i = 0; abs(xx) <= dist; ++i){
		x[nx++] = xx;
		if(i % 2 == 0) xx += L;
		else xx += R;
	}

	ny = 0;
	y[ny++] = 0;
	int yy = -D;
	for(int i = 0; abs(yy) <= dist; ++i){
		y[ny++] = yy;
		if(i % 2 == 0) yy -= U;
		else yy -= D;
	}
	yy = U;
	for(int i = 0; abs(yy) <= dist; ++i){
		y[ny++] = yy;
		if(i % 2 == 0) yy += D;
		else yy += U;
	}

	set<Point, cmp> vst;
	int cnt = 0;
	for(int i = 0;i < nx; ++i){
		for(int j = 0;j < ny; ++j){
			int xx = x[i], yy = y[j];
			if(xx == 0 && yy == 0) continue;
			if(xx * xx + yy * yy <= dist * dist &&
			    vst.find(Point(xx, yy)) == vst.end()){
					++cnt;
					vst.insert(Point(xx, yy));
				}
		}
	}
	return cnt;
}
char room[35][35];
int H, W, D;
int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("Ds0.txt", "w", stdout);
	
	int TT;
	scanf("%d", &TT);
	for(int cas = 1; cas <= TT; ++cas){
		scanf("%d %d %d", &H, &W, &D);
		for(int i = 0;i < H; ++i) scanf("%s", room[i]);
		int x0 , y0;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(room[i][j] == 'X') x0 = i, y0 = j;
			}
		}
		printf("Case #%d: %d\n", cas,
			solve(2 * y0 - 1, 2 * (W - 1 - y0) - 1, 2 * x0 - 1, 2 * (H - 1 - x0) - 1, D));
	}

	return 0;
}

