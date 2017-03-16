#include <stdio.h>

char field[50][50];
int r, c, count;

unsigned char fill(int x, int y)
{
	if(count)
	{
		int rem[9];
		int enc=0;
		int i, j, flag;

		for(i=-1; i<=1; i++)
			for(j=-1; j<=1; j++)
				if((i || j) && (i+x)>=0 && (i+x)<r && (j+y)>=0 && (j+y)<c && field[i+x][j+y]=='*')
				{
					if(count)
					{
						count--;
						field[i+x][j+y]='.';
						rem[enc]=(i+x)*50+(j+y);
						enc++;
					}
					else
						return 0;
				}
		flag=1;
		for(i=0; i<enc; i++) flag=flag && fill(rem[i]/50, rem[i]%50);
		return flag;
	}
	return 1;
}

int main()
{
	int t, m, i, j, k, flag;

	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%d %d %d", &r, &c, &m);

		printf("Case #%d:\n", i+1);

		flag=0;
		for(j=0; j<r; j++)
			for(k=0; k<c; k++)
			{
				if(!flag)
				{
					for(int jj=0; jj<r; jj++)
						for(int kk=0; kk<c; kk++)
							field[jj][kk]='*';

					count=r*c-m-1;
					field[j][k]='c';
					flag=fill(j, k);
				}
				else
					break;
			}

		if(flag)
		{
			for(j=0; j<r; j++)
			{
				for(k=0; k<c; k++)
					printf("%c", field[j][k]);
				printf("\n");
			}
		}
		else
			printf("Impossible\n");
	}

	return 0;
}
