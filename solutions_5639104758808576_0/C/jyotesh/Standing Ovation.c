/*Standing Ovation*/

#include<stdio.h>

char str[1024];

int main()
{
	int count, i, Smax, t, total, T;
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d %s", &Smax, str);
		for (i = 0; i <= Smax; i++)
			str[i] -= '0';
		total = str[0];
		count = 0;
		for (i = 1; i <= Smax; i++)
		{
			if (count <= i - total)
				count = i - total;
			total += str[i];
		}
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}