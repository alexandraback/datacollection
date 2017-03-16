#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define eps (1e-9)
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>
#define equal(a,b) (ABS(a-b)<eps)
using namespace std;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }

int dx[8]={0, 0, 1,-1, 1, 1,-1,-1};
int dy[8]={1,-1, 0, 0,-1, 1,-1, 1};
int kx[8]={1, 1,-1,-1, 2, 2,-2,-2};
int ky[8]={2,-2, 2,-2, 1,-1, 1,-1};

/////////////////////////////////////////////////////////////////////////////////////////////////////

string fileName = "B-small-attempt0";

int n, m, h;
int lower[100][100];
int upper[100][100];
bool vis[100][100];
double d[100][100];
priority_queue<pair<double, Pair> > q;

bool can(int x1, int y1, int x2, int y2) {
	if (x2 < 0 || x2 >= n && y2 < 0 || y2 >= m || vis[x2][y2]) return false;
	if (upper[x2][y2] - lower[x2][y2] < 50) return false;
	if (lower[x1][y1] + 50 <= upper[x2][y2] && lower[x2][y2] + 50 <= upper[x1][y1]) return true;
	return false;
}

void add(int x, int y, double t) {
	q.push(mp(-t, mp(x, y)));
	d[x][y] = t;
}

void solveSingle(int testNumber) {
	memset(vis, false, sizeof(vis));
	scanf("%d%d%d", &h, &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = 1e50;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &upper[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &lower[i][j]);
	printf("Case #%d: ", testNumber);

	while(q.size()) q.pop();
	q.push(mp(0.0, mp(0, 0)));
	d[0][0] = 0.0;

	while (q.size()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (vis[x][y]) continue;
		vis[x][y] = true;
//		printf("%d %d %lf\n", x, y, d[x][y]);

		double now = d[x][y];
		for (int i = 0; i < 4; i++) {
			int x2 = x + dx[i], y2 = y + dy[i];
			if (can(x, y, x2, y2)) {
				int cur = max(h - (int)(now * 10 + 0.5), 0);
				int need = upper[x2][y2] - 50;
				double t;
				t = now;
				if (need >= cur) { // no need to wait
					if (cur != h) {
						if (cur - lower[x][y] >= 20) t += 1.0;
						else t += 10.0;
					}
				}
				else { // wait
					t += (cur - need) / 10.0;
					if (need - lower[x][y] >= 20) t += 1.0;
					else t += 10.0;
				}

				if (t < d[x2][y2])
					add(x2, y2, t);
			}
		}
	}
	printf("%.8lf\n", d[n - 1][m - 1]);
	fflush(stdout);
}

int main() {
	freopen((fileName + ".in").c_str(), "r", stdin);
	freopen((fileName + ".out").c_str(), "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		solveSingle(t);
	}
	return 0;
}
