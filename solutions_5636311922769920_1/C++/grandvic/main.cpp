#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <deque>
#include <iterator>
#include <string>
#include <limits>
#include <sstream>
 
using namespace std;

long long code(const vector<int>& g, int k)
{
	long long answer = g[0];
	for (int i = 1; i < g.size(); ++i)
		answer = answer * k + g[i];
	return answer + 1;
}

void solve()
{
	int k, c, s; cin >> k >> c >> s;
	if (k == s)
	{
		for (int i = 1; i <= k; ++i)
			cout << i << " ";
		cout << endl;
	}
	else
	{
		vector<vector<int> > g;
		for (int i = 0; i < k; ++i)
		{
			if (i % c == 0)
			{
				g.push_back(vector<int>());
			}
			g.back().push_back(i);
		}
		while (g.back().size() < c)
		{
			g.back().push_back(0);
		}
		vector<long long> answer;
		for (int i = 0; i < g.size(); ++i)
		{
			answer.push_back(code(g[i], k));
		}
		if (answer.size() > s)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			for (int i = 0; i < answer.size(); ++i)
				cout << answer[i] << " ";
			cout << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}
