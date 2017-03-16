#include <cstdio>

inline int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	for(int cn=1;cn<=t;cn++)
	{
		
		int r,c,m;
		scanf("%d %d %d", &r, &c, &m);
		
		bool possible = true;
		
		
		printf("Case #%d:\n", cn);
		
		if(r>1 && c>1 && m>c*r-4 && m<c*r-1)
		{
			possible = false;
		}
		
		int map[100][100];
		for(int y=0;y<100;y++) for(int x=0;x<100;x++) map[y][x] = 0;
		
		
		for(int y=0;y<r-2;y++)
		{
			for(int x=0;x<c-2;x++)
				if(m) { map[y][x]=1; m--; }
		}
		for(int y=0;y<r-3;y++)
		{
			for(int x=max(0,c-2);x<c;x++)
			{
				if(m==1 && x==c-2)
				{
					if(c>=3)
					{
						map[r-3][c-3] = 0;
						m++;
					}
					else
					{
						possible = false;
					}
				}
				if(m) { map[y][x]=1; m--; }
			}
		}
		for(int x=0;x<c-3;x++)
		{
			for(int y=max(0,r-2);y<r;y++)
			{
				if(m==1 && y==r-2)
				{
					if(r>=3)
					{
						map[r-3][c-3] = 0;
						m++;
					}
					else
					{
						possible = false;
					}
				}
				if(m) { map[y][x]=1; m--; }
			}
		}
		
		if(r>=3 && m>0)
		{
			if(m==1 && c>1)
				possible = false;
			else
			{
				int y = r-3;
				for(int x=max(0,c-2);x<c;x++)
				{
					map[y][x]=1;
					m--;
				}
			}
		}
		if(c>=3 && m>0)
		{
			if(m==1 && r>1)
				possible = false;
			else
			{
				int x = c-3;
				for(int y=max(0,r-2);y<r;y++)
				{
					map[y][x]=1;
					m--;
				}
			}
		}
		if(r==1 && c>1 && m>0)
		{
			map[0][c-2]=1;
			m--;
		}
		if(c==1 && r>1 && m>0)
		{
			map[r-2][0]=1;
			m--;
		}
		if(r>1 && c>1)
		{
			if(m==3)
			{
				map[r-2][c-1] = 1;
				map[r-2][c-2] = 1;
				map[r-1][c-2] = 1;
				m-=3;
			}
		}
		
		if(!possible || m>0)
			printf("Impossible\n");
		else
		for(int y=0;y<r;y++)
		{
			for(int x=0;x<c;x++)
			{
				if(x==c-1 && y==r-1)
					printf("c");
				else if(map[y][x])
					printf("*");
				else
					printf(".");
			}
			printf("\n");
		}
	}
}
