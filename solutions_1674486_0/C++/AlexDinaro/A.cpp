#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mp make_pair
#define pb push_back

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

vector<vector<int>> g; 
vector<bool> used;

bool dfs (int v)
{
	used[v]=1;
	bool ans=false;
	for (int i=0; i<g[v].size() && !ans; ++i)
	{
		if (used[g[v][i]])
			return true;
		else
			ans = dfs(g[v][i]);
	}
	return ans;
}


void solve()
{
	int tests;
	cin>>tests;
	for (int test=1; test<=tests; ++test)
	{
		int ans=0;
		int n;
		cin>>n;
		g.clear();
		g.resize(n);
		for (int i=0;i<n;++i)
		{
			int m;
			cin>>m;
			g[i].resize(m);
			for (int j=0;j<m;++j)
			{
				cin>>g[i][j];
				--g[i][j];
			}
		}
		for (int i=0; i<n && !ans; ++i)
		{
			used.assign(n,0);
			if (dfs(i))
				ans=1;
		}
		cout<<"Case #"<<test<<": "<<(ans?"Yes":"No")<<endl;
	}
}

int main()
{
	prepare();
	solve();
	return 0;
}