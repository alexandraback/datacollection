#include <bits/stdc++.h>

using namespace std;

char s[2010];
int cnt[300], res[11], test;

char a[11] = "ZXGWUFVORI";
int b[11] = {0,6,8,2,4,5,7,1,3,9};
char c[11][11] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
		"SIX", "SEVEN", "EIGHT", "NINE"};

int main()
{
	scanf("%d", &test);
	for (int tt = 1; tt <= test; ++tt)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(res, 0, sizeof(res));
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			++cnt[(int)s[i]];

		for (int i = 0; i < 10; ++i)
		{
			int tmp = cnt[a[i]];
			int len = strlen(c[b[i]]);
			for (int j = 0; j < len; ++j)
				cnt[c[b[i]][j]] -= tmp;
			res[b[i]] += tmp;
		}
		printf("Case #%d: ", tt);

		for (int i = 0; i < 10; ++i)
		for (int j = 0; j < res[i]; ++j)
			printf("%d", i);
		printf("\n");
	}
	return 0;
}