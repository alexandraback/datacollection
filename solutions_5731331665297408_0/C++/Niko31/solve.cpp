#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n,m;
		cin >> n >> m;
		vector<string> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int g[10][10];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = 0;

		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			g[x-1][y-1] = g[y-1][x-1] = 1;
		}
		vector<int> por(n);
		for (int i = 0; i < n; i++)
			por[i] = i;
		bool f =  true;
		cerr << 1;
		string ans = "A";
		while (f)
		{
			string cur = s[por[0]];
			vector<bool> used(n, 0);
			used[por[0]] = true;
			for (int i = 1; i < n; i++)
			{
				bool ys = false;
				for (int j = 0; j < n; j++)
					if (used[j])
					{
						if (g[j][por[i]]) ys = true;
					}
				if (!ys) break;
				cur += s[por[i]];
				used[por[i]] = true;
			}
			if (cur.length() == n * 5) ans = min(cur, ans);
			f = next_permutation(por.begin(), por.end());
		}
		cout << ans << "\n";

	}
}