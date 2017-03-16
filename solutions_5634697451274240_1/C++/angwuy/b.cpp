#include <cstdio>
#include <cstring>

const int MAXN = 10000;

int n;
int len;
char s[MAXN];

void solve()
{
	scanf("%s\n",s);
	len = strlen(s);
	int ans = 0;
	if (s[len - 1] == '-') ++ans;
	for (int i = 1; i < len; ++i)
		if (s[i] != s[i - 1]) ++ans;
	printf("%d\n", ans);
}

int main()
{
	freopen("b.in", "r", stdin);
	int nn;
	scanf("%d\n", &nn);
	for (int ii = 1; ii <= nn; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}