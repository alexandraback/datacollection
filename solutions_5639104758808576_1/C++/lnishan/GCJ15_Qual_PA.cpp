#include <cstdio>

using namespace std;

const int N = 1005;

char s[N];

int main()
{
	int i, t, smax, stand, ans;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++)
	{
		stand = ans = 0;
		scanf("%d %s", &smax, s);
		for (i = 0; i <= smax; i++)
			if (stand >= i)
				stand += s[i] - '0';
			else
			{
				ans += i - stand;
				stand = i + s[i] - '0';
			}
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}
