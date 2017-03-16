#include <stdio.h>

int T, R, C, M, a[55];
char c[55][55];

void clear()
{
	int i, j;
	for(i=0; i<55; ++i)
	{
		a[i] = 0;
		for(j=0; j<55; ++j)
			c[i][j] = '*';
	}
	a[0] = 55;
}

bool rec(int ost, int k)
{
	int koef=1, s;
	bool rez;

	if(ost == 0)
		return true;
	if(ost < 0)
		return false;
	if(k > C)
		return false;
	if(k == 1)
		koef = 2;
	for(s=R; s>=2; --s)
	{
		/*if(s == R-1)
			continue;*/
		if(s > a[k-1])
			continue;
		a[k] = s;
		if(k==1)
			a[2] = a[1];
		rez = rec(ost-koef*s, k+koef);
		if(rez == true)
			return true;
	}
	return false;
}

void my_print()
{
	int i, j;

			for(i=1; i<=R; ++i)
			{
				for(j=1; j<=C; ++j)
					printf("%c", c[i][j]);
				printf("\n");
			}

}

void fill_1()
{
	int i;

	if(R == 1)
		for(i=1; i<=C-M; ++i)
			c[1][i] = '.';
	else if(C == 1)
		for(i=1; i<=R-M; ++i)
			c[i][1] = '.';
	c[1][1] = 'c';
}


int main()
{	int tt, i;
	bool rez;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(tt=1; tt<=T; ++tt)
	{
		scanf("%d %d %d", &R, &C, &M);
		clear();
		printf("Case #%d:\n", tt);
		if(R*C - M == 1)
		{
			c[1][1] = 'c';
			my_print();
			continue;
		}
		if(R==1 || C==1)
		{
			fill_1();
			my_print();
			continue;
		}
		rez = rec(R*C - M, 1);
		if(rez == false)
			printf("Impossible\n");
		else
		{
			int sum=0;
			int k=1;
			a[2] = a[1];
			while(sum < R*C-M)
			{
				sum += a[k];
				for(i=1; i<=a[k]; ++i)
					c[i][k] = '.';
				++k;
			}
			c[1][1] = 'c';
			my_print();
		}
	}

	return 0;
}