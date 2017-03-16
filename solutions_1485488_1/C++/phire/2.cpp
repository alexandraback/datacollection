#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int H, N, M;
int F[102][102];
int C[102][102];

double reach[102][102];

struct Coord
{
	int y, x;
	double val;
	Coord(int y, int x, double val) : y(y), x(x), val(val) { }
};

bool operator < (const Coord& l, const Coord& r)
{
	return l.val > r.val;
}

double when(int fy, int fx, int ty, int tx, double t)
{
	int h_needed;
	double t_needed;
	double cur_h;

	if (min(C[fy][fx], C[ty][tx]) < F[ty][tx] + 50)
		return 10e15;
	if (C[ty][tx] < F[fy][fx] + 50)
		return 10e15;

	h_needed = C[ty][tx] - 50;
	assert(h_needed >= 0);
	t_needed = H <= h_needed ? 0 : (H - h_needed) / 10.0;
	cur_h = max(0.0, H - 10.0 * t);

	if (t == 0.0) {
		if (H <= h_needed)
			return 0.0;

		if (h_needed >= F[fy][fx] + 20)
			return t_needed + 1;
		else
			return t_needed + 10;
	} else {
		if (cur_h <= h_needed) {
			if (cur_h >= F[fy][fx] + 20)
				return t + 1;
			else
				return t + 10;
		} else {
			if (h_needed >= F[fy][fx] + 20)
				return t_needed + 1;
			else
				return t_needed + 10;

		}
	}
}

double solve()
{
	priority_queue<Coord> q;
	q.push(Coord(1, 1, 0.0));
	while (!q.empty()) {
		const Coord c = q.top();
		if (reach[c.y][c.x] > c.val) {
			double d;
			reach[c.y][c.x] = c.val;

			if (c.y == N && c.x == M)
				break;

			d = when(c.y, c.x, c.y + 1, c.x, c.val);
			if (d < reach[c.y + 1][c.x])
				q.push(Coord(c.y + 1, c.x, d));

			d = when(c.y, c.x, c.y - 1, c.x, c.val);
			if (d < reach[c.y - 1][c.x])
				q.push(Coord(c.y - 1, c.x, d));

			d = when(c.y, c.x, c.y, c.x - 1, c.val);
			if (d < reach[c.y][c.x - 1])
				q.push(Coord(c.y, c.x - 1, d));

			d = when(c.y, c.x, c.y, c.x + 1, c.val);
			if (d < reach[c.y][c.x + 1])
				q.push(Coord(c.y, c.x + 1, d));
			
		}
		q.pop();
	}

	return reach[N][M];
}

int main(int argc, const char* argv[])
{
	int T;
	cin >> T;
	for(size_t i = 1; i <= T; ++i) {
		cin >> H >> N >> M;
		memset(F, 0, sizeof(F));
		memset(C, 0, sizeof(C));
		for (int j = 0; j < N; j++)
			for(int k = 0; k < M; k++)
				cin >> C[j + 1][k + 1];
		for (int j = 0; j < N; j++)
			for(int k = 0; k < M; k++)
				cin >> F[j + 1][k + 1];
		for (int j = 0; j < N + 2; j++)
			for(int k = 0; k < M + 2; k++)
				reach[j][k] = 10e15;
//		if (i == 29) {
//			ofstream f("/tmp/q");
//			f << H << " " << N << " " << M << endl;
//			for (int j = 0; j < N; j++) {
//				for(int k = 0; k < M; k++)
//					f << C[j + 1][k + 1] << ' ';
//				f << endl;
//			}
//			for (int j = 0; j < N; j++) {
//				for(int k = 0; k < M; k++)
//					f << F[j + 1][k + 1] << ' ';
//				f << endl;
//			}
//		}
		//reach[1][1] = 0.0;
		cout.precision(15);
		cout << "Case #" << i << ": " << solve() << endl;
	}
    return 0;
}
