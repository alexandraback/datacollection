#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define st first
#define nd second
#define mp make_pair

using namespace std;

int F[105][105];
int C[105][105];
int H,N,M;
double dist[105][105];
bool A[105][105];
bool V[105][105];
const int moves[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
vector<int> at_zero[2];

struct fd
{
	int x,y;
	double p;
	fd(int _x = 0, int _y = 0, double _p = 0.0)
	{
		x = _x;
		y = _y;
		p = _p;
	}
};

bool operator<(const fd &a, const fd &b)
{
	return a.p > b.p;
}

void read()
{
	scanf("%d%d%d", &H, &N, &M);
	for(int i = 0;i<N;i++)
		for(int j = 0;j<M;j++)
			scanf("%d", &C[i][j]);
	for(int i = 0;i<N;i++)
		for(int j = 0;j<M;j++)
			scanf("%d", &F[i][j]);
	at_zero[0].clear();
	at_zero[1].clear();
	for(int i = 0;i<N;i++)
		for(int j = 0;j<M;j++)
			A[i][j] = V[i][j] = false;
}

int achieveable(int x1, int y1, int x2, int y2, double t)
{
	if(x2 >= N || y2 >= M || x2 < 0 || y2 < 0)
		return 0;
	if(F[x2][y2] > C[x1][y1] - 50)
		return 0;
	if((double)C[x2][y2] < max((double)F[x1][y1], (double)H - t*10.0) + 50.0)
		return 0;
	if((double)H - t*10.0 - (double)F[x1][y1] >= 20.0)
		return 1;
	return 10;
}
void get_at_zero()
{
	V[0][0] = true;
	queue<pair<int,int> > Q;
	Q.push(mp(0,0));
	at_zero[0].push_back(0);
	at_zero[1].push_back(0);
	while(!Q.empty())
	{
		pair<int,int> v = Q.front();
		//printf("at zero in %d %d\n", v.st, v.nd);
		Q.pop();
		for(int i = 0;i<4;i++)
			if(achieveable(v.st, v.nd, v.st+moves[i][0], v.nd+moves[i][1],0.0) && !V[v.st+moves[i][0]][v.nd+moves[i][1]])
			{
				V[v.st+moves[i][0]][v.nd+moves[i][1]] = true;
				at_zero[0].push_back(v.st+moves[i][0]);
				at_zero[1].push_back(v.nd+moves[i][1]);
				Q.push(mp(v.st+moves[i][0],v.nd+moves[i][1]));
			}
			
	}
}
double get_waiting(int x1, int y1, int x2, int y2, double t)
{
	if(x2 >= N || y2 >= M || x2 < 0 || y2 < 0)
		return -1.0;
	if(F[x2][y2] > C[x1][y1] - 50)
		return -1.0;
	if(C[x2][y2] < F[x1][y1] + 50)
		return -1.0;
	return -(((double)C[x2][y2] - (double)H + 10.0*t - 50.0)/10.0) +0.0000001;
}
void dijkstra()
{
	priority_queue<fd> Q;
	for(int i = 0;i<at_zero[0].size();i++)
		Q.push(fd(at_zero[0][i], at_zero[1][i], 0.0));
	while(!Q.empty())
	{
		fd v = Q.top();
		Q.pop();
		if(A[v.x][v.y])
			continue;
		//printf("dajkstrin' in %d %d\n", v.x, v.y);
		A[v.x][v.y] = true;
		dist[v.x][v.y] = v.p;
		for(int i = 0;i<4;i++)
		{
			if(achieveable(v.x, v.y, v.x+moves[i][0], v.y + moves[i][1],v.p))
			{
				Q.push(fd(v.x+moves[i][0], v.y + moves[i][1], v.p + (double)achieveable(v.x, v.y, v.x+moves[i][0], v.y + moves[i][1],v.p)));
				continue;
			}
			double wait = get_waiting(v.x, v.y, v.x+moves[i][0], v.y + moves[i][1],v.p);
			//printf("waiting in %d %d for %lf\n", v.x, v.y, wait);
			if(wait < 0.0)
				continue;
			Q.push(fd(v.x+moves[i][0], v.y + moves[i][1], v.p + wait + (double)achieveable(v.x, v.y, v.x+moves[i][0], v.y + moves[i][1],v.p+wait)));
		}
	}
}
void process_case(int c)
{
	read();
	get_at_zero();
	dijkstra();
	printf("Case #%d: %lf\n", c, dist[N-1][M-1]);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1;i<=T;i++)
		process_case(i);
	return 0;
}
