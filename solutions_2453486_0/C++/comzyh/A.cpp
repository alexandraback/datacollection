#include <cstdio>
#include <cstring>
int T;
int map[5][5];
int main()
{
	scanf("%d",&T);
	char str[20];
	for (int TT=1;TT<=T;TT++)
	{
		gets(str);
		int empty=0;
		memset(map,0,sizeof(map));
		for (int i=1;i<=4;i++)
		{
			gets(str);
			for (int j=0;j<4;j++)
			switch(str[j])
			{
				case 'X':
					map[i][j+1]=1;
					break;
				case 'O':
					map[i][j+1]=2;
					break;
				case 'T':
					map[i][j+1]=3;
					break;
				case '.':
					map[i][j+1]=0;
					empty++;
					break;
			}
		}
		
		// for (int i=1;i<=4;i++)
		// {
			// for (int j=0;j<=4;j++)
		// }
		printf("Case #%d: ",TT);
		
		int suml[5]={0,3,3,3,3},sumr[5]={0,3,3,3,3},sumx1=3,sumx2=3,ans;
		for (int i=1;i<=4;i++)
		{
			suml[1]&=map[1][i];
			suml[2]&=map[2][i];
			suml[3]&=map[3][i];
			suml[4]&=map[4][i];
			sumr[1]&=map[i][1];
			sumr[2]&=map[i][2];
			sumr[3]&=map[i][3];
			sumr[4]&=map[i][4];
			sumx1&=map[i][i];
			sumx2&=map[i][5-i];
		}
		ans=0;
		for (int i=1;i<=4;i++)
			ans|=(suml[i]|sumr[i]);
		ans|=sumx1;
		ans|=sumx2;
		if (ans)
		{
			if (ans==1)
				printf("X won\n");
			else
				printf("O won\n");
		}
		else
		{
			if (empty)
				printf("Game has not completed\n");
			else
				printf("Draw");
		}
	}
}
