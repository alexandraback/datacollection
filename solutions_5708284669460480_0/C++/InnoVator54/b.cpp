#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MAXN 110
int dp[MAXN];
char keyboard[MAXN];
string tar;
int tot = 0;
int res = 0;
int k, l, s;
int maxx;

void dfs(int pos, string cur)
{
	if(pos >= s)
	{
		int tmp = 0;
		for (int i = 0; i < cur.size() - tar.size() + 1; ++i)
		{
			if(cur.substr(i, tar.size()) == tar)
				tmp++;
		}
		maxx = max(tmp, maxx);
		tot++;
		res += tmp;
		return;
	}
	for (int i = 0; i < k; ++i)
	{
		dfs(pos + 1, cur + keyboard[i]);
	}
}

int main()
{
	int T;
	int ca = 0;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		tot = 0;
		maxx = 0;
		res = 0;
		scanf("%d%d%d", &k, &l, &s);
		scanf("%s", keyboard);
		cin>>tar;
		dfs(0, "");
		printf("Case #%d: %lf\n", ++ca, maxx - res * 1.0 / tot);
	}
	return 0;
}