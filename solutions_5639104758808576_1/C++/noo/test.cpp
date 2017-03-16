#include <stdio.h>

int n;
char shy[1100];
int sum[1100];

void in();
int pro();

FILE *input = fopen("c:\\input.txt", "r");
FILE *output = fopen("c:\\output.txt", "w");

int main()
{	
	int n;
	fscanf (input, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		in();
		fprintf (output, "Case #%d: %d\n", i + 1, pro());
	}
	return 0;
}

void in()
{
	fscanf (input, "%d %s", &n, shy);
}

int pro()
{
	for (int i = 0; i <= n; i++)
		sum[i] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + shy[i - 1] - '0';
	int max = 0;
	for (int i = 0; i <= n; i++)
		max = max < (i - sum[i]) ? i - sum[i] : max;
	return max;
}
