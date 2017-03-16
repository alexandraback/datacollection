#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool field[20][20];
bool isVisited[20][20];
int n, m;

bool isBlocked(int y, int x)
{
	if(field[y][x]) return true;
	if(y == 0 || y == n - 1 || x == 0 || x == m - 1) return false;

	queue <pair<int, int>> q;
	q.push(make_pair(y, x));
	memset(isVisited, 0, sizeof(isVisited));
	isVisited[y][x] = true;
	while(!q.empty())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int ny = cy + mov[i][0];
			int nx = cx + mov[i][1];
			if(ny >= 0 && ny < n && nx >= 0 && nx < m && field[ny][nx] == false && isVisited[ny][nx] == false)
			{
				q.push(make_pair(ny, nx));
				isVisited[ny][nx] = true;
				if(ny == 0 || ny == n - 1 || nx == 0 || nx == m - 1) return false;
			}
		}
	}

	return true;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		int K;
		scanf("%d %d %d", &n, &m, &K);

		int lim = (n * m), ans = K;
		for(int i = 0; i < (1 << lim); i++)
		{
			memset(field, 0, sizeof(field));
			for(int j = 0; j < lim; j++)
			{
				if(i & (1 << j))
				{
					int y = j / m;
					int x = j % m;

					field[y][x] = true;
				}
			}

			int cand = __builtin_popcount(i);
			if(cand >= ans) continue;

			int cnt = 0;
			for(int i = 0; i < n && cnt <= K; i++)
				for(int j = 0; j < m && cnt <= K; j++)				
					cnt += isBlocked(i, j);

			if(cnt == K) ans = min(ans, cand);
		}
	
		printf("Case #%d: %d\n", kase, ans);
		fprintf(stderr, "Case #%d: %d\n", kase, ans);
	}

	return 0;
}
