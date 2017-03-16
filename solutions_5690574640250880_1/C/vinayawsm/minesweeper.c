#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	int turn =1;
	while(turn<=t)
	{
		int r,c,m;
		scanf("%d %d %d",&r,&c,&m);
		char a[60][60]={'.'};
		int i=0,j=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				a[i][j]='.';
			}
		}
		int mines=m;
		int flag=0;
		if(r==1 || c==1)
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					if(mines>0)
					{
						a[i][j]='*';
						mines--;
					}
					else break;
				}
			}
			a[r-1][c-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}

		if(c==2 && !(m == (r*c)-1))
		{
			if(m%2==1)
				goto imp;
			if(m>(r*c)-4)
				goto imp;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					if(mines>0)
					{
						a[i][j]='*';
						mines--;
					}
					else break;
				}
			}
			a[r-1][c-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}

		if(r==2 && !(m == (r*c)-1))
		{
			if(m%2==1)
				goto imp;
			if(m>(r*c)-4)
				goto imp;
			for(j=0;j<c;j++)
			{
				for(i=0;i<r;i++)
				{
					if(mines>0)
					{
						a[i][j]='*';
						mines--;
					}
					else break;
				}
			}
			a[r-1][c-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}
		
	/*	if(m==(r-2)*c-1 || m==(r-2)*c+1)////////////wrong
			goto imp;

		if(m > (r-2)*c && m < (r*c))
		{
			if((m-((r-2)*c))%2==1)
				goto imp;
		}*/

		if(mines == (r*c)-1)
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					a[i][j]='*';
				}
			}
			a[r-1][j-1]='c';
			flag=1;
			printf("Case #%d:\n",turn);
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
			goto imp;
		}

		int h1=0;
		for(i=0;i<r-3;i++)
		{
			for(j=0;j<c;j++)
			{
				if(mines==1 && j==c-2)
				{
					h1=1;
					break;
				}
				if(mines>0)
				{
					a[i][j]='*';
					mines--;
				}
			}
			if(h1==1)
				break;
		}

		if(h1==1)
		{
			a[i+1][0]='*';
			mines--;
		}

		int h2=0;
		for(j=0;j<c;j++)
		{
			for(i=r-3;i<r;i++)
			{
				if(mines==1 && i==r-2)
				{
					h2=1;
					break;
				}
				if(mines==1 && j==c-2)
				{
					goto imp;
				}
				if(mines>0)
				{
					a[i][j]='*';
					mines--;
				}
				else break;
			}
			if(h2==1)
				break;
		}

		if(h2==1)
		{
			a[r-3][j+1]='*';
			mines--;
			if(j+1==c-2)
				goto imp;
		}

		a[r-1][c-1]='c';

		if(a[r-2][c-2]=='*' || a[r-1][c-2]=='*' || a[r-2][c-1]=='*')
			goto imp;

		flag=1;
		printf("Case #%d:\n",turn);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				printf("%c",a[i][j]);
			}
			printf("\n");
		}

		imp:
		if(flag==0)
		{
			printf("Case #%d:\n",turn);
			printf("Impossible\n");
		}

		turn++;
	}


	return 0;
}