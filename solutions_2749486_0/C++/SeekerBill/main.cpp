#include<stdio.h>
#include<string.h>
int map[1000][1000];
int map2[1000][1000];
char dic[1000][1000][500];
char ans[1000];
int main()
{
	int T,n;
	scanf("%d",&T);
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			map[i][j]=-1;
			map2[i][j]=-1;
		}
	}
	map[500][500]=0;
	int count=0;
	while(count<=500)
	{
		count++;
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<1000;j++)
			{
				if (map[i][j]==count-1)
				{
					if (i+count<1000)
					{
						map2[i+count][j]=count;
						dic[i+count][j][count]='E';
					}
					if (i-count>=0)
					{
						map2[i-count][j]=count;
						dic[i-count][j][count]='W';
					}
					if (j+count<1000)
					{
						map2[i][j+count]=count;
						dic[i][j+count][count]='N';
					}
					if (i-count>=0)
					{
						map2[i][j-count]=count;
						dic[i][j-count][count]='S';
					}
				}
			}
		}
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<1000;j++)
			{
				map[i][j]=map2[i][j];
			}
		}
	}
	for(int TT=1;TT<=T;TT++)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		X+=500;Y+=500;
		printf("Case #%d: ",TT);
		int steps=map[X][Y];
		ans[steps]=0;
		while(steps)
		{
			ans[steps-1]=dic[X][Y][steps];
			switch (dic[X][Y][steps])
			{
			case 'E':
				X-=steps;
				break;
			case 'W':
				X+=steps;
				break;
			case 'N':
				Y-=steps;
				break;
			case 'S':
				Y+=steps;
				break;
			}
			steps--;
		}
		printf("%s\n",ans);
	}
}