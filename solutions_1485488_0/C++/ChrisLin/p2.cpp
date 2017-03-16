// p2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

struct node
{
	int x, y;
	double time;
};

int h, n, m, t;
int map[101][101];
int c[101][101];
int f[101][101];
double time[101][101];
bool visit[101][101];
int front, back;
node list[10000];

#define HEI 50
#define EPS 0.000001
const int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool pop(node *p)
{
	front++;
	if(front == 10000)
		front = 0;
	if(front == back)
		return false;
	*p = list[front];
	visit[p->x][p->y] = false;
	return true;
}

void push(node p)
{
	list[back++] = p;
	visit[p.x][p.y] = true;
	if(back == 10000)
		back = 0;
}


double canGo(int x1, int y1, int x2, int y2, double time)
{
	double wat = h - time * 10;
	if(c[x2][y2] - f[x2][y2] < HEI)
		return -1;
	if(c[x2][y2] - f[x1][y1] < HEI)
		return -1;
	if(c[x1][y1] - f[x2][y2] < HEI)
		return -1;
	if(c[x2][y2] - wat < HEI)
		return (wat - (c[x2][y2] - HEI))/10;
	return 0;
}

void firstRun(int x, int y)
{
	time[x][y] = 0;
	node p = {x,y,0};
	push(p);
	for(int i = 0; i < 4; i++)
	{
		int xx = x + d[i][0];
		int yy = y + d[i][1];
		if(xx < 0 || yy < 0 || xx >=n || yy >= m || time[xx][yy] < EPS)
			continue;
		if(canGo(x,y,xx,yy,0)>=-EPS && canGo(x,y,xx,yy,0)<= EPS)
			firstRun(xx,yy);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inFile("text.in");
	//ofstream outFile("ans.out");
	FILE *out = fopen("ans.out", "w");
	
	inFile >> t;

	for(int z = 1; z <=t; z++)
	{
		inFile >> h >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				inFile >> c[i][j];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				inFile >> f[i][j];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				time[i][j] = 100000000000;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				visit[i][j] = false;
		front = 0;
		back = 1;
		firstRun(0,0);
		node p;
		while(pop(&p))
		{
			int x = p.x;
			int y = p.y;
			for(int i = 0; i < 4; i++)
			{
				int xx = x + d[i][0];
				int yy = y + d[i][1];
				if(xx < 0 || yy < 0 || xx >=n || yy >= m)
					continue;
				double left = canGo(x,y,xx,yy,p.time);
				if(left >= -EPS)
				{
					node pt;
					double th = h - (p.time + left) * 10;

					if(th - f[p.x][p.y] >= 20)
						pt.time = p.time + left + 1;
					else
						pt.time = p.time + left + 10;

					pt.x = xx;
					pt.y = yy;

					if(pt.time < time[xx][yy])
					{
						time[xx][yy] = pt.time;
						if(visit[xx][yy] == false)
							push(pt);
					}
				}
			}
		}
		fprintf(out, "Case #%d: %.6lf\n", z, time[n-1][m-1]);
	}

	return 0;
}

