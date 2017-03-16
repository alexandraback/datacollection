#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T,N,X,Y;
double ANSP;
int map[20][20];
void pri()
{
	for (int j=6;j>=0;j--)
	{
		for (int i=5;i<=15;i++)
			printf("%d ",map[i][j]);
		printf("\n");
	}	
}
int DFS(double P,int n)
{
	if (n>N)
		return 0;
	//printf("%d:P=%.5f\n",n,P);
	//pri();
	int x=10,y=18;
	while (y>0 && !map[x][y-2] )y-=2;
	if(y!=0)
	{
		if (map[x-1][y-1] && map[x+1][y-1])
		{
			//fixed;
			map[x][y]=1;
			if (x==X && Y==y)
				ANSP+=P;
			else
				DFS(P,n+1);
			map[x][y]=0;
		}
		else
		{
			int di=1;
			if (map[x-1][y-1]==0 && map[x+1][y-1]==0)
			{
				di=2;
				//printf("div at %4d,%4d\n",x,y);
			}
			int bx=x,by=y;
			if(map[x-1][y-1] || di==2)
			{
				//right
				while (y>0 && !(map[x-1][y-1] && map[x+1][y-1]))
				{
					x++;
					y--;
				}
				//printf("right %4d %4d di=%4d\n",x,y,di);
				map[x][y]=1;
				if (x==X && Y==y)
					ANSP+=P/di;
				else
					DFS(P/di,n+1);
				map[x][y]=0;
			}
			x=bx;y=by;
			if(map[x+1][y-1] || di==2)
			{
				//left
				
				while (y>0 && !(map[x-1][y-1] && map[x+1][y-1]))
				{
					x--;
					y--;
				}
				//printf("left  %4d %4d di=%4d\n",x,y,di);
				map[x][y]=1;
				if (x==X && Y==y)
					ANSP+=P/di;
				else
					DFS(P/di,n+1);
				map[x][y]=0;
			}
		}
	}
	else
	{
		map[x][y]=1;
		if (x==X && Y==y)
			ANSP+=P;
		else
			DFS(P,n+1);
		map[x][y]=0;
	}
	return 0;
}
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d%d%d",&N,&X,&Y);
		X+=10;
		ANSP=0;
		memset(map,0,sizeof(map));
		DFS(1.0,1);
		printf("Case #%d: %.9f\n",TT,ANSP);
	}
}