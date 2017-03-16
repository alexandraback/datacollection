#include <bits/stdc++.h>
using namespace std;
int t, k, c, s;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d: ", tt);
		for (int i = 1; i <= s; i++) printf("%d ", i);
		puts("");
	}
	return 0;
}