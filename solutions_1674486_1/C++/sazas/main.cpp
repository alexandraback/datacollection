#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FILE_NAME "A-large"

using namespace std;

vector< vector<int> > e;
vector<bool> used;

bool dfs(int v)
{
	if(used[v])
		return true;
	used[v] = true;
	for(int i = 0; i < e[v].size(); ++i)
	{
		if(dfs(e[v][i]))
			return true;
	}
	return false;
}

int main()
{
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
	
	int numTestCaces = 0;
	cin >> numTestCaces;
	for(int Case = 1; Case <= numTestCaces; ++Case)
	{
		int n;
		cin >> n;
		e.assign(n, vector<int>());
		for(int i = 0;i < n; ++i)
		{
			int m;
			cin >> m;
			e[i].resize(m);
			for(int j = 0; j < m; ++j)
			{
				cin >> e[i][j];
				--e[i][j];
			}
		}
		bool found = false;
		for(int i = 0; i < n; ++i)
		{
			used.assign(n, false);
			if(dfs(i))
			{
				found = true;
				break;
			}
		}

		cout << "Case #" << Case << ": ";
		if(found)
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}

	return 0;
}
