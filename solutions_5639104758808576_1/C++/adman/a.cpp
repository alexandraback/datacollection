#include <stdio.h>
#include <string.h>

FILE * in = fopen("in.txt", "r");
FILE * out = fopen("out.txt", "w");

int n, len;
char data[1005];

void p(int z)
{
	int i;

	fscanf(in, "%d", &n);
	fscanf(in, " %s", data);

	int len = strlen(data);

	int sum = 0;
	int ans = 0;

	sum = data[0] - '0';
	data[0] = 0;

	for (i = 1; i < len; i++)
	{
		if (sum < i && data[i] != '0')
		{
			ans += i - sum;
			sum += i - sum;
		}
		sum += data[i] - '0';
		data[i] = 0;
	}
	fprintf(out, "Case #%d: %d\n", z, ans);
}

int main()
{
	int i, t;
	fscanf(in, "%d", &t);
	for (i = 0; i < t; i++)
		p(i+1);
}