#include <stdio.h>
#include <string.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int arr[21][21] = { NULL };
int t;
int r;
int c;
int w;
int result = 0;

void init()
{
	int i;
	int j;
	int cnt = 0;
	for (i = 2; i <= 20; i++)
	{
		cnt = i;
		for (j = i; j <= 20; j++)
		{
			if (j % i == 0)
			{
				arr[i][j] = cnt;
				cnt++;
			}
			else
			{
				arr[i][j] = cnt;
			}
		}
	}
}
int main(void)
{
	int i;
	int j;
	init();
	fscanf(in, "%d", &t);
	for (i = 1; i <= t; i++)
	{
		result = 0;
		fscanf(in, "%d %d %d", &r, &c, &w);
		if (r > 1)
		{
			result = result + (r - 1) * (c / w);
		}
		if (w == 1 || w == c)
		{
			result = result + c;
			fprintf(out, "Case #%d: %d\n", i, result);
		}
		else
		{
			result = result + arr[w][c];
			fprintf(out, "Case #%d: %d\n", i, result);
		}
	}
	return 0;
}


