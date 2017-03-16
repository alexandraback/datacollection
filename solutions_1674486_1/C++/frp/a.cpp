#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > g;
vector<vector<int> > gt;
vector<bool> used;
bool dfs(int v)
{
	used[v] = true;
	for(int i = 0; i < gt[v].size(); i++)
	{
		int t = gt[v][i];
		if(!used[t])
		{
			if(dfs(t))
				return true;
		}
		else
			return true;
	}
	return false;
}
void test(int num)
{
	int n;
	cin >> n;
	g.assign(n, vector<int>());
	gt.assign(n, vector<int>());
	used.assign(n, false);
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			int v;
			cin >> v;
			v--;
			g[i].push_back(v);
			gt[v].push_back(i);
		}
	}
	bool diamond = false;
	for(int i = 0; i < n; i++)
	{
		if(g[i].size() == 0)
		{
			used.assign(n, false);
			if(dfs(i))
			{
				diamond = true;
				break;
			}
		}
	}
	cout << "Case #" << num << ": " << (diamond ? "Yes" : "No") << "\n";
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}
