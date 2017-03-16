#include <stdio.h>

long long int l, x;
char str[11000];
int num[81000];

void pro(int a);

int cal(int a, int b)
{
	if (a < 0)
		return -cal(-a, b);
	if (b < 0)
		return -cal(a, -b);
	if (a == 1)
		return b;
	if (b == 1)
		return a;
	if (a == b)
		return -1;
	if (a < b)
		return -cal(b, a);
	if (a == 3 && b == 2)
		return -4;
	if (a == 4 && b == 2)
		return 3;
	if (a == 4 && b == 3)
		return -2;
}

FILE *input = fopen("c://input.txt", "r");
FILE *output = fopen("c://output.txt", "w");

int main()
{
	
	int t;
	fscanf (input, "%d", &t);
	for (int i = 0; i < t; i++)
		pro(i + 1);
	return 0;
}

void pro(int a)
{
	long long int first_i, last_k;
	fscanf (input, "%lld %lld", &l, &x);
	fscanf (input, "%s", str);
	fprintf (output, "Case #%d: ", a);
	num[0] = 1;
	for (long long int i = 0; i < l * 8; i++)
	{
		if (str[i % l] == 'i')
			num[i + 1] = cal(num[i], 2);
		else if (str[i % l] == 'j')
			num[i + 1] = cal(num[i], 3);
		else
			num[i + 1] = cal(num[i], 4);
	}
	if (num[l] == 1)
	{
		fprintf (output, "NO\n");
		return;
	}
	if (num[l] == -1 && x % 2 == 0)
	{
		fprintf (output, "NO\n");
		return;
	}
	if (num[l] != -1 && x % 4 != 2)
	{
		fprintf (output, "NO\n");
		return;
	}
	if (x <= 8)
	{
		first_i = l * x + 1;
		last_k = 0;
		for (long long int i = 1; i <= l * x; i++)
		{
			if (num[i] == 2)
			{
				first_i = i;
				break;
			}
		}
		for (long long int i = l * x; i >= 1; i--)
		{
			if (num[i] == 4)
			{
				last_k = i;
				break;
			}
		}
		if (first_i < last_k)
		{
			fprintf (output, "YES\n");
			return;
		}
		else
		{
			fprintf (output, "NO\n");
			return;
		}
	}
	else
	{
		first_i = l * 8 + 1;
		last_k = 0;
		for (long long int i = 1; i <= l * 8; i++)
		{
			if (num[i] == 2)
			{
				first_i = i;
				break;
			}
		}
		for (long long int i = l * 8; i >= 1; i--)
		{
			if (num[i] == 4)
			{
				last_k = i;
				break;
			}
		}
		if (first_i < last_k)
		{
			fprintf (output, "YES\n");
			return;
		}
		else
		{
			fprintf (output, "NO\n");
			return;
		}
	}
}