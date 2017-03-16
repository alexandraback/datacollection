#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = 3.1415926535;
const double eps = 1e-6;

struct TL {
	double a, b, c;
}L, A;
struct TP {
	double x, y;
	TP () {}
	TP (double a, double b) {x = a, y = b;}
}P, E, rec[11000][6];
int n, m, d, tot, who[110][110], sx, sy;
char ma[110][110];

double det(TP a, TP b, TP c) {
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
}
double dot(TP a, TP b, TP c) {
	return (c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y);
}
bool across(TL a, TL b, TP &c) {
	if (fabs(a.b * b.a - b.b * a.a) < eps) return 0;
	c.y = (b.c * a.a - a.c * b.a) / (a.b * b.a - b.b * a.a);
	c.x = (b.c * a.b - a.c * b.b) / (a.a * b.b - b.a * a.b);
	return 1;
}
void getL(TP a, TP b, TL &c) {
	c.a = b.y - a.y;
	c.b = a.x - b.x;
	c.c = -(c.a * b.x + c.b * b.y);
}
bool online(TP a, TP b, TP c) {
	return dot(a, b, c) < -eps;
}
bool online2(TP a, TP b, TP c) {
	return dot(a, b, c) < eps;
}
double sqr(double x) {
	return x * x;
}
double dis(TP a, TP b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double dis2(TP a, TP b) {
	return (sqr(a.x - b.x) + sqr(a.y - b.y));
}
void update(TP &a, TP b, TP c) {
	if (dis2(a, c) > dis2(b, c)) a = b;
}
vector <pair<int, int> > ap;
int work(TP s, TP dir) {
	double D = 0; int ni, nj;
	while (D < d + eps) {
		TP M = dir;
		getL(s, dir, L);
		if (online(E, s, dir) && fabs(det(E, s, dir)) < 1e-3) M = E;
		for (int i = 0; i < tot; i++) {
			getL(rec[i][0], rec[i][2], A);
			if (across(L, A, P) && online(P, rec[i][0], rec[i][2]) && online(P, s, dir)) update(M, P, s);
			getL(rec[i][1], rec[i][3], A);
			if (across(L, A, P) && online(P, rec[i][1], rec[i][3]) && online(P, s, dir)) update(M, P, s);
		}
		if (fabs(M.x - E.x) < eps && fabs(M.y - E.y) < eps) {
			return dis(E, s) + D < d + eps;
		}
		int id;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) if (ma[i][j] == '#')
				if (i - 0.5 <= M.x + eps && M.x <= i + 0.5 + eps && j - 0.5 <= M.y + eps && M.y <= j + 0.5 + eps)
					id = who[i][j], ni = i, nj = j;
		M = dir;
		for (int i = 0; i < 4; i++) {
			getL(rec[id][i], rec[id][i + 1], A);
			if (across(L, A, P) && online2(P, rec[id][i], rec[id][i + 1])) update(M, P, s);
		}
		int C = 0;
		ap.clear();
		for (int i = ni - 1; i <= ni + 1; i++)
			for (int j = nj - 1; j <= nj + 1; j++)
				if (0 <= i && i < n && 0 <= j && j < m && ma[i][j] == '#')
					if (i - 0.5 <= M.x + eps && M.x <= i + 0.5 + eps && j - 0.5 <= M.y + eps && M.y <= j + 0.5 + eps) {
						C++; ap.PB(MP(i, j));
					}
		if (C == 3) {
			D += dis(s, M);
			dir.x = -(dir.x - s.x), dir.y = -(dir.y - s.y);
			s = M;
			dir.x += s.x, dir.y += s.y;
		} else if (C == 1) {
			D += dis(s, M);
			dir.x -= s.x, dir.y -= s.y;
			bool flag = 0;
			for (int i = 0; i < 4; i++)
				if (online(M, rec[id][i], rec[id][i + 1])) {
					if (rec[id][i].x == rec[id][i + 1].x) dir.x = -dir.x;
					else dir.y = -dir.y;
					flag = 1;
				}
			s = M;
			dir.x += s.x, dir.y += s.y;
			if (!flag) break;
		} else if (C == 2) {
			D += dis(s, M);
			dir.x -= s.x, dir.y -= s.y;
			if (ap[0].first != ap[1].first) dir.y = -dir.y;
			else dir.x = -dir.x;
			s = M;
			dir.x += s.x, dir.y += s.y;
		} else
			cout << endl;
	}
	return 0;
}
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		tot = 0;
		scanf("%d%d%d", &n, &m, &d);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf(" %c", &ma[i][j]);
				if (ma[i][j] == 'X') {
					sx = i, sy = j;
					E = TP(sx, sy);
				}
				if (ma[i][j] == '#') {
					rec[tot][0] = TP(i - 0.5, j - 0.5);
					rec[tot][1] = TP(i + 0.5, j - 0.5);
					rec[tot][2] = TP(i + 0.5, j + 0.5);
					rec[tot][3] = TP(i - 0.5, j + 0.5);
					rec[tot][4] = rec[tot][0];
					who[i][j] = tot;
					tot++;
				}
			}
		int ans = 0;
		for (int dx = -d; dx <= d; dx++)
			for (int dy = -d; dy <= d; dy++)
				if ((abs(dx) + abs(dy) > 0) && __gcd(abs(dx), abs(dy)) == 1) {
					ans += work(TP(sx, sy), TP(sx + dx * 1000, sy + dy * 1000));
//					cout << dx << ' ' << dy << ' ' << ans << endl;
				}
			
		printf("Case #%d: %d\n", ++ca, ans);
	}
}
