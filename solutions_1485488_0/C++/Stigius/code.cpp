#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 0

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}


int top[100][100];
int bottom[100][100];
int dist[100][100];
const int infty = 1e9;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int w,h;
int h0;
std::set<std::pair<int, pii> > heap;

int move(int x, int y, int d, int hh)
{
	int nx = x + dx[d], ny = y + dy[d];
	dbg("move %d %d, %d %d\n", x, y, d, hh);
	if (nx < 0 || nx >= w || ny < 0 || ny >= h)
		return infty;
	dbg("----> (%d-%d), (%d-%d)\n", bottom[x][y], top[x][y], bottom[nx][ny], top[nx][ny]);
	if (bottom[x][y] > top[nx][ny] - 50 || top[x][y] < bottom[nx][ny] + 50)
		return infty;
	dbg("Fail1\n");
	if (bottom[nx][ny] > top[nx][ny] - 50)
		return infty;
	dbg("Success\n");
	int maxh = top[nx][ny] - 50;
	return std::max(0, hh - maxh);
}

void dijkstra()
{
	while(!heap.empty())
	{
		pii pos = heap.begin()->second;
		int x = pos.first;
		int y = pos.second;
		int t = heap.begin()->first;
		heap.erase(heap.begin());
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + move(x, y, i, h0 - t);
			if (h0 - nt >= bottom[x][y] + 20)
				nt += 10;
			else
				nt += 100;
			if (nt < dist[nx][ny])
			{
				heap.erase(heap.find(std::make_pair(dist[nx][ny], pii(nx, ny))));
				dist[nx][ny] = nt;
				heap.insert(std::make_pair(dist[nx][ny], pii(nx, ny)));
			}
		}
	}
}

void dfs(int x, int y, int hh)
{
	if (dist[x][y] == 0)
		return;
	dist[x][y] = 0;
	for(int i = 0; i < 4; i++)
		if (move(x, y, i, hh) == 0)
			dfs(x + dx[i], y + dy[i], hh);
}

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	scanf("%d%d%d", &h0, &w, &h);
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
			scanf("%d", &top[i][j]);
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
			scanf("%d", &bottom[i][j]);
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
			dist[i][j] = infty;
	dfs(0,0,h0);
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
			heap.insert(std::make_pair(dist[i][j], pii(i,j)));
	dijkstra();
	printf("%.10lf\n", dist[w-1][h-1] / 10.);
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
