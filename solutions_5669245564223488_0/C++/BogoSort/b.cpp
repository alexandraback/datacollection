#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
int n;
char st[110][110];
int next[110];
bool vis[110];
bool f[110];

int position(int k, char ch)
{
	int l = strlen(st[k]);
	int ocr = -1, now = -1;
	for (int i = 0; i < l; ++i)
	{
		if (st[k][i] == ch)
		{
			if (ocr == -1)
			{
				ocr = now = i;
			} else
			{
				if (i != now + 1)
				{
					return -1;
				}
				++now;
			}
		}
	}
	int x = 0;
	if (ocr == 0) x |= 1;
	if (now == l - 1) x |= 2;
	if (ocr > 0 && now < l - 1) x = 4;
	return x;
}

void work()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", st[i]);
		next[i] = -1;
	}
	memset(f, 0, sizeof(f));
	long long ans = 1;
	for (int i = 'a'; i <= 'z'; ++i)
	{
		int begin = -1, end = -1, nowh = -1, nowt = -1, s = 0;
		bool danger = false;
		for (int j = 0; j < n; ++j)
		{
			int kind = position(j, i);
			if (kind == 0) continue;
			if (kind > 0 && danger)
			{
				printf("0\n");
				return;
			}
			if (kind == -1)
			{
				printf("0\n");
				return;
			}
			if (kind == 1)
			{
				if (end > -1)
				{
					printf("0\n");
					return;
				}
				end = j;
			} else
			if (kind == 2)
			{
				if (begin > -1)
				{
					printf("0\n");
					return;
				}
				begin = j;
			} else
			if (kind == 3)
			{
				if (nowh == -1)
				{
					nowh = nowt = j;
				} else
				{
					next[nowt] = j;
					nowt = j;
					f[j] = true;
				}
				++s;
			} else
			{
				if (begin != -1 || end != -1 || nowh != -1)
				{
					printf("0\n");
					return;
				}
				danger = true;
			}
		}
		if (nowh > -1)
		{
			if (begin > -1)
			{
				next[begin] = nowh;
				f[nowh] = true;
			}
			if (end > -1)
			{
				next[nowt] = end;
				f[end] = true;
			}
		}
		if (nowh == -1 && begin != -1 && end != -1)
		{
			next[begin] = end;
			f[end] = true;
		}
		if (s > 0)
		{
			for (int k = 2; k <= s; ++k)
				ans = (ans * (long long)k) % MOD;
		}
	}
	
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i)
		if (!f[i])
		{
			vis[i] = true;
			int v = i;
			while (next[v] != -1)
			{
				v = next[v];
				if (vis[v])
				{
					printf("0\n");
					return;
				}
				vis[v] = true;
			}			
		}
	for (int i = 0; i < n; ++i)
		if (!vis[i])
		{
			printf("0\n");
			return;
		}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (next[i] == -1) ++cnt;
	for (int i = 2; i <= cnt; ++i)
	{
		ans = (ans * (long long)i) % MOD;
	}
	cout << ans << endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
