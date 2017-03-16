#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

vector<int> e[1005];
int bff[1005];
int l[1005];
int res = 0;

int dfs(int ind, int f)
{
	int res = 0;
	for (int i = 0; i < e[ind].size(); ++i)
		if (e[ind][i] != f)
			res = max(res, dfs(e[ind][i], ind));
	return res + 1;
}

void f(int ind, int num)
{
	if (l[ind] != -1)
	{
		res = max(res, num - l[ind]);
		return;
	}
	l[ind] = num;
	f(bff[ind], num+1);
	l[ind] = -1;
}

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int n;
		res = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			e[i].clear();
			l[i] = -1;
		}
		for (int i = 1; i <= n; ++i)
		{
			cin >> bff[i];
			e[bff[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++i)
			if (bff[bff[i]] == i)
				res += dfs(i, bff[i]) + dfs(bff[i], i);
		res /= 2;
		for (int i = 1; i <= n; ++i)
			f(i, 0);
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
