#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define maxit(x,y) ((x) = max((x),(y)))
#define minit(x,y) ((x) = min((x),(y)))
typedef long long LL;

#define N 111

const double inf = 1.0e60;
int dr[4] = { 0, 0,-1, 1};
int dc[4] = {-1, 1, 0, 0};
int H;
double cH;
int R, C;
int floor_plan[N][N], ceil_plan[N][N];
double dist[N][N];
typedef pair<int,int> PII;
typedef pair<double,PII> PDII;

bool inside(int r, int c)
{
	return 0 <= r && r < R && 0 <= c && c < C;
}

double initial_dist(int r1, int c1, int r2, int c2)
{
	if (cH > ceil_plan[r2][c2]-50.0) return inf;
	if (floor_plan[r1][c1] > ceil_plan[r2][c2]-50.0) return inf;
	if (floor_plan[r2][c2] > ceil_plan[r2][c2]-50.0) return inf;
	if (floor_plan[r2][c2] > ceil_plan[r1][c1]-50.0) return inf;
	return 0.0;
}

double tide_dist(int r1, int c1, int r2, int c2)
{
	cH = max(0.0, H - 10*dist[r1][c1]);
	if (initial_dist(r1, c1, r2, c2) == 0.0) {
		if (cH - floor_plan[r1][c1] >= 20.0)
			return 1.0;
		else
			return 10.0;
	}
	cH = 0.0;
	if (initial_dist(r1, c1, r2, c2) != 0.0) return inf;
	double lo = 0.0, hi = 1.0e7;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo+hi) / 2.0;
		cH = max(0.0, H - 10*(dist[r1][c1] + mid));
		if (initial_dist(r1,c1, r2,c2) == 0.0)
			hi = mid;
		else
			lo = mid;
	}
	double mid = (lo+hi) / 2.0;
	cH = max(0.0, H - 10*(dist[r1][c1] + mid));
	if (cH - floor_plan[r1][c1] >= 20.0)
		return mid + 1.0;
	else
		return mid + 10.0;
}

void dijkstra(double (*cost_fn)(int,int,int,int))
{
	dist[0][0] = 0.0;
	priority_queue<PDII> Q;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < R; ++c) {
			if (dist[r][c] < 10.0)
				Q.push(MP(dist[r][c], MP(r,c)));
		}
	}

	while (!Q.empty()) {
		double d;
		int r, c;

		d = Q.top().first;
		r = Q.top().second.first;
		c = Q.top().second.second;
		Q.pop();

		if (dist[r][c] != d) continue;

		for (int i = 0; i < 4; ++i) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (!inside(rr, cc)) continue;
			double dd = dist[r][c] + cost_fn(r,c, rr,cc);
			if (dd < dist[rr][cc]) {
				dist[rr][cc] = dd;
				Q.push(MP(dd, MP(rr,cc)));
			}
		}
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int ctc = 1; ctc <= TC; ++ctc) {
		scanf("%d %d %d", &H, &R, &C);
		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				scanf("%d", &ceil_plan[r][c]);
		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				scanf("%d", &floor_plan[r][c]);
		for (int r = 0; r < R; ++r)
			for (int c = 0; c < C; ++c)
				dist[r][c] = 1.0e50;

		cH = H;
		dijkstra(initial_dist);
		dijkstra(tide_dist);
		printf("Case #%d: %0.9lf\n", ctc, dist[R-1][C-1]);
		fflush(stdout);
	}
	return 0;
}
