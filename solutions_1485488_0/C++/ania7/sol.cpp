#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;

#define infty 1000000100
#define maxn 111

int px[4] = {1,0,-1,0}, py[4] = {0,1,0,-1};
int C[maxn][maxn], F[maxn][maxn];
int t_in[maxn][maxn][4], t_walk[maxn][maxn];
int vis[maxn][maxn], dist[maxn][maxn];

double test()
{
	int N,M,H0;
	scanf("%d%d%d", &H0, &N, &M);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) scanf("%d", &C[i][j]);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) scanf("%d", &F[i][j]);


	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
	{
		t_walk[i][j] = H0 - F[i][j] - 20;
		for(int k = 0; k < 4; k++)
		{
			int x = i+px[k], y = j+py[k];
			if(x < 0 || y < 0 || x >= N || y >= M)
			{
				t_in[i][j][k] = infty;
			}
			else if(F[i][j] + 50 > C[x][y] || F[x][y] + 50 > C[x][y] || F[x][y] + 50 > C[i][j])
			{
				t_in[i][j][k] = infty;
			}
			else
			{
				t_in[i][j][k] = H0 + 50 - C[x][y];
			}
			//printf("t_in[%d][%d][%d] = %d\n", i,j,k,t_in[i][j][k]);
		}
		vis[i][j] = 0;
		dist[i][j] = infty;
		//printf("t_walk[%d][%d] = %d\n", i, j, t_walk[i][j]);
	}


	queue<int> q;
	vis[0][0] = 1;
	dist[0][0] = 0;
	q.push(0);
	q.push(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		for(int k = 0; k < 4; k++) if(t_in[x][y][k] < 0)
		{
			int nx = x+px[k], ny = y+py[k];
			if(vis[nx][ny] == 0)
			{
				vis[nx][ny] = 1;
				dist[nx][ny] = 0;
				q.push(nx);
				q.push(ny);
			}
		}
	}
	set<pair<int, pair<int,int> > > S;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		S.insert(make_pair(dist[i][j], make_pair(i,j)));

	while(!S.empty())
	{
		pair<int,int> p = S.begin() -> second;
		S.erase(*S.begin());
		int x = p.first, y = p.second;
		//printf("x = %d, y = %d, dist = %d\n", x, y, dist[x][y]);

		for(int k = 0; k < 4; k++) if(t_in[x][y][k] <= infty-1)
		{
			//printf("k = %d\n", k);
			int T = dist[x][y];
			if(T < t_in[x][y][k]) T = t_in[x][y][k];
			if(T <= t_walk[x][y]) T += 10;
			else T += 100;
			int nx = x+px[k], ny = y+py[k];

			//printf("T = %d, dist = %d\n", T, dist[nx][ny]);

			if(T < dist[nx][ny])
			{
				S.erase(S.find(make_pair(dist[nx][ny], make_pair(nx, ny))));
				dist[nx][ny] = T;
				S.insert(make_pair(dist[nx][ny], make_pair(nx,ny)));
			}
		}
	}

	return dist[N-1][M-1] / 10.0;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for(int i = 1; i <= tt; i++)
		printf("Case #%d: %.7lf\n", i, test());
	return 0;
}
