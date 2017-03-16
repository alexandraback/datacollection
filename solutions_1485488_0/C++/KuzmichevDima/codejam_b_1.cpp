#include <stdafx.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>

using namespace std;

const long maxn=15;
const long maxt=maxn*maxn*100;
const long dx[4]={1,0,0,-1};
const long dy[4]={0,1,-1,0};

bool pos[maxt][maxn][maxn];
long n,m,h;
long f[maxn][maxn];
long c[maxn][maxn];

bool trying1(long t,long x,long y,long x1,long y1)
{
	long w=h-t;
	long f1=f[x1][y1];
	long c1=c[x1][y1];
	if (c[x][y]-w<50) return(false);
	if (c[x][y]-f1<50) return(false);
	if (c[x][y]-f[x][y]<50) return(false);
	if (c1-f[x][y]<50) return(false);


	//if (w-f[x1][y1]>=20)
	//	printf("trying1 %ld %ld %ld %ld %ld\n",t,x,y,x1,y1);
	return(w-f[x1][y1]>=20);
}

bool trying2(long t,long x,long y,long x1,long y1)
{
	long w=h-t;
	long f1=f[x1][y1];
	long c1=c[x1][y1];
	if (c[x][y]-w<50) return(false);
	if (c[x][y]-f1<50) return(false);
	if (c[x][y]-f[x][y]<50) return(false);
	if (c1-f[x][y]<50) return(false);
	
	//printf("trying2 %ld %ld %ld %ld %ld\n",t,x,y,x1,y1);

	return(true);
}

void dfs(long x,long y)
{
	pos[0][x][y]=true;
	for (long move=0;move<=3;move++)
	{
		long x1=x+dx[move];
		long y1=y+dy[move];
		if ((x1<1)||(x1>n)||(y1<1)||(y1>m))
			continue;
		if (trying2(0,x1,y1,x,y))
			if (!pos[0][x1][y1])
				dfs(x1,y1);
	}
}

void solve()
{
	long t,x,y;
	long limit=n*m*100;
	for (t=0;t<=limit;t++)
		for (x=1;x<=n;x++)
			for (y=1;y<=m;y++)
				pos[t][x][y]=false;
	dfs(1,1);
	for (t=1;t<=limit;t++)
		for (x=1;x<=n;x++)
			for (y=1;y<=m;y++)
			{
				if (pos[t-1][x][y])
				{
					pos[t][x][y]=true;
					continue;
				}
				for (long move=0;move<=3;move++)
				{
					long x1=x+dx[move];
					long y1=y+dy[move];
					if ((x1<1)||(x1>n)||(y1<1)||(y1>m))
						continue;
					if ((t-10>=0)&&(pos[t-10][x1][y1]))
						if (trying1(t-10,x,y,x1,y1)) 
						{
							pos[t][x][y]=true;
							break;
						}
					if ((t-100>=0)&&(pos[t-100][x1][y1]))
						if (trying2(t-100,x,y,x1,y1)) 
						{
							pos[t][x][y]=true;
							break;
						}
				}
			}
	for (t=0;t<=limit;t++)
		if (pos[t][n][m])
		{
			printf("%0.1lf\n",(double)t/10.0);
			return;
		}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long tests;
	scanf("%ld",&tests);
	for (long test=1;test<=tests;test++)
	{
		scanf("%ld%ld%ld",&h,&n,&m);
		//h=h*10;
		long q,k;
		for (q=1;q<=n;q++)
			for (k=1;k<=m;k++)
				scanf("%ld",&c[q][k]);
		for (q=1;q<=n;q++)
			for (k=1;k<=m;k++)
				scanf("%ld",&f[q][k]);
		printf("Case #%ld: ",test);
		solve();
		//exit(0);
	}
}