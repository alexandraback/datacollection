#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <set>
using namespace std;

#pragma comment(linker, "/STACK:36777216")

#define INF 0x7fffffff
#define EPS 1e-8

typedef long long LL;

int n, ans;
string str[105];
bool d[10];

void dfs(int k, string s)
{
	int i;
	if (k == n)
	{
		int f[26] = {0};
		f[s[0] - 'a']++;
		for (i = 1; i < s.size(); ++i)
		{
			if(s[i] != s[i - 1])
			{
				f[s[i] - 'a']++;
			}
		}
		for (i = 0; i < 26; ++i)
		{
			if (f[i] > 1)
			{
				break;
			}
		}
		if (i == 26)
		{
			ans++;
		}
	}
	for (i = 0; i < n; ++i)
	{
		if (d[i])
		{
			continue;
		}
		d[i] = true;
		dfs(k + 1, s + str[i]);
		d[i] = false;
	}
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cs;
	scanf("%d", &T);
	for (cs = 1; cs <= T; ++cs)
	{
		int i, j, k;
		char s[105][105];
		int f[26] = {0}, g[26] = {0};
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
			int len = strlen(s[i]);
			str[i] = s[i][0];
			for (j = 1; j < len; ++j)
			{
				if (s[i][j] != s[i][j - 1])
				{
					str[i] += s[i][j];
				}
			}
			for (j = 1; j < str[i].size() - 1; ++j)
			{
				f[str[i][j] - 'a']++;
			}
			g[str[i][0] - 'a'] = 1;
			g[str[i][str[i].size() - 1] - 'a'] = 1;
		}
		ans = 0;
		for (i = 0; i < 26; ++i)
		{
			if (f[i] > 1 || f[i] == 1 && g[i] == 1)
			{
				ans = -1;
			}
		}
		for (i = 0; i < n; ++i)
		{
			if (str[i].size() > 1 && str[i][0] == str[i][str[i].size() - 1])
			{
				ans = -1;
			}
			if (str[i].size() > 1)
			{
				str[i] = str[i][0];
				str[i] += s[i][strlen(s[i]) - 1];
			}
		}
		printf("Case #%d: ", cs);
		if (ans == -1)
		{
			printf("0\n");
			continue;
		}
		memset(d, false, sizeof(d));
		dfs(0, "");
		printf("%d\n", ans);
	}
}