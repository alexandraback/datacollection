#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cctype>
#include <queue>
#include <complex>
#include <functional>
#include <sstream>
#include <tuple>

using namespace std;

vector<int> t;
vector<vector<int>> a;

int dfs(int v, int p)
{
	int result = 0;
	for (auto u : a[v])
		if (u != p)
			result = max(result, dfs(u, p));
	return result + 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	int n;
    	cin >> n;
    	a.clear();
    	a.resize(n);
    	t.clear();
    	t.resize(n);
    	for (int i = 0; i < n; i++)
    	{
    		int d;
    		cin >> d;
    		t[i] = d - 1;
    		a[d - 1].push_back(i);
    	}
    	vector<pair<int, int> > ps;
    	for (int i = 0; i < n; i++)
    		for (int j = i + 1; j < n; j++)
    			if (t[i] == j && t[j] == i)
    				ps.push_back(make_pair(i, j));

    	int result = 0;
    	for (auto p : ps)
    		result += dfs(p.first, p.second) + dfs(p.second, p.first);

    	for (int i = 0; i < n; i++)
    	{
    		int cur = i;
    		int rep = -1;
    		for (int j = 1; j <= n; j++)
    		{
    			cur = t[cur];
    			if (cur == i)
    			{
    				rep = j;
    				break;
    			}
    		}
    		if (rep + 1)
    			result = max(result, rep);
    	}

    	cout << "Case #" << tc + 1 << ": " << result << endl;
    }
    return 0;
}