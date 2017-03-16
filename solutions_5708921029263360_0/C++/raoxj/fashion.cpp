#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "memory.h"

int t;

int a,b,c;

int n;

int ans;

int max;

//0 = ab,1 = ac, 2 = bc
int used[3][20][20];

int best[1005];

int choice[1005];

void dfs(int d,int x,int y,int z)
{
	z++;
	if (d>a*b*c)
	{
		if (ans > max)
		{
			max = ans;
			memcpy(best,choice,sizeof(best));
		}
		return;
	}
	if (z > c)
	{
		z -= c;
		y ++;
	}
	if (y > b)
	{
		y -= b;
		x++;
	}
	if ((used[0][x][y] < n) && (used[1][x][z] < n) && (used[2][y][z] < n))
	{
		used[0][x][y] ++;
		used[1][x][z] ++;
		used[2][y][z] ++;
		ans ++;
		choice[d] = 1;
		dfs(d+1,x,y,z);
		choice[d] = 0;
		ans --;
		used[0][x][y] --;
		used[1][x][z] --;
		used[2][y][z] --;
	}
	dfs(d+1,x,y,z);
}

int main()
{
	int i,j,k,l;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		memset(used,0,sizeof(used));
		memset(best,0,sizeof(best));
		memset(choice,0,sizeof(choice));
		ans = 0;
		max = 0;
		scanf("%d %d %d %d",&a,&b,&c,&n);
		if (n>=c)
		{
			printf("Case #%d: %d\n",i+1,a*b*c);
			for (j=1;j<=a;j++)
			{
				for (k=1;k<=b;k++)
				{
					for (l=1;l<=c;l++)
					{
						printf("%d %d %d\n",j,k,l);
					}
				}
			}	
			continue;
		}
		dfs(1,1,1,0);
		printf("Case #%d: %d\n",i+1,max);
		int mark = 0;
		for (j=1;j<=a;j++)
		{
			for (k=1;k<=b;k++)
			{
				for (l=1;l<=c;l++)
				{
					mark ++;
					if (best[mark])
					{
						printf("%d %d %d\n",j,k,l);
					}
				}
			}
		}
	}
	return 0;
}
