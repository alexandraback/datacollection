#include <cstdio>
#include <cstring>
const int maxt = 100, maxs = 100;
int t, len, ans;
char s[maxs + 5];
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		scanf("%s", s);
		len = strlen(s);
		s[len] = '+';
		ans = 0;
		for(int i = 0; i < len; ++i)
			ans += s[i] != s[i + 1];
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
