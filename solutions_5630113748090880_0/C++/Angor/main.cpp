#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	freopen( "..\\input.txt", "r", stdin );
	freopen( "..\\output.txt", "w", stdout );

	int t;
	cin >> t;
	for( int tt = 1; tt <= t; tt++ )
	{
		int n;
		cin >> n;
		vector<vector<int>> lines(2 * n - 1, vector<int>(n));
		for (int i = 0; i < 2 * n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> lines[i][j];
			}
		}

		vector<int> ans(n);
		vector<int> diag(n);
		vector<bool> used(2 * n - 1, false);

		int bestD;
		int bestI;
		int count;
		int notFound = -1;
		int oppLine;
		for (int d= 0; d < n; d++)
		{
			bestD = -1;
			count = 0;
			for (int i = 0; i < lines.size(); i++)
			{
				if (used[i])
				{
					continue;
				}
				if (lines[i][d] == bestD)
				{
					count++;
				}
				if (lines[i][d] < bestD || count == 0)
				{
					count = 1;
					bestD = lines[i][d];
					bestI = i;
				}
			}

			diag[d] = bestD;
			for (int i = 0; i < lines.size(); i++)
			{
				if (lines[i][d] == bestD)
				{
					used[i] = true;
				}
			}

			if (count != 2)
			{
				notFound = d;
				oppLine = bestI;
			}
		}

		ans[notFound] = diag[notFound];
		for (int d = 0; d < n; d++)
		{
			ans[d] = lines[oppLine][d];
			
			for (int j = 0; j < lines.size(); j++)
			{
				if (lines[j][d] == diag[d] && lines[j][notFound] != lines[oppLine][d])
				{
					ans[d] = lines[j][notFound];
				}
			}
		}
		//printf( "Case #%d: ", tt );
		cout << "Case #" << tt << ":";
		for (int i = 0; i < n; i++)
		{
			cout << " " << ans[i];
		}
		cout << endl;
	}
	return 0;
}