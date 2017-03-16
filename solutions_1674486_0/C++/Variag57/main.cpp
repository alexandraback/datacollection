# include <iostream>
# include <cstdio>
# include <vector>
# include <queue>
# include <bitset>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc)
	{
		cout << "Case #" << tc + 1 << ": " ;
		int n, m, tmp;
		vector<int> sup;
		cin >> n;
		vector<int> start(n, -1);
		vector<int> next;
		vector<int> aim;
		for (int i = 0; i < n; ++i)
		{
			cin >> m;
			if (m == 0)
				sup.push_back(i);
			for (int j = 0; j < m; ++j)
			{
				cin >> tmp; 
				--tmp;
				next.push_back(start[tmp]);
				start[tmp] = next.size() - 1;
				aim.push_back(i);
			}
		}
		
		//bfs
		for (int i = 0; i < sup.size(); ++i)
		{
			queue<int> q;
			q.push(sup[i]);
			bitset<1000> used(0);
			while (!q.empty())
			{
				int v = q.front();
				q.pop();
				int p = start[v];
				while (p != -1)
				{
					if (used[aim[p]] == 0)
					{
						q.push(aim[p]);
						used[aim[p]] = 1;
					}
					else
					{
						cout << "Yes\n";
						goto l;
					}
					p = next[p];
				}
			}
		}
		cout << "No\n";
l:		continue;
	}

	return 0;
}