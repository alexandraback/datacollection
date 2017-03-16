#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> l[1000];
bool used[1000];
int deg_in[1000];

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < l[v].size(); ++i)
	{
		deg_in[l[v][i]]++;
		if (!used[l[v][i]])
			dfs(l[v][i]);
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			l[i].clear();
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j)
			{
				int temp;
				cin >> temp;
				--temp;
				l[i].push_back(temp);
			}
		}
		bool yes = false;
		for (int i=  0; i < n && !yes; ++i)
			if (l[i].size() >= 2)
			{
				for (int j = 0; j < n; ++j)
				{
					used[j] = false;
					deg_in[j] = 0;
				}
				dfs(i);
				for (int j = 0; j < n; ++j)
					if (used[j] && deg_in[j] >= 2)
					{
						yes = true;
						break;
					}
			}
		if (yes)
			cout <<"Yes";
		else
			cout <<"No";
		cout << endl;
	}
}