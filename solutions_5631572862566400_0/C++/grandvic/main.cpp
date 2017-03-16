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
	vector<int> g(n);
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x; --x;
		g[i] = x;
	}

	int answer = 0;

	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		a[i] = i;

	do
	{
		int s = a[0];
		int c = 0, last_good = 0;
		for (; c < n; ++c)
		{
			int v = a[c];
			if (g[v] == s)
			{
				if (c == 1)
				{
					last_good = 1;
					continue;
				}
				else
				{
					break;
				}
			}

			if (c < n - 1)
			{
				int next = a[c + 1];
				if (g[v] == next)
					continue;
				else if (c > 0)
				{
					int prev = a[c - 1];
					if (g[v] == prev)
					{
						last_good = c;
						continue;
					}
					else
					{
						c = last_good;
						break;
					}
				}
				else
				{
					c = last_good;
					break;
				}
			}

			if (c == n - 1)
			{
				int prev = a[c - 1];
				if (g[v] == prev)
				{
					break;
				}
				else
				{
					c = last_good;
					break;
				}
			}
		}

		answer = max(answer, c + 1);

	}
	while (next_permutation(a.begin(), a.end()));
	cout << answer << endl;
}

int main()
{
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}