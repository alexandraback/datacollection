#include <cstdio>
#include <cstring>

int		H, n, m;

int		top	[110][110];
int		bot	[110][110];

void init()
{
	scanf("%d%d%d", &H, &n, &m);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", &top[i][j]);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			scanf("%d", &bot[i][j]);
}


const int MOD = 110 * 110;
int			qx	[MOD];
int			qy	[MOD];
int			head, tail;

bool		inq		[110][110];
double		dist	[110][110];

int			dx[] = {0, 0, 1, -1};
int			dy[] = {1, -1, 0, 0};

inline bool valid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

inline double max(double a, double b){ return a > b ? a : b; }

void solve()
{
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			dist[i][j] = 1e20;
	memset(inq, 0, sizeof(inq));

	head = 0; tail = 0;

	dist[0][0] = 0;
	qx[tail] = 0; qy[tail] = 0; tail ++;
	inq[0][0] = 1;

	while (head != tail)
	{
		int x = qx[head];
		int y = qy[head];
		head = (head + 1) % MOD;
		inq[x][y] = 0;

		for (int d = 0; d < 4; d ++)
		{
			if (valid(x + dx[d], y + dy[d]))
			{
				double t = dist[x][y];

				int px = x + dx[d];
				int py = y + dy[d];

				int lb = bot[x][y];
				int lt = top[x][y];

				int rb = bot[px][py];
				int rt = top[px][py];

				if (rt - rb < 50) continue;
				if (rt - lb < 50) continue;
				if (lt - rb < 50) continue;

				double current = max(lb, H - t * 10);
				double cost = 0;
				bool fall = t > 0;

				if (rt - current < 50)
				{
					cost += (current - (rt - 50)) / 10.0;
					current = rt - 50;
					fall = 1;
				}
				if (current - lb >= 20) cost += 1;
				else cost += 10;
				cost += dist[x][y];

				if (!fall) cost = 0;
				
				if (cost < dist[px][py])
				{
					dist[px][py] = cost;
					if (!inq[px][py])
					{
						inq[px][py] = 1;
						qx[tail] = px;
						qy[tail] = py;
						tail = (tail + 1) % MOD;
					}
				}
			}
		}
	}

	printf(" %.6lf\n", dist[n-1][m-1]);
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int caseNo;
	scanf("%d", &caseNo);

	for (int t = 1; t <= caseNo; t ++)
	{
		printf("Case #%d:", t);

		init();
		solve();
	}
	return 0;
}