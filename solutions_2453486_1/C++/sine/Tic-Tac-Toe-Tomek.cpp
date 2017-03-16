#include <stdio.h>

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("l.out", "w", stdout);

	int t, cas;
	int i, j;
	int x, o;
	int f, res;
	char borad[4][4];

	scanf("%d\n", &t);
	for (cas=1; cas<=t; cas++)
	{
		f=0;
		for (i=0; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				scanf("%c", &borad[i][j]);
				if (borad[i][j]=='.') f=1;
			}
			getchar();
		}
		getchar();
		res=-1;
		for (i=0; i<4; i++)
		{
			x=0;
			o=0;
			for (j=0; j<4; j++)
			{
				switch(borad[i][j])
				{
				case 'X': x++; break;
				case 'O': o++; break;
				case 'T': x++; o++; break;
				}
			}
			if (x==4) res=0;
			else if (o==4) res=1;
		}
		if (res<0)
		{
			for (i=0; i<4; i++)
			{
				x=0;
				o=0;
				for (j=0; j<4; j++)
				{
					switch(borad[j][i])
					{
					case 'X': x++; break;
					case 'O': o++; break;
					case 'T': x++; o++; break;
					}
				}
				if (x==4) res=0;
				else if (o==4) res=1;
			}
		}
		if (res<0)
		{
			x=0;
			o=0;
			for (j=0; j<4; j++)
			{
				switch(borad[j][j])
				{
				case 'X': x++; break;
				case 'O': o++; break;
				case 'T': x++; o++; break;
				}
			}
			if (x==4) res=0;
			else if (o==4) res=1;
		}
		if (res<0)
		{
			x=0;
			o=0;
			for (j=0; j<4; j++)
			{
				switch(borad[j][3-j])
				{
				case 'X': x++; break;
				case 'O': o++; break;
				case 'T': x++; o++; break;
				}
			}
			if (x==4) res=0;
			else if (o==4) res=1;
		}
		printf("Case #%d: ", cas);
		if (res<0)
		{
			if (f) printf("Game has not completed\n");
			else printf("Draw\n");
		}
		else if (res==0) printf("X won\n");
		else printf("O won\n");
	}
	return 0;
}