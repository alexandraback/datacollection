#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

char s[1010];
char ans[1010];

int cmp(int len)
{
	for (int i = 0; i < len; i++)
	{
		if (ans[i] != ans[i + 1])
			return (ans[i] - ans[i + 1]);
	}
	return 0;
}

void solve()
{
	int n = strlen(s + 1);
	memset(ans, 0, 1010);
	for (int i = 1; i <= n; i++)
	{
		ans[0] = s[i];
		ans[i] = s[i];
		int c = cmp(i);
		if (c > 0)
		{
			for (int j = i; j > 0; j--)
			{
				ans[j] = ans[j - 1];
			}
		}
	}
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		scanf("%s", s + 1);
		solve();
		printf("Case #%d: %s\n", test, ans + 1);
	}
	return 0;
}