#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

char s[105];	
int main()
{
	int test;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		scanf("%s\n", s);
		char last = '+';
		int ans = 0;
		for (int i = strlen(s) - 1; i >= 0; i--)
		{
			if (s[i] != last)
			{
				ans++;
				last = s[i];
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}