#include <stdio.h>
#include <string.h>
const int maxn=11;
int num[maxn][4];
char str[5];
int index(char ch)
{
	switch(ch)
	{
		case 'X':
			return 0;
		case 'O':
			return 1;
		case 'T':
			return 2;
		case '.':
			return 3;
		default:
			return -1;
	}
}
int main()
{
	int T,t,temp,flag,i,j;
	scanf("%d",&T);
	t=1;
	while(T--)
	{
		flag=0;
		memset(num,0,sizeof(num));
		for(i=0;i<4;i++)
		{
			scanf("%s",str);
			for(j=0;j<4;j++)
			{
				temp=index(str[j]);
				num[i][temp]++;
				num[4+j][temp]++;
				if(i==j)
					num[8][temp]++;
				if(i==3-j)
					num[9][temp]++;
			}
		}
		for(i=0;i<10;i++)
		{
//			printf("%d %d %d %d\n",num[i][0],num[i][1],num[i][2],num[i][3]);
			if(num[i][3])
			{
				flag=1;
				continue;
			}
			if(num[i][2]<2)
			{
				if(num[i][1]==0)
				{
					flag=2;
					break;
				}
				else if(num[i][0]==0)
				{
					flag=3;
					break;
				}
			}
		}
		printf("Case #%d: ",t++);
		switch(flag)
		{
			case 0:
				printf("Draw\n");
				break;
			case 1:
				printf("Game has not completed\n");
				break;
			case 2:
				printf("X won\n");
				break;
			case 3:
				printf("O won\n");
				break;
			default:
				break;
		}
	}
	return 1;
}