#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n; cin >> n;
	long long m; cin >> m;

	vector<long long> w(n);
	vector<pair<int, int> > path;

	w[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (w[j] + w[i] <= m)
			{
				w[i] += w[j];
				path.push_back(make_pair(j, i));
			}
		}
	}

	if (w.back() == m)
	{
		cout << "POSSIBLE" << endl;
		vector<vector<int> > g(n, vector<int>(n));

		for (int i = 0; i < path.size(); ++i)
		{
			g[path[i].first][path[i].second] = 1;
		}

		for (int i = 0; i < g.size(); ++i)
		{
			for (int j = 0; j < g[i].size(); ++j)
				cout << g[i][j];
			cout << endl;
		}
	}
	else
	{
		cout << "IMPOSSIBLE" << endl;
	}


}

int main()
{
	//freopen("i:/input.txt", "rt", stdin);
	//freopen("i:/input.out", "wt", stdout);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}