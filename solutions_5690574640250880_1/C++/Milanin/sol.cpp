#include <stdio.h>
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		int r, c, m;
		char a[55][55];
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", t);
		for(int i=0; i<r; a[i][c]=0, i++)
			for(int j=0; j<c; a[i][j]='*', j++);
		int f=1;
		m=r*c-m;
		if(r==1)
			for(int j=0; m--; a[0][j]='.', j++);
		else if(c==1)
			for(int i=0; m--; a[i][0]='.', i++);
		else if(r==2)
		{
			if(m==2 || (m!=1 && m%2)) f=0;
			else
				for(int j=0; j<m/2; a[0][j]='.', a[1][j]='.', j++);
		}
		else if(c==2)
		{
			if(m==2 || (m!=1 && m%2)) f=0;
			else
				for(int i=0; i<m/2; a[i][0]='.', a[i][1]='.', i++);
		}
		else
		{
			if(m==1) f=1;
			else if(m==2 || m==3 || m==5 || m==7) f=0;
			else
			{
				int i, j;
				for(i=0; i<r && m>=2; a[i][0]='.', a[i][1]='.', m-=2, i++);
				if(m==1)
				{
					a[i-1][0]='*';
					a[i-1][1]='*';
					a[0][2]='.';
					a[1][2]='.';
					a[2][2]='.';
				}
				else
					for(j=2; j<c; j++)
					{
						for(i=0; i<r && m; a[i][j]='.', m--, i++);
						if(i==1)
						{
							a[i][j]='.';
							for(i=r-1; a[i][0]=='*'; i--);
							a[i][j-1]='*';
						}
					}
			}
		}
		a[0][0]='c';
		if(!f) printf("Impossible\n");
		else
			for(int i=0; i<r; printf("%s\n", a[i]), i++);
	}
	return 0;
}
