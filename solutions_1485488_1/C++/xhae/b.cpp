#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int h, n, m;
int ceil[100][100], floor[100][100];

priority_queue <pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
queue <pair<int, int> > bfs;
bool isVisit[100][100];

const int mov[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dist[100][100];

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		scanf("%d %d %d", &h, &n, &m);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", ceil[i]+j);
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", floor[i]+j);

		while(!q.empty()) q.pop();
		while(!bfs.empty()) bfs.pop();
		
		memset(isVisit, 0, sizeof(isVisit));
		bfs.push(make_pair(0, 0));
		isVisit[0][0] = true;
		q.push(make_pair(0, make_pair(0, 0)));

		while(!bfs.empty())
		{
			pair <int, int> cur = bfs.front();
			bfs.pop();

			q.push(make_pair(0, cur));
			for(int i=0;i<4;i++)
			{
				int ny = cur.first + mov[i][0];
				int nx = cur.second + mov[i][1];

				if(ny>=0 && ny<n && nx>=0 && nx<m && !isVisit[ny][nx])
				{
					int curFloor = max(h, floor[cur.first][cur.second]);
					int tarFloor = max(h, floor[ny][nx]);

					if(ceil[ny][nx] - 50 >= curFloor && ceil[ny][nx] - 50 >= tarFloor && ceil[cur.first][cur.second] - 50 >= tarFloor)
					{
						isVisit[ny][nx] = true;
						q.push(make_pair(0, make_pair(ny, nx)));
						bfs.push(make_pair(ny, nx));
					}
				}
			}
		}

		memset(dist, -1, sizeof(dist));

		while(!q.empty())
		{
			pair<int, int> cur;
			int curDist;
			while(!q.empty())
			{
				cur = q.top().second;
				curDist = q.top().first;
				q.pop();
				if(dist[cur.first][cur.second] == -1) break;				
			}

			if(dist[cur.first][cur.second] != -1) break;
			dist[cur.first][cur.second] = curDist;

			for(int i=0;i<4;i++)
			{
				int ny = cur.first + mov[i][0];
				int nx = cur.second + mov[i][1];

				if(ny>=0 && ny<n && nx>=0 && nx<m && dist[ny][nx]==-1)
				{
					if(ceil[ny][nx] - floor[ny][nx] < 50) continue;
					if(ceil[ny][nx] - floor[cur.first][cur.second] < 50) continue;
					if(ceil[cur.first][cur.second] - floor[ny][nx] < 50) continue;

					int waterHeight = h - curDist;
					int cost = 0;					
					if(ceil[ny][nx] - waterHeight < 50) cost = max(cost, waterHeight - (ceil[ny][nx] - 50));

					int left = waterHeight - floor[cur.first][cur.second] - cost;
					if(left >= 20) q.push(make_pair(curDist + cost + 10, make_pair(ny, nx)));
					else q.push(make_pair(curDist + cost + 100, make_pair(ny, nx)));
				}
			}
		}

		printf("Case #%d: %d.%d\n", caseN, dist[n-1][m-1]/10, dist[n-1][m-1]%10);
	}

	return 0;
}
