#include <bits/stdc++.h>
using namespace std;
int t, cnt = 0, r;
char s[105] = {'\0'};
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%s", s);
		printf("Case #%d: ", tt);
		r = strlen(s);
		while (r && s[r - 1] == '+') r--;
		if (r == 0) puts("0");
		else
		{
			cnt = 0;
			while (r)
			{
				if (s[r - 1] != s[r]) cnt++;
				r--;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}