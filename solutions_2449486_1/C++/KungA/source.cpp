#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n, m;
		int a[100][100];
		string ans = "YES";
		vector<int> v[101];

		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				v[a[i][j]].push_back(i * 100 + j);
			}

		for (int k = 0; k < 101; k++)
			for (int u = 0; u < v[k].size(); u++)
			{
				int x = v[k][u] / 100, y = v[k][u] % 100;

				bool can = 1;
				for (int i = 0; i < n; i++)
					if (a[i][y] > a[x][y])
						can = 0;
				if (can)
					continue;

				can = 1;
				for (int i = 0; i < m; i++)
					if (a[x][i] > a[x][y])
						can = 0;

				if (!can)
					ans = "NO";
			}

		cout << "Case #" << t + 1 << ": " << ans << endl;	

		/*for (int i = 0; i < n; i++) 
		{
			cout << "\t";
			for (int j = 0; j < m; j++)
				cout << a[i][j];
			cout << endl;
		}*/
		
	}
}
































