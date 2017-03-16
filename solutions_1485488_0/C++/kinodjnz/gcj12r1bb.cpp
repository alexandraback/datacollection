#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const int INF = (1<<29);

int H, N, M;
int c[102][102];
int f[102][102];

double dp[102][102];

bool in(int x, int y) {
	return (0 <= x && x < M && 0 <= y && y < N);
}

bool canmove(int x1, int y1, int x2, int y2, double t) {
	int cl = c[y2][x2]-50;
	if (cl < H-t*10 || cl < f[y1][x1] || cl < f[y2][x2]) {
		return false;
	}
	if (f[y2][x2] > c[y1][x1]-50) {
		return false;
	}
	return true;
}

void find_start(deque<pair<int, int> > &v) {
	while (!v.empty()) {
		pair<int, int> p = v.front();
		v.pop_front();
		int x = p.first;
		int y = p.second;
#define PUSH(X, Y) if (in(X, Y) && dp[Y][X] > 0 && canmove(x, y, X, Y, 0)) dp[Y][X]=0, v.push_back(make_pair(X, Y))
		PUSH(x-1, y);
		PUSH(x, y-1);
		PUSH(x+1, y);
		PUSH(x, y+1);
	}
}

double tidetime(int x1, int y1, int x2, int y2) {
	int cl = c[y2][x2]-50;
	if (H-cl <= 0)
		return 0.0;
	return (H-cl)/10.0;
}

double movetime(int x1, int y1, int x2, int y2, double t) {
	double u = tidetime(x1, y1, x2, y2);
	if (t < u)
		t = u;
	if (f[y1][x1]+20 <= H-t*10)
		return t+1;
	return t+10;
}

void calc(deque<pair<int, int> > &v) {
	while (!v.empty()) {
		pair<int, int> p = v.front();
		v.pop_front();
		int x = p.first;
		int y = p.second;
		double t = dp[y][x];
#define CPUSH(X, Y) if (in(X, Y) && canmove(x, y, X, Y, INF)) { \
			double t2 = movetime(x, y, X, Y, t); \
			if (dp[Y][X] > t2) dp[Y][X] = t2, v.push_back(make_pair(X, Y)); \
		}
		CPUSH(x-1, y);
		CPUSH(x, y-1);
		CPUSH(x+1, y);
		CPUSH(x, y+1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &H, &N, &M);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				scanf("%d", &c[y][x]);
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				scanf("%d", &f[y][x]);
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				dp[y][x] = INF;
			}
		}
		dp[0][0] = 0;
		deque<pair<int, int> > v;
		v.push_back(make_pair(0, 0));
		find_start(v);
#if 0
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				printf("%g ", dp[y][x]);
			}
			printf("\n");
		}
#endif
		v.clear();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (dp[y][x] == 0)
					v.push_back(make_pair(x, y));
			}
		}
		calc(v);
		printf("Case #%d: %.9f\n", i+1, dp[N-1][M-1]);
	}
}
