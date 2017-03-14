#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <set>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

struct PtInfo {
	int x, y;
	int gx, gy;
	int distSqr;
	bool operator < (const PtInfo& rhs) const { return distSqr < rhs.distSqr; }
};

static inline int sqr(int x) { return x*x; }

int gcd(int a, int b)
{
	while (a && b) {
		b %= a;
		if (b) a %= b;
	}
	return a+b;
}

void solve(void)
{
	set<pair<int, int> >  ss;
	int W, H, D;
	char s[100];
	scanf("%d%d%d", &H, &W, &D);
	int ix, iy;
	FOR(y, H) {
		scanf("%s", s);
		FOR(x, W) {
			if (s[x] == 'X') {
				ix = x*2 - 1;
				iy = y*2 - 1;
			}
		}
	}
	W = (W - 2) * 2;
	H = (H - 2) * 2;
	D *= 2;
	vector<PtInfo> v;
	for (int i = -64; i <= 64; i++)
		for (int j = -64; j <= 64; j++) {
			if (i == 0 && j == 0) continue;
			PtInfo p;
			p.gx = j;
			p.gy = i;
			p.x = j * W;
			p.y = i * H;
			if ((j + 100) % 2) p.x += W - ix;
			else p.x += ix;
			if ((i + 100) % 2) p.y += H - iy;
			else p.y += iy;
			p.distSqr = sqr(p.x - ix) + sqr(p.y - iy);
			if (p.distSqr <= D*D)
				v.push_back(p);
		}
	sort(v.begin(), v.end());
	REP(ii, v) {
		int dx = v[ii].x - ix;
		int dy = v[ii].y - iy;
		int G = gcd(abs(dx), abs(dy));
		dx /= G;
		dy /= G;
		pair<int, int> key = make_pair(dx, dy);
		if (ss.find(key) == ss.end()) {
			ss.insert(key);
// 			printf("At (gx = %d, gy = %d, x = %d, y = %d), dist = %.3lf\n", v[ii].gx, v[ii].gy, v[ii].x, v[ii].y, sqrt(v[ii].distSqr));
		}
	}
	printf("%d\n", (int) ss.size());
}

int main(void)
{
// 	freopen("/home/vesko/gcj/d.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
