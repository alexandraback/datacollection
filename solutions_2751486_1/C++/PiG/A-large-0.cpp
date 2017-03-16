#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long LL;

int N;
char str[1001000];

bool vowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	int kase = 0;
	while ((++kase) <= T)
	{
		scanf("%s%d", str, &N);
		LL tot = 0;
		LL i;
		LL sl = strlen(str);
		LL a, b, tmp;
		a = b = 0;
		bool flag = false;
		tmp = 0;
		for (i = 0; i < sl; ++i)
		{
			if (!vowel(str[i]))
				tmp++;
			else
				tmp = 0;
			if (tmp >= N)
				a = i + 2 - N;
			tot += a;
		}
		printf("Case #%d: %lld\n", kase, tot);
	}
	
	return 0;
}

