#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double eps = 1e-8;

int T;
double dist[105 * 105];
double up[105][105], down[105][105];
double key[105 * 105 * 2];
int ckey;
int mark[105][105][10], rmark[105 * 105 * 10][3];
//alert
double f[105][105];
int q[105 * 105][2], qr;
bool vis[105][105];
double initwater;
int m, n;
priority_queue<pair<double, int> > heap;

struct Graph {
	static const int N = 105 * 105;
	static const int M = N * 10;
	int head[N];
	int next[M], dest[M], w[M];
	int tot;
	void clear()
	{ tot = 0; memset(head, 0, sizeof(head)); }
	void add(int x, int y, int z)
	{
		dest[++tot] = y; w[tot] = z;
		next[tot] = head[x]; head[x] = tot;
	}
} g;

void checkmin(double &a, double b)
{ if (b < a) a = b; }

void checkmax(double &a, double b)
{ if (b > a) a = b; }
double max(double a, double b)
{ return a > b ? a : b; }

double min(double a, double b)
{ return a < b ? a : b; }

bool inrange(int x, int y)
{ return x >= 1 && x <= m && y >= 1 && y <= n; }

bool canpass(int x, int y, int ux, int uy, double t)
{
	double water = initwater - t * 10;
	double curpos = max(water, down[x][y]);
	if (up[ux][uy] - curpos < 50 - eps) return false;
	if (up[ux][uy] - down[ux][uy] < 50 - eps) return false;
	if (up[x][y] - down[ux][uy] < 50 - eps) return false;
	return true;
}

double gettime(int x, int y, double t)
{
	double water = initwater - t * 10;
	if (water - down[x][y] > 20 - eps) return 1; else return 10;
}

int getinterval(int x, int y, double t)
{
	int l = 0, r = ckey;
	while (l + 1 < r) {
		int mid = l + r >> 1;
		if (t > key[mid] - eps) l = mid; else r = mid;
	}
	return l;
}

int getpt(int x, int y)
{ return (x - 1) * n + y; }

void work()
{
	scanf("%lf%d%d", &initwater, &m, &n);
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) scanf("%lf", &up[i][j]);
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) scanf("%lf", &down[i][j]);
	//
	ckey = 0;
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
		if (initwater > up[i][j] - 50 && up[i][j] - 50 >= down[i][j]) 
			key[ckey++] = (initwater - (up[i][j] - 50)) / 10;
		if (initwater > down[i][j] + 20 && down[i][j] + 20 <= up[i][j])
			key[ckey++] = (initwater - (down[i][j] + 20)) / 10;
	}
	key[ckey++] = 0;
	sort(key, key + ckey);
	ckey = unique(key, key + ckey) - key;
	key[ckey] = 1e99;
	
	//printf("ckey: "); for (int i = 0; i < ckey; ++i) printf("%0.2lf\n", key[i]);
	//
	for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j)
		f[i][j] = 1e99;
	f[1][1] = 0;
	qr = 1;
	q[1][0] = q[1][1] = 1;
	for (int l = 1; l <= qr; ++l) {
		int x = q[l][0], y = q[l][1];
		for (int k = 0; k < 4; ++k) {
			int ux = x + dx[k], uy = y + dy[k];
			if (inrange(ux, uy) && canpass(x, y, ux, uy, 0) && f[ux][uy] > eps) {
				++qr;
				q[qr][0] = ux;
				q[qr][1] = uy;
				f[ux][uy] = 0;
			}
		}
	}
	//
	double ans = 1e99;
	for (int l = 0; l < ckey; ++l) {
		g.clear();
		double tt = (key[l] + key[l + 1]) / 2;
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
			checkmax(f[i][j], key[l]);
		}
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
			int pt0 = getpt(i, j);
			int x = i, y = j;
			for (int k = 0; k < 4; ++k) {
				int ux = x + dx[k], uy = y + dy[k];
				int pt1 = getpt(ux, uy);
				if (!inrange(ux, uy) || !canpass(x, y, ux, uy, tt)) continue;
				g.add(pt0, pt1, gettime(x, y, tt));
			}
		}
		//
		while (!heap.empty()) heap.pop();
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) dist[getpt(i, j)] = f[i][j];
		for (int i = 1; i <= n * n; ++i) if (dist[i] > key[l] - eps && dist[i] < key[l + 1] - eps) 
			heap.push(make_pair(-dist[i], i));
		while (!heap.empty()) {
			pair<double, int> pdi = heap.top();
			heap.pop();
			double d = -pdi.first;
			int x = pdi.second;
			if (d != dist[x]) continue;
			for (int k = g.head[x]; k != 0; k = g.next[k]) {
				int y = g.dest[k];
				double z = g.w[k] + dist[x];
				if (z < dist[y] - eps && z > key[l] - eps && z < key[l + 1] - eps) {
					dist[y] = z;
					heap.push(make_pair(-dist[y], y));
				}
			}
		}
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) 
			f[i][j] = dist[getpt(i, j)];
		checkmin(ans, f[m][n]);
		//
		if (l == ckey - 1) break;
		for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) if (1 || f[i][j] < key[l + 1] - eps) {
			int pt0 = getpt(i, j);
			int x = i, y = j;
			for (int k = 0; k < 4; ++k) {
				int ux = x + dx[k], uy = y + dy[k];
				//printf("%d %d %d %d\n", x, y, ux, uy);
				int pt1 = getpt(ux, uy);
				if (!inrange(ux, uy) || !canpass(x, y, ux, uy, f[i][j])) continue;
				double ut = f[i][j] + gettime(x, y, f[i][j]);
				//printf("add update %d %d %d %d %0.2lf %0.2lf\n", x, y, ux, uy, f[i][j], ut);

				checkmin(f[ux][uy], ut);
			}
		}
		//printf("l=%d\n", l);
		//for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j)
		//	printf("f[%d][%d]=%0.2lf\n", i, j, f[i][j]);
	}
	static int ttt = 0;
	printf("Case #%d: %0.1lf\n", ++ttt, ans);
}
		
	
int main()
{
	scanf("%d", &T);
	while (T--) work();
}