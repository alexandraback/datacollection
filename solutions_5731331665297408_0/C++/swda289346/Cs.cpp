#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#define N 8
using namespace std;

int n, m;
int order[N], use[N];
int map[N][N];
vector<string> zip;
vector<string> ans;

bool available()
{
	stack<int> tmp;
	tmp.push(order[0]);
	for (int i=1;i<n;i++)
	{
		while (tmp.size() && !map[tmp.top()][order[i]])
			tmp.pop();
		if (!tmp.size())
			return false;
		tmp.push(order[i]);
	}
	return true;
}

void dfs(int now)
{
	if (now==n)
	{
		if (!available())
			return;
		string s;
		for (int i=0;i<n;i++)
			s += zip[order[i]];
		ans.push_back(s);
		return;
	}
	for (int i=0;i<n;i++)
		if (!use[i])
		{
			use[i] = 1;
			order[now] = i;
			dfs(now+1);
			use[i] = 0;
		}
	return;
}

int main()
{
	int t;
	int a, b;
	string s;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> m;
		zip.clear();
		ans.clear();
		for (int j=0;j<n;j++)
			use[j] = 0;
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				map[j][k] = 0;
		for (int j=0;j<n;j++)
		{
			cin >> s;
			zip.push_back(s);
		}
		for (int j=0;j<m;j++)
		{
			cin >> a >> b;
			map[a-1][b-1] = map[b-1][a-1] = 1;
		}
		dfs(0);
		sort(ans.begin(), ans.end(), less<string>());
		cout << "Case #" << i << ": " << ans[0] << endl;
	}
	return 0;
}
