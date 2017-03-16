#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, ans, sum;
char ch;

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d%c", &n, &ch);
		int ans = 0;
		scanf("%c", &ch);
		sum = ch - '0';
		for (int i = 1; i <= n; ++i)
		{
			if (ans < i - sum)
				ans = i - sum;
			scanf("%c", &ch);
			sum += ch - '0';
		}
		printf("%d\n", ans);
	}
	return 0;
}