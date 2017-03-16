#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int cCeil[100][100];
int cFloor[100][100];

double reach[100][100];

bool solved[100][100];

typedef pair<int, int> pii;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
	int lz;
	scanf("%d", &lz);
	for (int tcase = 1; tcase <= lz; tcase++)
	{
		int h, n, m;
		scanf("%d%d%d", &h, &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) 
			{
				scanf("%d", &cCeil[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) 
			{
				scanf("%d", &cFloor[i][j]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) 
			{
				reach[i][j] = -1.0;
				solved[i][j] = false;
			}
		}

		int startX = 0;
		int startY = 0;

		reach[startX][startY] = 0.0;
		priority_queue<pair<double, pii> > pq;
		pq.push(pair<double, pii>(-reach[startX][startY], pii(startX, startY)));
		int done = 0;
		while(done < n*m && !pq.empty())
		{
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (solved[x][y])
			{
				continue;
			}

			solved[x][y] = true;
			done++;

			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if ( nx < 0 || nx >= n || ny < 0 || ny >= m)
				{
					continue;
				}
				if (solved[nx][ny])
				{
					continue;
				}
				
				if (cFloor[x][y] + 50 > cCeil[nx][ny] || cFloor[nx][ny] + 50 > cCeil[nx][ny])
				{
					continue;
				}
				if (cFloor[nx][ny] + 50 > cCeil[x][y])
				{
					continue;
				}

				double goDown  = max(0.0, h + 50.0 - (double)cCeil[nx][ny]);
				double opening = goDown / 10.0;

				double cTime = max(reach[x][y], opening);
				double water = max(0.0, h - cTime*10);
				double local = max(0.0, water - cFloor[x][y]);
				double prop = cTime + (opening == 0.0 && cTime == 0.0 ? 0.0 : (local >= 20.0 ? 1.0 : 10.0));
				if (reach[nx][ny] < 0.0 || reach[nx][ny] > prop)
				{
					reach[nx][ny] = prop;
					pq.push(pair<double, pii>(-reach[nx][ny], pii(nx,ny)));
				}
			}

		}
		printf("Case #%d: %.10lf\n", tcase, reach[n-1][m-1]);
	}
	return 0;
}