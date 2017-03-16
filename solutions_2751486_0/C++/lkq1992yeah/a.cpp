#include <stdio.h>
#include <string.h>
#define MAX(a,b)    ((a) > (b) ? (a) : (b))

char str[2000000];
int n;

bool Need_Count(char c)
{
	if (c != 'a' && c != 'e' && c != 'i'
		&& c != 'o' && c != 'u')
		return true;
	return false;
}

int main()
{
	int i, j, k, l, consec;
	int cnt, ret;
	int cas, t;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		ret = 0;
		scanf("%s%d", str, &n);
		int l = strlen(str);
		for (i = 0; i < l; i++)
			for (j = i + n - 1; j < l; j++)
			{
				consec = cnt = 0;
				for (k = i; k <= j; k++)
				{
					if (Need_Count(str[k]))
						cnt++;
					else
						cnt = 0;
					consec = MAX(cnt, consec);
				}
				if (consec >= n)
				{
					//printf("%d %d\n", i, j);
					ret++;
				}
			}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}
