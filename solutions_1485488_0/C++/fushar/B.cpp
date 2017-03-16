/* by Ashar Fuadi [fushar] */

#include <cstdio>
#include <cstring>

#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define RESET(c,v) memset(c, v, sizeof(c))

typedef long long ll;

#define pb push_back
#define mp make_pai

const int MAX = 105, oo = 999999999;

int T, H, N, M;
int C[MAX][MAX], F[MAX][MAX];
int dist[MAX][MAX][1005];
bool seen[MAX][MAX][1005];

struct grid
{
	int x, y, h, d;
	bool operator<(const grid& o) const
	{
		return d > o.d;
	}
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
	scanf("%d\n", &T);
	REP(tc, T)
	{
		scanf("%d%d%d", &H, &N, &M);
		REP(i, N) REP(j, M)
			scanf("%d", &C[i][j]);
		REP(i, N) REP(j, M)
			scanf("%d", &F[i][j]);
		
		REP(i, N) REP(j, M) REP(h, 1005)
			dist[i][j][h] = oo;
		RESET(seen, false);
		
		priority_queue<grid> Q;
		dist[0][0][0] = 0;
		Q.push((grid){0, 0, 0, 0});
		
		while (!Q.empty())
		{
			int x = Q.top().x;
			int y = Q.top().y;
			int h = Q.top().h;
			Q.pop();
			
			if (seen[x][y][h])
				continue;
			seen[x][y][h] = true;
			
			if (x == N-1 && y == M-1)
			{
				printf("Case #%d: %d.%d\n", tc+1, dist[x][y][h]/10, dist[x][y][h]%10);
				break;
			}
			
			// turun saja
			if (H - (h+1) >= 0)
			{
				if (dist[x][y][h+1] > dist[x][y][h] + 1)
				{
					dist[x][y][h+1] = dist[x][y][h] + 1;
					Q.push((grid){x, y, h+1, dist[x][y][h+1]});
				}
			}
			
			// gerak
			REP(k, 4)
			{
				int nx = x + dx[k], ny = y + dy[k];
				if (nx<0 || nx>=N || ny<0 || ny>=M)
					continue;
				
				if (F[x][y] + 50 > C[nx][ny])
					continue;
				if (F[nx][ny] + 50 > C[nx][ny])
					continue;
				if (H-h + 50 > C[nx][ny])
					continue;
				if (F[nx][ny] + 50 > C[x][y])
					continue;
				
				/*
				int wait = 0;
				if (H-h*10 + 50 > C[nx][ny])
					wait = H-h*10 + 50 - C[nx][ny];
				*/
				int cost;
				if (F[x][y]+20 <= H-h)
					cost = 10;
				else
					cost = 100;
				int nh = min(H, h+cost);
				if (h == 0)
					cost = 0, nh = 0;
				
				if (dist[nx][ny][nh] > dist[x][y][h] + cost)
				{
					dist[nx][ny][nh] = dist[x][y][h] + cost;
					Q.push((grid){nx, ny, nh, dist[nx][ny][nh]});
				}
			}
		}
	}
}
