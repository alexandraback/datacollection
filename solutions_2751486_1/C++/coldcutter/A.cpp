#include <cstdio>
#include <cstring>

const int maxn = 1000005;

int a[maxn], test, n;
char s[maxn];

bool isvowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%s %d", s + 1, &n);
		int len = strlen(s + 1);
		int m = 0;
		for (int i = 1; i <= len;)
		{
			int j = i;
			while (j <= len && !isvowel(s[j]))
				++j;
			if (j - i >= n)
				a[++m] = i;
			i = j;
		}
		long long ans = 0;
		if (m != 0)
		{
			for (int i = 1, j = 1; i <= len; ++i)
			{
				while (j <= m && a[j] < i)
					++j;
				if (j > m)
					break;
				ans += len - (a[j] + n - 2);
			}
		}
		printf("Case #%d: %I64d\n", kase, ans);
	}
	
	return 0;
}
