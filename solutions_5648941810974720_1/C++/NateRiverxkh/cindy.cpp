#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
char s[20100];
int cnt[2010];
int ans[2010];
int main()
{
	int ncase, i, j, tt = 0, len;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", s);
		len = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));

		for (i = 0; i<len; i++)
		{
			cnt[s[i] - 'A']++;
		}

		ans[6] = cnt['X' - 'A'];
		ans[7] = cnt['S' - 'A'] - ans[6];
		ans[5] = cnt['V' - 'A'] - ans[7];
		ans[4] = cnt['F' - 'A'] - ans[5];
		ans[2] = cnt['W' - 'A'];
		ans[0] = cnt['Z' - 'A'];
		ans[1] = cnt['O' - 'A'] - ans[2] - ans[4] - ans[0];
		ans[3] = cnt['R' - 'A'] - ans[0] - ans[4];
		ans[8] = cnt['G' - 'A'];
		ans[9] = cnt['I' - 'A'] - ans[5] - ans[6] - ans[8];

		printf("Case #%d: ", ++tt);
		for (int i = 0; i<10; i++)
		{
			for (int j = 0; j<ans[i]; j++)
				printf("%d", i);
		}
		puts("");
	}


}
