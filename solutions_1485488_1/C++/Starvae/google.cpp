#include  <stdio.h>   
#include <iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void FileIn()
{
	freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
}
int h;
int n,m;
int f[110][110];
int c[110][110];
double ans[110][110];
struct NODE
{
	int x,y;
};
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
double Work()
{
	NODE tmp;
	queue<NODE>Q;
	while(!Q.empty())
		Q.pop();
	tmp.x = 0;
	tmp.y = 0;
	ans[0][0] = 0;

	int f1,f2,c1,c2;
	double h1;
	Q.push(tmp);
	while(!Q.empty())
	{
		tmp = Q.front();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		for(int i = 0 ; i < 4; i ++)
		{
			x = tmp.x + dir[i][0];
			y = tmp.y + dir[i][1];
			if(x < 0 || y < 0 || x == n || y == m)
				continue;
			f1 = f[tmp.x][tmp.y];
			c1 = c[tmp.x][tmp.y];
			f2 = f[x][y];
			c2 = c[x][y];
			h1 = h - ans[tmp.x][tmp.y] * 10;
			if(c2 - f1 < 50 ||
				c2 - f2 < 50 ||
				c1 - f2 < 50)
				continue;
			if(c2 - h1 < 50)
			{
				h1 = c2 - 50;
			}
			double val;
			if(h1 - f1 >= 20)
				val = 1 + (h - h1)/10.0;
			else
				val = 10 + (h-h1)/10.0;
			if(h - h1 < 0.00000001)
				val = 0;
			if(ans[x][y] < 0 || ans[x][y] > val)
			{
				ans[x][y] = val;
				NODE ad;
				ad.x = x;
				ad.y = y;
				Q.push(ad);
			}
		}
	}
	return ans[n-1][m-1];
}
int main()
{
	FileIn();
	int T;
	int cas;

	scanf("%d",&T);
	cas = 1;
	while(T--)
	{
		scanf("%d%d%d",&h,&n,&m);
		
		for(int i = 0; i < n ; i ++)
		{
			for(int j = 0 ; j < m; j ++)
				scanf("%d",&c[i][j]);
		}
		for(int i = 0; i < n ; i ++)
		{
			for(int j = 0 ; j < m; j ++)
			{
				scanf("%d",&f[i][j]);
				ans[i][j] = -1;
			}
		}		

		printf("Case #%d: ",cas++);
		printf("%.7lf\n",Work());
	//	printf("\n");
	}
	return 0;
}
