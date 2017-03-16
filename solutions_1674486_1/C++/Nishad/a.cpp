#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool found;

void func(vector<bool>& visited, int now, const vector< vector<int> >& inh)
{
	if (found)
		return;

	visited[now] = true;

	for (int i = 0; i < inh[now].size(); i++)
	{
		if (visited[inh[now][i]])
		{
			found = true;
			return;
		}

		func(visited, inh[now][i], inh);
	}
}

int main()
{
	int t;

	cin >> t;

	for (int c = 0; c < t; c++)
	{
		int n;

		cin >> n;

		vector< vector<int> > inh(n);

		for (int i = 0; i < n; i++)
		{
			vector<int> temp;
			int m;

			cin >> m;
			for (int x = 0; x < m; x++)
			{
				int a;
				cin >> a;
				temp.push_back(a - 1);
			}

			inh[i] = temp;
		}

		found = false;

		for (int i = 0; i < n; i++)
		{
			vector<bool> visited(n, false);
			func(visited, i, inh);
			if (found)
				break;
		}

		cout << "Case #" << (c + 1) << ": ";
		if (found) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
