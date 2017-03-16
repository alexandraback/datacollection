#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

char str1[30], str2[30];
vector<pair<string, string>> dat;

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\C-small-attempt0.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\C-small-attempt0.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s%s", str1, str2);
			dat.emplace_back(str1, str2);
		}
		int ans = 0;
		for (int i = 1; i < (1 << n); i++)
		{
			set<string> s1, s2;
			int j;
			int faked = 0;
			for (j = 0; j < n; j++)
			{
				if (i & (1 << j))
				{
					s1.insert(dat[j].first);
					s2.insert(dat[j].second);
				}
			}
			for (j = 0; j < n; j++)
			{
				if ((i & (1 << j)) == 0)
				{
					if (s1.count(dat[j].first) == 0 ||
						s2.count(dat[j].second) == 0) break;
					faked++;
				}
			}
			if (j == n) ans = max(ans, faked);
		}
		printf("%d\n", ans);

		dat.clear();
	}
}