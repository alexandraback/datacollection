#include <cstdio>
#include <cstring>

char s[102];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%s", s);
		int n = strlen(s);
		s[n] = '+';
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += s[i] != s[i + 1];
		printf("Case #%d: %d\n", kase, cnt);
	}
	return 0;
}
