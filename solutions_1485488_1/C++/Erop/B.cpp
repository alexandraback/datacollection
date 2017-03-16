#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const double EPS = 1e-9;
int H, N, M;
int C[200][200];
int F[200][200];
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};
bool used[200][200];
set<pair<int, pii> > S;
int dist[200][200];
void dfs(int x, int y)
{
	if (used[x][y]) return;
	used[x][y] = true;
	dist[x][y] = -H;
	pii coord = pii(x, y);
	S.insert(make_pair(-H, coord));
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dirx[i];
		int ny = y + diry[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

		int mf = max(H, F[x][y]);
		int hf = max(H, F[nx][ny]);
		
		if (C[nx][ny] - hf < 50) continue;
		if (C[x][y] - hf < 50) continue;
		if (C[nx][ny] - mf < 50) continue;

		dfs(nx, ny);
	}
}
void solve()
{
	scanf ("%d%d%d", &H, &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf ("%d", &C[i][j]);
			used[i][j] = false;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf ("%d", &F[i][j]);
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	dfs(0, 0);
	while (!S.empty())
	{
		pii t = S.begin()->second;
		S.erase(S.begin());
		int x = t.first;
		int y = t.second;
		for (int i = 0; i < 4; ++i)
		{
			int h = -dist[t.first][t.second];
			int nx = x + dirx[i];
			int ny = y + diry[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			int mf = F[x][y];
			int hf = F[nx][ny];			
			if (C[nx][ny] - hf < 50) continue;
			if (C[x][y] - hf < 50) continue;
			if (C[nx][ny] - mf < 50) continue;

			h = min(h, C[x][y] - 50);
			h = min(h, C[nx][ny] - 50);
			if (h - F[x][y] >= 20)
			{
				h -= 10;
			}
			else
			{
				h -= 100;
			}

			h = -h;
			if (dist[nx][ny] > h)
			{
				dist[nx][ny] = h;
				S.insert(make_pair(h, pii(nx, ny)));
			}
		}
	}
	printf("%.2lf\n", (dist[N-1][M-1]+H)/10.);
}
int main()
{
#ifdef _DEBUG
	freopen("Btest.txt", "r", stdin);
	freopen("Bout.txt", "w", stdout);
#endif
	int T;
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}