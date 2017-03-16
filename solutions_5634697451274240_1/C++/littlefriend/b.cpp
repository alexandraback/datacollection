#include <cstdio>
#include <cstring>
int main(int argc, char** argv)
{
	int n;
	char s[150];
	if (argc > 1)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		int len = strlen(s);
		s[len] = '+';
		int cnt = 0;
		for (int j = 1; j <= len; ++j)
			if (s[j] != s[j-1])
				cnt++;
		printf("Case #%d: %d\n", i+1, cnt);
	}
	return 0;
}