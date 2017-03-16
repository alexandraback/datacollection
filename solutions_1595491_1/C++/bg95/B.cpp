#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std; 

int max3(int a)
{
	if (a % 3 == 0)
		return a / 3;
	return a / 3 + 1;
}
int max3surp(int a)
{
	if (!a)
		return 0;
	if (a % 3 == 0)
		return a / 3 + 1;
	if (a % 3 == 2)
		return a / 3 + 2;
	return a / 3 + 1;
}
int t;
int n, s, p;
int T, c;
int main(void)
{
	int i;
	int ans;
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		ans = 0;
		printf("Case #%d: ", c);
		scanf("%d%d%d", &n, &s, &p);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &t);
			if (max3(t) >= p)
				ans++;
			else if (max3surp(t) >= p && s)
			{
				s--;
				ans++;
			}
			//printf("%d %d %d\n", t, max3(t), max3surp(t));
		}
		printf("%d\n", ans);
	}
	return 0;
}
