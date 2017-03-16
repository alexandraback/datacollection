#include <stdio.h>
#include <string.h>

FILE *out = fopen("output.txt", "w");

int arr[21][21] = { NULL };
int t;
int r;
int c;
int w;

void input();
void process();

int main(void)
{
	input();
	return 0;
}

void input()
{
	int i;
	int j;
	process();
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d %d %d", &r, &c, &w);
		if (w == 1 || w == c)
			fprintf(out, "Case #%d: %d\n", i, c);
		else
			fprintf(out, "Case #%d: %d\n", i, arr[w][c]);
	}
}

void process()
{
	int i;
	int j;
	int count = 0;
	for (i = 2; i <= 10; i++)
	{
		count = i;
		for (j = i; j <= 10; j++)
		{
			if (j % i == 0)
			{
				arr[i][j] = count;
				count++;
			}
			else
			{
				arr[i][j] = count;
			}
		}
	}
}