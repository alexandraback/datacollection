#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>
#include <ios>

using namespace std;

int main()
{
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ios_base::sync_with_stdio(0);
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int res;
		int n;
		ifs >> n;
		vector<vector<int> > v(n);
		vector<int> st(n);
		for (int i = 0; i < n; ++i)
		{
			int m;
			ifs >> m;
			for (int j = 0; j < m; ++j)
			{
				int k;
				ifs >> k;
				--k;
				st[k]++;
				v[i].push_back(k);
			}
		}

		bool ok = true;
		for (int i = 0; i < n; ++i)
		{
			if (st[i] == 0)
			{
				vector<int> was(n, 0);
				queue<int> q;
				q.push(i);
				was[i] = 1;
				while (!q.empty())
				{
					int z = q.front();
					q.pop();
					for (int j = 0; j < v[z].size(); ++j)
					{
						int x = v[z][j];
						if (was[x] == 0)
						{
							was[x] = 1;
							q.push(x);
						}
						else 
						{
							ok = false;
							break;
						}
					}
					if (!ok) break;
				}
			}
			if (!ok) break;
		}

		ofs << "Case #" << test+1 << ": " << (ok ? "No" : "Yes") << endl;
	}
	return 0;
}
