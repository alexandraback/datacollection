#pragma region predefinition
#define _CRT_SECURE_NO_DEPRECATE
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).size())
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, (n)-1)
#define C(a) memset((a), 0, sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())
#pragma endregion
//#define x first
//#define y second

int u[111][111], d[111][111], used[111][111], h, n, m;

struct cord {
	int x, y, t;
	cord (int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

inline bool operator < (const cord & a, const cord & b) {
	return a.t > b.t;
}

#define cn(x) (0 <= x && x < n)
#define cm(x) (0 <= x && x < m)

inline pii intersect(int lx, int rx, int ly, int ry) {
	return mp(max(lx, ly), min(rx, ry));
}

inline int count(int lx, int rx, int ly, int ry, int t) {
	pii a = intersect(lx, rx, ly, ry);
	if (a.second - a.first < 50) return -INF;
	while (h - t > 0) {
		pii a = intersect(lx, rx, ly, ry);
		a = intersect(a.first, a.second, h - t, INF);
		if (a.second - a.first >= 50) break;
		t++;
	}
	return t;
}

int solve() {
	priority_queue<cord, vector<cord> > Q;
	Q.push(cord(0, 0, 0));
	memset(used, 0, sizeof(used));
	int dx[] = {0, 1, 0, -1},
		dy[] = {1, 0, -1, 0};
	while (!Q.empty()) {
		cord cur = Q.top(); Q.pop();
		if (used[cur.x][cur.y]) continue;
		used[cur.x][cur.y] = true;
		if (cur.x == n - 1 && cur.y == m - 1) return cur.t;
		rept(k, 4) {
			cord w(cur.x + dx[k], cur.y + dy[k], 0);
			if (cn(w.x) && cm(w.y) && !used[w.x][w.y]) {
				int wt = count(d[cur.x][cur.y],	u[cur.x][cur.y], 
							   d[w.x][w.y],		u[w.x][w.y], 
							   cur.t);
				if (wt == -INF) continue;
				if (wt == 0) {
					assert(cur.t == 0);
					Q.push(cord(w.x, w.y, 0));
				} 
				else
				if (h - wt >= d[cur.x][cur.y] + 20) {
					Q.push(cord(w.x, w.y, wt + 10));
				}
				else {
					Q.push(cord(w.x, w.y, wt + 100));
				}
			}
		}
	}
	return INF;
}

int main()
{ 
	freopen("input.txt","rt",stdin); freopen("output.txt","wt",stdout); 
	int TC;
	scanf("%d", &TC);
	rept(tc, TC) {
		cerr << tc << endl;
		scanf("%d%d%d", &h, &n, &m);
		rept(i, n)
			rept(j, m)
				scanf("%d", &u[i][j]);
		rept(i, n)
			rept(j, m)
				scanf("%d", &d[i][j]);
		int t = solve();
		printf("Case #%d: %d.%d\n", tc + 1, t / 10, t % 10);
	}
	return 0;
}
