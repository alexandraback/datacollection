#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
using namespace std;

const int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int N, M, H;

int C[200][200], F[200][200];

inline bool inside(int x,int y){return x>=0&&x<N&&y>=0&&y<M;}

int D[200][200];

inline bool checkmx(int &a, int b)
{
	if(a < 0 || (b < a))
	{
		a = b;
		return true;
	}
	return false;
}

struct data
{
	int x, y, dis;
	inline data(int x=0,int y=0,int dis=0):x(x),y(y),dis(dis){};
};
bool operator < (const data&a, const data&b)
{
	return a.dis > b.dis;
}

int checktime(int t, int a, int b, int c, int d)
{
	//time to wait from (a,b) to (c,d) at time t
	if(F[c][d] + 50 > C[c][d]) return -1;
	if(F[a][b] + 50 > C[c][d]) return -1;
	if(F[c][d] + 50 > C[a][b]) return -1;
	int x = H - t + 50 - C[c][d];
	if(x < 0) x = 0;
	return x;
}

inline int checkcost(int t, int a, int b)
{
	int h = H - t;
	if(h >= F[a][b] + 20) return 10;
	else return 100;
}

void Dfs(int x,int y)
{
	if(D[x][y] > -1) return;
	D[x][y] = 0;
	for(int d=0;d<4;++d)
	{
		int tx = x + dir[d][0], ty = y + dir[d][1];
		if(!inside(tx,ty)) continue;
		if(checktime(0, x,y,tx,ty) == 0)
			Dfs(tx,ty);
	}
}

void run()
{
	scanf("%d %d %d", &H, &N, &M);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", &C[i][j]);
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			scanf("%d", &F[i][j]);
	memset(D, -1, sizeof(D));

	Dfs(0,0);

	if(D[N-1][M-1]>-1)
	{
		printf("0.0\n"); return ;
	}

	priority_queue<data> Q;
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(D[i][j] > -1)
				Q.push(data(i,j,0));
	while(!Q.empty())
	{
		data t = Q.top(); Q.pop();
		if(t.dis != D[t.x][t.y]) continue;
		
		int x = t.x, y = t.y, dis = t.dis;

		if(x == N-1 && y == M -1)
		{
			printf("%d.%d\n", dis/10, dis%10);
			return;
		}

		int tx, ty, tmp;
		for(int d = 0; d < 4; ++ d)
		{
			tx = x + dir[d][0], ty = y + dir[d][1];
			if(!inside(tx,ty)) continue;
			int wait = checktime(dis, x, y, tx, ty);
			if(wait < 0) continue;
			tmp = dis + wait + checkcost(dis + wait, x, y);
			if(checkmx(D[tx][ty], tmp))
				Q.push(data(tx,ty,tmp));
		}
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d: ",no);
		run();
	}
	return 0;
}