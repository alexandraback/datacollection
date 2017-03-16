#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

int test;
int n;
int m;
int h;
int f[110][110];
int c[110][110];
double time[110][110];
bool was[110][110];
int minx,miny;
void change(int x1, int y1, int x2, int y2)
{
	double water = h - 10*time[x1][y1];
	double water_time = 0;
	if (f[x2][y2] > (c[x2][y2] - 50))
		return;
	if (f[x2][y2] > (c[x1][y1] - 50))
		return;
	if (f[x1][y1] > (c[x2][y2] - 50))
		return;
	if (water > (c[x2][y2] - 50))
	{
		water_time = (water - (c[x2][y2] - 50))*1.0 / 10;
		water = c[x2][y2] - 50;
	}
	if ((time[x1][y1] == 0) && (water_time == 0))
	{
		time[x2][y2] = 0;
	}
	else
	{
		if (water-f[x1][y1] >= 20)
		{
			time[x2][y2] = min(time[x2][y2],time[x1][y1]+1+water_time);
		}
		else
		{
			time[x2][y2] = min(time[x2][y2],time[x1][y1]+10+water_time);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&test);
	for(int t = 1; t <= test; t++)
	{
		scanf("%d%d%d",&h,&n,&m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d",&c[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				scanf("%d",&f[i][j]);
				was[i][j] = 0;
				time[i][j] = 2000000000;				
			}
		time[0][0] = 0;
		while(true)
		{
			minx = n-1;
			miny = m-1;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
				{
					if ((!was[i][j])&&(time[i][j] < time[minx][miny]))
					{
						minx = i;
						miny = j;
					}
				}
			was[minx][miny] = 1;
			if ((minx == n-1)&&(miny == m-1))
				break;
			if (minx > 0)
				change(minx,miny,minx-1,miny);
			if (minx < n-1)
				change(minx,miny,minx+1,miny);
			if (miny > 0)
				change(minx,miny,minx,miny-1);
			if (miny < m-1)
				change(minx,miny,minx,miny+1);
		}
		printf("Case #%d: %0.6f\n",t,time[n-1][m-1]);
	}
	return(0);
}