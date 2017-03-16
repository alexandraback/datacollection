#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

//////////////////// Defines ////////////////////

#pragma comment(linker, "/STACK:67108864")

#define inf      2147483647
#define inf64    9223372036854775807
#define eps      1e-7
#define pi      3.14159265358
#define sqr(a) (a)*(a)
#define rall(a) a.rbegin(),a.rend()
#define all(a) a.begin(),a.end()
#define sz(a) (a).size()
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back 
typedef long long ll;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define ContinueIf(x) if ((x)) continue
#define ContinueUnless(x) if(!(x)) continue

#define BreakIf(x) if ((x)) break
#define BreakUnless(x) if(!(x)) break

#define ReturnUnless(x) if (!(x)) return
#define ReturnIf(x) if ((x)) return

#define ReturnUnless2(x, ret) if (!(x)) return ret
#define ReturnIf2(x, ret) if ((x)) return ret

//////////////////// Problem Code ////////////////////
#define MAX 16

double board[MAX][MAX];
int f[MAX][MAX];
int c[MAX][MAX];

int dirs[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

struct State {
	int x, y;
	double t;

	State() {}
	State(int _x, int _y, int _t = 0) : x(_x), y(_y), t(_t) {}

	bool operator<(const State& s) const {
		return this->t > s.t;
	}
};

double getTimeToTransfer(double H, const State& from, const State& to) {
	if (c[from.x][from.y] - f[to.x][to.y] + eps < 50.0) {
		return -1.0;
	}

	if (c[to.x][to.y] - f[to.x][to.y] + eps < 50.0) {
		return -1.0;
	}

	if (c[to.x][to.y] - f[from.x][from.y] + eps < 50.0) {
		return -1.0;
	}
	
	double curr_water = H - 10 * from.t;
	double result = from.t;
	
	// Find the valid water level.
	double curr_floor = max((double)f[from.x][from.y], curr_water);
	if (c[to.x][to.y] - curr_floor + eps < 50.0) {
		// Wait for tide.
		double left = 50.0 - (c[to.x][to.y] - curr_floor);
		result += left / 10.0;
	}
	
	curr_water = H - 10 * result;
	if (c[to.x][to.y] - max(curr_water, (double)f[to.x][to.y]) + eps < 50.0) {
		// Wait for tide.
		double left = 50.0 - (c[to.x][to.y] - max(curr_water, (double)f[to.x][to.y]));
		result += left / 10.0;
	}

	curr_water = H - 10 * result;
	if (curr_water - f[from.x][from.y] + eps > 20.0) {
		result++;
	} else {
		result += 10;
	}

	return result;
}

bool isValid(double H, const State& from, const State& to) {
	if (c[from.x][from.y] - f[to.x][to.y] + eps < 50.0) {
		return false;
	}

	if (c[to.x][to.y] - max((double)f[to.x][to.y], H) + eps < 50.0) {
		return false;
	}

	// Find the valid water level.
	double curr_floor = max((double)f[from.x][from.y], H);
	if (c[to.x][to.y] - curr_floor + eps < 50.0) {
		return false;
	}

	return true;
}

void bfs(int H, int N, int M) {
	queue<State> q;
	q.push(State(0, 0));

	while (!q.empty()) {
		State cur = q.front();
		q.pop();
		board[cur.x][cur.y] = 0;

		for (int i = 0; i < 4; ++i) {
			State next(cur.x + dirs[0][i], cur.y + dirs[1][i]);
			if (next.x < 0 || next.x >= N) {
				continue;
			}

			if (next.y < 0 || next.y >= M) {
				continue;
			}

			if (!board[next.x][next.y]) {
				continue;
			}

			if (isValid(H, cur, next)) {
				q.push(next);
			}
		}
	}
}

double solve(int H, int N, int M) {
	bfs(H, N, M);
	priority_queue<State> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!board[i][j]) {
				q.push(State(i, j, 0));
			}
		}
	}
	
	while (!q.empty()) {
		State cur = q.top();
		q.pop();

		if (board[cur.x][cur.y] > -eps && board[cur.x][cur.y] + eps < cur.t) {
			continue;
		}

		board[cur.x][cur.y] = cur.t;
		if (cur.x == N - 1 && cur.y == M - 1) {
			break;
		}

		for (int i = 0; i < 4; ++i) {
			State next(cur.x + dirs[0][i], cur.y + dirs[1][i]);
			if (next.x < 0 || next.x >= N) {
				continue;
			}

			if (next.y < 0 || next.y >= M) {
				continue;
			}

			double tt = getTimeToTransfer(H, cur, next);

			if (tt < -eps) {
				continue;
			}

			next.t = tt;

			if (board[next.x][next.y] > -eps && board[next.x][next.y] + eps < next.t) {
				continue;
			}

			q.push(next);
		}
	}

	return board[N - 1][M - 1];
}

int main()
{
	int k, T;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &T);
	for(k = 1 ; k <= T ; ++k)
	{
		int H, N, M;
		scanf("%d%d%d", &H, &N, &M);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				board[i][j] = -1.0;
				scanf("%d", &c[i][j]);
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				scanf("%d", &f[i][j]);
			}
		}
		
		double result = solve(H, N, M);
		printf("Case #%d: %.6lf\n", k, result);
	}
	return 0;
}

