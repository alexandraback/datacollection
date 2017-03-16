#include <stdio.h>
#include <string.h>

FILE * in = fopen("in.txt", "r");
FILE * out = fopen("out.txt", "w");

int n, len;
int data[1005];

void p(int z)
{
	int i, j;
	int max = -1;

	int ans;
	int real = 0x7fffffff;

	fscanf(in, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &data[i]);

		if (max < data[i])
		{
			max = data[i];
		}
	}

	for (i = 1; i <= max; i++)
	{
		ans = i;

		for (j = 0; j < n; j++)
		{
			ans += (data[j] - 1) / i;
		}

		if (real > ans)
		{
			real = ans;
		}
	}

	fprintf(out, "Case #%d: %d\n", z, real);
}

int main()
{
	int i, t;
	fscanf(in, "%d", &t);
	for (i = 0; i < t; i++)
		p(i+1);
}