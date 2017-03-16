#include "cstdio"

char field[50][50];
int R,C,M;
int left;

bool foo(int y, int x)
{
	if(left == 0) return true;
	if(x == C-1 && y == R-1) return true;
	if(x == C-1)
	{
		if(field[y+1][x] == '*') return left == 0;
		else if(field[y+1][x] == 'x' && (x == 0 || field[y+1][x-1] == 'x'))
		{
			field[y+1][x] = '.';
			left--;
			return foo(y+1,x);
		}
		else return left == 0;
	}
	if(y == R-1)
	{
		if(field[y][x+1] == '*') return left == 0;
		else if(field[y][x+1] == 'x' && (y == 0 || field[y-1][x+1] == 'x'))
		{
			field[y][x+1] = '.';
			left--;
			return foo(y,x+1);
		}
		else return left == 0;
	}
	else
	{
		if(field[y+1][x] == '*' || field[y][x+1] == '*' || field[y+1][x+1] == '*' || (x > 0 && field[y+1][x-1] == '*') || (y > 0 && field[y-1][x+1] == '*'))
		{
			return left == 0;
		}
		bool ret = false;
		if(field[y+1][x] == 'x')
		{
			field[y+1][x] = '.';
			left--;
			ret = ret || foo(y+1,x);
		}
		if(field[y][x+1] == 'x')
		{
			field[y][x+1] = '.';
			left--;
			ret = ret || foo(y,x+1);
		}
		if(field[y+1][x+1] == 'x')
		{
			field[y+1][x+1] = '.';
			left--;
			ret = ret || foo(y+1,x+1);
		}
		return ret;
	}
}

void fill(int r, int c, int m)
{
	if(m == 0) return;
	if(m == 1)
	{
		field[r-1][c-1] = '*';
		return;
	}
	if(r == 1)
	{
		field[r-1][c-1] = '*';
		fill(r,c-1,m-1);
		return;
	}
	if(c == 1)
	{
		field[r-1][c-1] = '*';
		fill(r-1,c,m-1);
		return;
	}
	if(r == 2)
	{
		for(int i =0; i< r; i++) field[i][c-1] = '*';
		fill(r,c-1,m-r);
		return;
	}
	if(c == 2)
	{
		for(int i =0; i< c; i++) field[r-1][i] = '*';
		fill(r-1,c,m-c);
		return;
	}
	if(r == 3)
	{
		if((m - c + 2) % 2 == 1 && r * c - 1 != m)
		{
			for(int i = 3; i< c; i++) field[r-1][i] = '*';
			fill(r-1,c,m - c + 3);
			return;
		}
		if(m < c)
		{
			for(int i = c - m; i< c; i++) field[r-1][i] = '*';
			return;
		}
		for(int i = 0; i< c; i++) field[r-1][i] = '*';
		fill(r-1,c,m - c);
		return;
	}
	if(c == 3)
	{
		if((m - r + 2) % 2 == 1 && r * c - 1 != m)
		{
			for(int i = 3; i< r; i++) field[i][c-1] = '*';
			fill(r,c-1,m - r + 3);
			return;
		}
		if(m < r)
		{
			for(int i = r - m; i< r; i++) field[i][c-1] = '*';
			return;
		}
		for(int i = 0; i< r; i++) field[i][c-1] = '*';
		fill(r,c-1,m - r);
		return;
	}
	if(r - m == 1)
	{
		for(int i = 2; i< r; i++) field[i][c-1] = '*';
		fill(r,c-1,m - r + 2);
		return;
	}
	else if (r > m)
	{
		for(int i = r - m; i< r; i++) field[i][c-1] = '*';
		return;
	}
	for(int i = 0; i< r; i++) field[i][c-1] = '*';
	fill(r,c-1,m - r);
	return;
}

int main()
{
	int T;
	bool ans;

	scanf("%d",&T);
	for (int Case = 1; Case <= T; Case++)
	{
		ans = true;
		scanf("%d %d %d",&R, &C, &M);
		for(int x=0;x<50;x++)
		{
			for(int y=0; y<50;y++)
			{
				field[y][x] = 0;
			}
		}
		for(int x=0;x<C;x++)
		{
			for(int y=0; y<R;y++)
			{
				if(M == 0) field[y][x] = '.';
				else field[y][x] = 'x';
			}
		}
		fill(R,C,M);
		left = R*C - M -1;

		if(field[0][0] == '*') ans = false;
		else field[0][0] = 'c';

		if(M > 0 && ans) ans = foo(0,0);

		printf("Case #%d:\n",Case);
		if(ans)
		{
			for(int y=0; y<R;y++)
			{
				for(int x=0;x<C;x++)
				{
					printf("%c",field[y][x]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Impossible\n");
		}
	}


	return 0;
}