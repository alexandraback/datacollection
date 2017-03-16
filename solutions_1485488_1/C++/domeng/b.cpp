#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;
const int D=4;
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};
double ps[100][100][D];

int H,N,M;
int Floor[100][100],Ceil[100][100];
double Reach[100][100];
int Visit[100][100];

double openTime(int c1,int h1,int c2,int h2,int lv)
{
	if (c2+50>h2) return -1; 
	if (c2+50>h1) return -1;
	if (c1+50>h2) return -1;
	if (lv+50<=h1 && lv+50<=h2) return 0;
	return max(50-h2+lv,0)*.1;
}
int main()
{
	openTime(10,140,10,1000,100); 
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		fprintf(stderr,"%d-",kase);
		scanf("%d %d %d",&H,&N,&M);
		for (int q=0;q<N;++q) for(int w=0;w<M;++w)
			scanf("%d",&Ceil[q][w]);
		for (int q=0;q<N;++q) for(int w=0;w<M;++w)
			scanf("%d",&Floor[q][w]);
		for (int q=0;q<N;++q) for (int w=0;w<M;++w) for (int e=0;e<D;++e)
		{
			int y = q + dy[e];
			int x = w + dx[e];
			if (y<0 || y>=N || x<0 || x>=M)
				ps[q][w][e] = -1;
			else 
				ps[q][w][e] = openTime(Floor[q][w],Ceil[q][w],Floor[y][x],Ceil[y][x],H);
		}
		memset(Visit,0,sizeof(Visit));
		queue<int> Q; Q.push(0);
		while (!Q.empty())
		{
			int z = Q.front(); Q.pop();
			int y = z/1000, x = z % 1000;
			Visit[y][x] = 1;
			Reach[y][x] = 0;
			for (int e=0;e<D;++e)
				if (ps[y][x][e]>=0 && ps[y][x][e]<1E-06 && Visit[y+dy[e]][x+dx[e]]==0)
				{
					Visit[y+dy[e]][x+dx[e]]=1;
					Q.push((y+dy[e])*1000+(x+dx[e]));
				}
		}
		fprintf(stderr,"a");
		while (true)
		{
			int y=-1,x=-1;
			for (int q=0;q<N;++q) for (int w=0;w<M;++w)
				if (Visit[q][w] == 1)
					if (y<0 || Reach[q][w] < Reach[y][x])
						y=q,x=w;
			if (y<0) break;
			Visit[y][x] = 2;
			for (int e=0;e<D;++e) //dir
			{
				if (ps[y][x][e]<0) continue;
				double tm = max(Reach[y][x],ps[y][x][e]);
				double simLevel = H - 10 * tm;
				double simReach = tm + ((simLevel >= Floor[y][x] + 20 - 1E-08) ? (1.) : (10.));
				int yy = y + dy[e];
				int xx = x + dx[e];
				if (Visit[yy][xx] == 0 || Reach[yy][xx] > simReach)
				{
					Visit[yy][xx] = 1;
					Reach[yy][xx] = simReach;
				}
			}
		}
		fprintf(stderr,"b\n");

		printf("Case #%d: %.2lf\n",kase,Reach[N-1][M-1]);
	}
	return 0;
}