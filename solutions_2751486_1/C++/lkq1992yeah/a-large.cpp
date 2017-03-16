#include <stdio.h>
#include <string.h>
#define MAX(a,b)    ((a) > (b) ? (a) : (b))
#define MAXN 2000000
char str[MAXN];
int n, len;

bool Need_Count(char c)
{
	if (c != 'a' && c != 'e' && c != 'i'
		&& c != 'o' && c != 'u')
		return true;
	return false;
}

int next[MAXN];

void fill_blank()
{
	int i, j, cnt;
	int last = 0;
	int last_blank = 0;
	len = strlen(str);
	str[strlen(str)] = 'a';
	for (i = 0; i < len + 1; i++)
	{
		if (Need_Count(str[i]))
		{
			if (cnt == 0)
				last = i;
			cnt++;
		}
		else
		{
			if (cnt >= n)
			{
				for (j = last_blank; j < last; j++)
					next[j] = last;
				for (j = last; j + n - 1 < i; j++)
					next[j] = j;
				last_blank = j;
			}
			cnt = 0;
		}
	}
	for (j = last_blank; j < len; j++)
		next[j] = -1;
	str[strlen(str) - 1] = '\0';
	// for (i = 0; i < len; i++)
		// printf("%d\n", next[i]);
}

long long solve()
{
	int i;
	len = strlen(str);
	// printf("%s\n", str);
	// printf("len = %d, n = %d\n", len, n);
	long long ret = 0;
	int tmp = 0;
	for (i = 0; i < len; i++)
	{
		if (next[i] != -1)
		{
			tmp = len - next[i] - n + 1;
			ret += tmp;
		}
	}
	return ret;
}

int main()
{
	long long ret = 0;
	int cas, t;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		ret = 0;
		memset (str, 0, sizeof str);
		memset (next, -1, sizeof next);
		scanf("%s%d", str, &n);
		fill_blank();
		ret = solve();
		printf("Case #%d: %I64d\n", cas, ret);
	}
	return 0;
}
