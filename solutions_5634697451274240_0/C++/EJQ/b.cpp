#include <cstdio>
#include <cstring>
using namespace std;
char s[120];
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%s", s);
		int l = strlen(s);
		int ans = 0;
		s[l] = '+';
		for (int j = 0; j <= l; j++)
		{
			if (j && s[j] == '+' && s[j - 1] == '-')
				ans++;
			if (j < l && s[j] == '+' && s[j + 1] == '-')
				ans++;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
