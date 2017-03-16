#include <stdio.h>
#include <string.h>
#define LL long long
#define MaxN 1000010

bool con(char c)
{
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

char s[MaxN];
int left[MaxN], right[MaxN];

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, n;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		scanf("%s%d", s, &n);
		int len = strlen(s);
		LL ans = len * (len + 1) / 2;
		int cnt = 0;
		for (int i = 0; i < len; ++i)
		{
			if (!con(s[i])) continue;
			int pre = i;
			while (s[i] && con(s[i])) ++i;
			if (i - pre >= n)
			{
				left[cnt] = pre;
				right[cnt++] = i - 1;
			}
			--i;
		}

		left[cnt] = len, right[cnt++] = len;

		//for (int i = 0; i < cnt; ++i) printf("%d %d\n", left[i], right[i]);

		int j = 0;
		for (int i = 0; i < len; ++i)
		{
			while (i > right[j]) ++j;

			if (i < left[j])
			{
				int end = left[j] + n - 2;
				if (j == cnt - 1) end = len - 1;
				//printf("%d\n", end - i + 1);
				ans -= end - i + 1;
			}
			else if (right[j] - i + 1 < n)
			{
				int end = left[j+1] + n - 2;
				if (j+1 == cnt - 1) end = len - 1;
				//printf("%d\n", end - i + 1);
				ans -= end - i + 1;
			}
			else
			{
				//printf("%d\n", n - 1);
				ans -= n - 1;
			}
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}