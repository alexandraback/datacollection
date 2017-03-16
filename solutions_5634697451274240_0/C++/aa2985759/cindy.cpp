
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;

char s[1024];
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		scanf("%s", s);
		int ans = 0;
		for (int i = 1; s[i]; i++)
		{
			if (s[i] != s[i - 1])
				ans++;
		}
		if ((ans & 1) != (s[0] == '-'))
			ans++;
		printf("Case #%d: %d\n", ii, ans);
	}
}

