/*Dijkstra*/

#include<stdio.h>

char str[10005];
int product[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };

struct data
{
	int pos;
	int X;
};

int calc_prefix_product(int);
struct data check_prefix_product(int, int, struct data);
int multiply(int, int);

int main()
{
	int L, prefix_product, t, T, X;
	struct data current_data;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d %d", &L, &X);
		scanf("%s", str);
		prefix_product = calc_prefix_product(L);
		if ((prefix_product == 1) || ((prefix_product == -1) && (X % 2 == 0)))
			printf("Case #%d: NO\n", t);
		else if ((X == 1) && (prefix_product != -1))
			printf("Case #%d: NO\n", t);
		else if ((X > 1) && (prefix_product != -1) && ((X % 2 != 0) || (X % 4 == 0)))
			printf("Case #%d: NO\n", t);
		else
		{
			current_data.pos = 0;
			current_data.X = X;
			current_data = check_prefix_product(2, L, current_data);
			if (current_data.X <= 0)
				printf("Case #%d: NO\n", t);
			else
			{
				current_data = check_prefix_product(3, L, current_data);
				if (current_data.X <= 0)
					printf("Case #%d: NO\n", t);
				else
					printf("Case #%d: YES\n", t);
			}
		}
	}
	return 0;
}

int calc_prefix_product(int L)
{
	int i, prefix_product;
	prefix_product = 1;
	for (i = 0; i < L; i++)
		prefix_product = multiply(prefix_product, str[i] - 'i' + 2);
	return prefix_product;
}

struct data check_prefix_product(int val, int L, struct data current_data)
{
	int i, j, pos, prefix_product, X;
	struct data new_data;
	prefix_product = 1;
	pos = current_data.pos;
	X = current_data.X;
	for (i = 0; i < 4; i++)
	{
		for (j = pos; j < L; j++)
		{
			prefix_product = multiply(prefix_product, str[j] - 'i' + 2);
			if (prefix_product == val)
			{
				new_data.pos = (j == L - 1) ? 0 : j + 1;
				new_data.X = (j == L - 1) ? (X - 1) : X;
				return new_data;
			}
		}
		X--;
		pos = 0;
	}
	new_data.pos = -1;
	new_data.X = -1;
	return new_data;
}

int multiply(int a, int b)
{
	int sign;
	sign = (a * b > 0) ? 1 : -1;
	a = (a < 0) ? -a : a;
	b = (b < 0) ? -b : b;
	return sign * product[a][b];
}