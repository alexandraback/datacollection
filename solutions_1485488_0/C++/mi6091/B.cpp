#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define mp make_pair

int n, m, h; 
int c[128][128];
int f[128][128];

double d[128][128];


struct cmp
{
	
	bool operator () (pair <int, double> p1, pair <int, double> p2)
	{
		return p1.second > p2.second; 
	}
};


bool check (int wlvl, int c2, int f2)
{
	if (c2 - wlvl >= 50) return true;
}

bool check1(int c1, int f1, int c2, int f2)
{
	if (c2 - f2 < 50) return 0;
	if (c2 - f1 < 50) return 0;
	if (c1 - f2 < 50) return 0;
	if (c2 - h < 50) return 0;
	return 1;
}

double gettime( int ct, int c1, int f1, int c2, int f2)
{
	if (c2 - f2 < 50) return -1;
	if (c2 - f1 < 50) return -1;
	if (c1 - f2 < 50) return -1;
	
	int water = h - ct * 10;
	
	if (water <= f1) 
		return 10; 
	
	if (c2 - water >= 50 && water - f1 >= 20)
		return 1;
	else
		if (c2 - water >= 50)
			return 10;
	
	/*	
	int f = 0,mid = 0,  l = (water - f1) + 1;
	
	while (f < l)
	{
		mid = f + (l - f)/2;
		if (check (water - mid, c2, f2))
			l = mid;
		else 
			f = mid + 1;
	}
	*/
	
	//if (f == water - f1 + 1) return -1;
	
	int fo = 50 - (c2 - water);
	//printf (">>%d\n", fo );
	if (water - fo - f1 >= 20)
		return (double)fo/10.0 + 1;
	else
		return (double)fo/10.0 + 10;
	
}

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};

void solve ()
{
	scanf ("%d%d%d",&h, &n, &m);
	
	int i, j; 
	
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			scanf ("%d", &c[i][j]), d[i][j] = 200000000;
	
		
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			scanf ("%d", &f[i][j]);
		
	priority_queue <pair <int, double>, vector <pair <int, double> >, cmp> q;
	
		q.push (mp (0, 0) );
	d[0][0] = 0; 
	while (!q.empty ())
	{
		pair <int, int> op = q.top (); q.pop();
		
		int x = op.first/100;
		int y = op.first%100;
		
		//printf ("%d %d %lf\n", x, y, d[x][y]);
		
		
		if (d[x][y] < op.second) continue;
		
		for (i = 0; i < 4; i ++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (x < 0 || x >= n) continue;
			if (y < 0 || y >= m) continue;
			
			int t = check1 (c[x][y], f[x][y], c[nx][ny], f[nx][ny]);
			
			if (t == 0) continue;
			if (h - c[x][y] < 20) t = 10;
			
			//printf ("->(%d, %d) -  %d\n", nx, ny, t);
			if (d[nx][ny] > d[x][y] + t)
			{
				d[nx][ny] = d[x][y] + t; 
				q.push (mp (nx * 100 + ny, d[nx][ny]));
			}
		}
		
	}

	while (!q.empty()) q.pop (); 
	
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
		{
			if (d[i][j] != 200000000)
			{
				q.push (mp (i * 100 + j, 0) );
				d[i][j] = 0;
			}
		}
		
	while (!q.empty ())
	{
		pair <int, int> op = q.top (); q.pop();
		
		int x = op.first/100;
		int y = op.first%100;
		
		//printf ("%d %d %lf\n", x, y, d[x][y]);
		
		
		if (d[x][y] < op.second) continue;
		
		for (i = 0; i < 4; i ++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (x < 0 || x >= n) continue;
			if (y < 0 || y >= m) continue;
			
			double t = gettime (d[x][y], c[x][y], f[x][y], c[nx][ny], f[nx][ny]);
			if (t < 0) continue; 
			//printf ("->(%d, %d) -  %d\n", nx, ny, t);
			if (d[nx][ny] > d[x][y] + t)
			{
				d[nx][ny] = d[x][y] + t; 
				q.push (mp (nx * 100 + ny, d[nx][ny]));
			}
		}
		
	}
	
	printf ("%lf\n", d[n-1][m-1]);
}

int main () 
{
	
	int t; 
	scanf ("%d", &t);
	
	for (int i = 1; i <=t; i ++)
		printf ("Case #%d: ", i), solve ();
	
	return 0;
}