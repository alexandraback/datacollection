#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int caseNum = 1; caseNum <= t; caseNum++)
	{
		int n, m;
		cin >> n >> m;
		int lawn[n][m];
		vector<pair<int, int> > pts[100];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> lawn[i][j];
				lawn[i][j]--;
				pts[lawn[i][j]].push_back(make_pair(i, j));
			}

		bool ok = true;
		for (int i = 0; i < 100; i++)
		{
			for (unsigned int j = 0; j < pts[i].size(); j++)
			{
				pair<int, int> p = pts[i][j];
				bool rOk = true, cOk = true;
				for (int k = 0; k < n; k++)
					if (lawn[k][p.second] > i)
					{
						rOk = false;
						break;
					}
				for (int k = 0; k < m; k++)
					if (lawn[p.first][k] > i)
					{
						cOk = false;
						break;
					}

				if (!rOk && !cOk)
				{
					ok = false;
					break;
				}
			}

			if (!ok)
				break;
		}

		cout << "Case #" << caseNum << ": " << (ok ? "YES" : "NO") << endl;
	}
}
