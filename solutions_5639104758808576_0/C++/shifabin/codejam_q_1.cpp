#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int ii, tt, i, tot, ans, t,n;
	char x;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("222.txt", "w", stdout);
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ii++)
	{
		scanf("%d", &n);
		scanf("%c", &x);
		tot = 0;
		ans = 0;
		for (int i = 0; i <= n; i++)
		{
			scanf("%c", &x);
			t = x - '0';
			if (i == 0)
			{
				tot += t;
				continue;
			}
			if (t != 0&&tot<i)
			{
				ans += i - tot;
				tot = i;
			}
			tot += t;
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}