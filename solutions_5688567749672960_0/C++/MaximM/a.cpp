#include <cstdio>

const int M = 1000100, OO = 1e9;

int a[M], q[2][M], qs[2];
int i, k, x, y;
int te;

int rev(int n)
{
	int m = 0;
	while (n > 0)
	{
		m = m * 10 + (n % 10);
		n /= 10;
	}
	return m;
}

void add(int n)
{
	if (n < M && a[n] > k)
	{
		a[n] = k;
		q[y][qs[y]++] = n;
	}
}

int main()
{
	for (i = 0; i < M; i++)
		a[i] = OO;
	a[1] = 1;

	q[0][0] = 1;
	qs[0] = 1;
	y = 1;
	k = 1;
	while (qs[x] > 0)
	{
		++k;
		qs[y] = 0;
		for (i = 0; i < qs[x]; i++)
		{
			int num1 = q[x][i] + 1;
			int num2 = rev(q[x][i]);
			add(num1);
			add(num2);
		}
		x ^= 1, y ^= 1;
	}

	scanf("%d", &te);
	for (int tn = 1; tn <= te; tn++)
	{
		int x;
		scanf("%d", &x);
		printf("Case #%d: %d\n", tn, a[x]);
	}

	return 0;
}