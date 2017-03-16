#include <stdio.h>

char a[5][5];
char b[5][5];
int Xwin()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			b[i][j]=a[i][j];
			if(b[i][j]=='T')
				b[i][j]='X';
		}
	for(int i=0;i<4;i++)
	{
		if(b[i][0]=='X'&&b[i][1]=='X'&&b[i][2]=='X'&&b[i][3]=='X')
			return 1;
	}
	for(int i=0;i<4;i++)
	{
		if(b[0][i]=='X'&&b[1][i]=='X'&&b[2][i]=='X'&&b[3][i]=='X')
			return 1;
	}
	if(b[0][0]=='X'&&b[1][1]=='X'&&b[2][2]=='X'&&b[3][3]=='X')
		return 1;
	if(b[3][0]=='X'&&b[2][1]=='X'&&b[1][2]=='X'&&b[0][3]=='X')
		return 1;
	return 0;
}

int Owin()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			b[i][j]=a[i][j];
			if(b[i][j]=='T')
				b[i][j]='O';
		}
	for(int i=0;i<4;i++)
	{
		if(b[i][0]=='O'&&b[i][1]=='O'&&b[i][2]=='O'&&b[i][3]=='O')
			return 1;
	}
	for(int i=0;i<4;i++)
	{
		if(b[0][i]=='O'&&b[1][i]=='O'&&b[2][i]=='O'&&b[3][i]=='O')
			return 1;
	}
	if(b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O'&&b[3][3]=='O')
		return 1;
	if(b[3][0]=='O'&&b[2][1]=='O'&&b[1][2]=='O'&&b[0][3]=='O')
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	freopen("A-large.in","r",stdin);
	freopen("Aoutput.txt","w",stdout);
	int t,cass=1;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				a[i][j]=getchar();
			getchar();
		}
		getchar();
		/*for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}*/
		printf("Case #%d: ",cass++);
		if(Xwin())
		{
			printf("X won\n");
			continue;
		}
		if(Owin())
		{
			printf("O won\n");
			continue;
		}
		int f=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(a[i][j]=='.')
					f++;
		if(f)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	return 0;
}
