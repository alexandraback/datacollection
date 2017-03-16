#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#define INF 1000000007
#define EPS 0.000000001
using namespace std;

int T,h,n,m,i,j,I,J,y,mov[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int a[111][111],b[111][111],c[111][111],d[111][111];
pair<int,int> x;
queue<pair<int,int> > q;

int f(int x1,int y1,int x2,int y2,int t,int l=false)
{
	if(a[x2][y2]-b[x2][y2]<50 || a[x2][y2]-b[x1][y1]<50 || a[x1][y1]-b[x2][y2]<50) return INF;
	if(!l)
		if(50-a[x2][y2]+h <=t)
			return 0; else
			return INF;
	int res = max(t,50-a[x2][y2]+h);
	if(h-res-b[x1][y1] < 20)
		res += 100; else
		res += 10;
	return res;
}

void g(bool l = false)
{
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(!c[i][j])
				q.push(make_pair(i,j));
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			I = x.first+mov[i][0];
			J = x.second+mov[i][1];
			if(I>=0 && I<n && J>=0 && J<m)
			{
				y = f(x.first,x.second,I,J,c[x.first][x.second],l);
				if(c[I][J]>y)
				{
					c[I][J] = y;
					q.push(make_pair(I,J));
				}
			}
		}
	}

}

int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%d%d",&h,&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				scanf("%d",&b[i][j]);
				c[i][j] = INF;
			}
		c[0][0] = 0;
		g();
		g(true);
		printf("%.1lf\n",c[n-1][m-1]*0.1);

	}
	return 0;
}