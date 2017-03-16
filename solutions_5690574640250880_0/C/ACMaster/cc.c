#include <stdio.h>
#include <string.h>

char ch[55][55];

void Init1(int r, int c)
{
	int i, j;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			ch[i][j] = '*';
}
void Init2(int r, int c)
{
	int i, j;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			ch[i][j] = '.';
}
void Init3()
{
	ch[1][1] = ch[1][2] = ch[2][1] = ch[2][2] = '.';
}
void Init4()
{
	ch[1][3] = ch[2][3] = ch[3][3] = ch[3][2] = ch[3][1] = '.';
}
void work(int a, int c, int m, int b, int r)
{
	int i, j;
	for (j = a; j <= c && m > 0; j++)
	{
		ch[1][j] = ch[2][j] = '.';
		m -= 2;
	}
	for (i = b; i <= r && m > 0; i++)
	{
		ch[i][1] = ch[i][2] = '.';
		m -= 2;
	}
}
void work1(int m)
{
	int i;
	for (i = 1; i <= m; i++) ch[1][i] = ch[i][1] = '.';
}
void work2(int m)
{
	int j;
	for (j = 1; j <= m/2; j++) ch[1][j] = ch[2][j] = ch[j][1] = ch[j][2] = '.';
}
int judge(int m)
{
	if (m == 2 || m == 3 || m == 5 || m == 7) return 1;
	return 0;
}
void solve(int r, int c, int m)
{
	int i, j, mm, a, b;
	memset(ch, 0, sizeof(ch));
	Init1(r, c);
	if (m == 1 ) {ch[1][1] = 'c'; goto output;}
	if (r == 1 || c == 1)
	{
		work1(m);
		ch[1][1] = 'c';
		goto output;
	}
	if (c == 2 || r == 2)
	{
		work2(m);
		ch[1][1] = 'c';
		if (m%2 != 0 || m < 4)
		{
			printf("Impossible\n"); return ;
		}
		else goto output;
	}
	mm = r*c-m;
	if (mm <= (r-2)*(c-2))
	{
		Init2(r, c);
		for (i = r; i >= 3 && mm; i--)
			for (j = c; j >= 3 && mm; j--)
			{
				ch[i][j] = '*';
				mm--;
			}
		ch[1][1] = 'c';
		goto output;
	}
	if (judge(m))
	{
		printf("Impossible\n");
		return ;
	}
	Init3();
	m -= 4, a = 3, b = 3;
	if (m % 2)
	{
		Init4();
		m-=5, a = 4, b = 4;
	}
	work(a, c, m, b, r);
	ch[1][1] = 'c';
output:
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++) printf("%c", ch[i][j]);
		printf("\n");
	}
	return ;
}

int main()
{
	int T, ncas = 1, R, C, M;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &R, &C, &M);
		printf("Case #%d:\n", ncas++);
		solve(R, C, R*C-M);
	}

	return 0;
}