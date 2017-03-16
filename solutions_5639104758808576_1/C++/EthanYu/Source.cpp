#include <stdio.h>
#include<stdlib.h>
int main()
{
	int N;
	scanf_s("%d", &N);
	FILE *fp;
	fopen_s(&fp,"out.out", "wt+");
	for (int Case = 1; Case <= N;Case++)
	{
		int max;
		char s[1002];
		int sd[1002];
		int res = 0;
		scanf_s("%d ", &max);
		gets_s(s);
		sd[0] = s[0] - '0';
		for (int i = 1; i <= max; i++)
		{
			sd[i] = s[i] - '0';
			if (sd[i - 1] < i)
			{
				res += i - sd[i - 1];
				sd[i] += i;
			}
			else
				sd[i] += sd[i - 1];

		}
		fprintf(fp,"Case #%d: %d\n", Case, res);
		printf( "Case #%d: %d\n", Case, res);
	}
	fclose(fp);
	N = getchar();
}