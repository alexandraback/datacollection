#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int a[1010], length[1010], fa[1010], tot[1010];
int ans;
bool used[1010], love[1010], first[1010];

void Dfs(int start, int cur, int len)
{
	if (len && start == cur)
	{
		if (len >= ans) ans = len;
		return;
	}
	if (used[cur]) return;
	used[cur] = true;
	Dfs(start, a[cur], len + 1);
}

void Dfs2(int cur)
{
	if (used[cur])
	{
		if (!length[cur])
		{
			length[cur] = -999999999;
			fa[cur] = 0;
		}
		return;
	}
	used[cur] = true;
	if (love[cur])
	{
		used[a[cur]] = true;
		length[cur] = length[a[cur]] = 2;
		fa[cur] = cur;
		fa[a[cur]] = a[cur];
		return;
	}
	Dfs2(a[cur]);
	length[cur] = 1 + length[a[cur]];
	fa[cur] = fa[a[cur]];
}

void Work()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int ret = 1;

	memset(used, false, sizeof(used));
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (!used[i])
		{
			Dfs(i, i, 0);
		}
	if (ans >= ret) ret = ans;
	//cout << "ans = " << ans << endl;
	memset(love, false, sizeof(love));
	for (int i = 1; i <= n; i++)
	{
		if (a[a[i]] == i)
		{
			love[i] = true;
			love[a[i]] = true;
		}
	}
	memset(first, true, sizeof(first));
	for (int i = 1; i <= n; i++)
	{
		first[a[i]] = false;
	}
	
	memset(used, false, sizeof(used));
	memset(fa, 0, sizeof(fa));
	memset(length, 0, sizeof(length));
	for (int i = 1; i <= n; i++)
		if (!used[i])
		{
			Dfs2(i);
		}

	memset(tot, 0, sizeof(tot));
	for (int i = 1; i <= n; i++)
		if (first[i] && length[i] > 0 && fa[i])
		{
			tot[fa[i]] = max(tot[fa[i]], length[i]);	
		}
	int add = 0;
	for (int i = 1; i <= n; i++)
	{
		add += tot[i];
		if (love[i] && tot[i] != 0 && tot[a[i]] != 0 && i < a[i]) add -= 2;
		if (tot[i] != 0)
		{
			//cout << "tot[" << i << "] = " << tot[i] << endl;
		}
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		//cout << "len[" << i << "] = " << length[i] << endl;
		//cout << "first[" << i << "] = " << first[i] << endl;
		//cout << "fa[" << i << "] = " << fa[i] << endl;
	}
	//cout << "add = " << add << endl;
	if (add >= ret) ret = add;
	cout << ret << endl;
}

int main()
{
	freopen("123.in", "r", stdin);
	freopen("123.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "Case #" << i << ": ";
		Work();
	}

	return 0;
}