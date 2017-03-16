/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: b.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-05-11
*   last modified: 2014-05-11 17:52:18
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
#define X first
#define Y second
#define pb(x) push_back(x)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define foreach(it, s) for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++)

const int maxn = 100, maxm = 110;
int have[26];
int n;
char s[maxn][maxm];
bool ok[maxn];
int len[maxn];
int flag[maxn];
int ans;

bool judge(char *s)
{
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; s[i]; i++)
	{
		if (cnt[s[i]-'a'] && s[i-1]!=s[i])
			return 0;
		cnt[s[i]-'a']++;
	}
	return 1;
}
void dfs(int dep, int used, int state, char last)
{
	if (dep == n)
		ans++;
	FOR (i, n) if (ok[i] && !((1<<i)&used))
	{
		int it = state & flag[i];
		int cnt = 0;
		FOR (j, 26) if ((it>>j)&1) cnt++;
		if (cnt > 1) continue;
		if (cnt)
		{
			if (s[i][0] == last)
				dfs(dep+1, used|(1<<i), state|flag[i], s[i][len[i]-1]);
			continue;
		}
		dfs(dep+1, used|(1<<i), state|flag[i], s[i][len[i]-1]);
	}
}

int main()
{
	//freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	FOR (Case, T)
	{
		scanf("%d", &n);
		FOR (i, n)
		{
			scanf("%s", s[i]);
			ok[i] = judge(s[i]);
			flag[i] = 0;
			len[i] = strlen(s[i]);
			FOR (j, len[i])
				flag[i] |= (1<<int(s[i][j]-'a'));
		}
		ans = 0;
		dfs(0, 0, 0, 0);
		printf("Case #%d: %d\n", Case+1, ans);
	}
}
