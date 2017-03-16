#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n;
char s[1010];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d %s", &n, s);
		int m = strlen(s);
		int ans = 0;
		int sum = s[0] - '0';
		for (int i = 1; i < m; i++)
		{
			if (sum < i)
			{
				ans += i - sum;
				sum += i - sum;
			}
			sum += s[i] - '0';
		}
		printf("Case #%d: %d\n", q + 1, ans);
	}
	return 0;
}