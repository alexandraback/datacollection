#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int test, n, i, tt, ans, Hash[105], exist[1005];
string s[105], now;
vector <int> v[1005];

void dfs(int i, string now);
int ok(string now);

int main()
{
	freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			cin >> now;
			s[i] = "";
			for (int j = 0; j < now.size(); j++)
				if (j == 0 || now[j] != now[j - 1])
					s[i] += now[j];
		}
		
		ans = 0;
		dfs(1, "");
		printf("Case #%d: %d\n", ++tt, ans);
	}
	
	return 0;
}

void dfs(int i, string now)
{
	if (i > n)
	{
		if (ok(now))
			ans++;
		return;
	}
	
	for (int x = 1; x <= n; x++)
		if (Hash[x] == 0)
		{
			Hash[x] = 1;
			dfs(i + 1, now + s[x]);
			Hash[x] = 0;
		}
}

int ok(string now)
{
	for (char c = 'a'; c <= 'z'; c++)
		exist[c] = 0;
	for (int i = 0; i < now.size(); i++)
		if (i == 0 || now[i] != now[i - 1])
		{
			if (exist[now[i]] == 1)
				return 0;
			exist[now[i]] = 1;
		}
	
	return 1;
}
