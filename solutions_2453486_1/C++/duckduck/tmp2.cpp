#include <stdio.h>

const int maxn=4;

char map[maxn+1][maxn+1];
int i,j,k,m,n,t,tt,x,y;

bool check(char key)
{
	int i,j,k;

	map[x][y]=key;
	for (i=1;i<=4;i++)
	{
		if ((map[i][1]==key)&&(map[i][2]==key)&&(map[i][3]==key)&&(map[i][4]==key))
			return true;
		if ((map[1][i]==key)&&(map[2][i]==key)&&(map[3][i]==key)&&(map[4][i]==key))
			return true;
		if ((map[1][1]==key)&&(map[2][2]==key)&&(map[3][3]==key)&&(map[4][4]==key))
			return true;
		if ((map[4][1]==key)&&(map[3][2]==key)&&(map[2][3]==key)&&(map[1][4]==key))
			return true;
	}
	return false;
}
bool full()
{
	int i,j;

	for (i=1;i<=4;i++)
		for (j=1;j<=4;j++)
			if (map[i][j]=='.')
				return false;
	return true;
}


int main()
{
	//("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d\n",&t);
	for (int tt=1;tt<=t;tt++)
	{
		for (i=1;i<=4;i++)
		{
			for (j=1;j<=4;j++)
			{
				scanf("%c",&map[i][j]);
				if (map[i][j]=='T')
				{
					x=i;y=j;
				}
			}
			scanf("\n");
		}
		scanf("\n");
		printf("Case #%d: ",tt);
		if (check('X'))
		{
			printf("X won\n");
			continue;
		}
		if (check('O'))
		{
			printf("O won\n");
			continue;
		}
		if (full())
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}
