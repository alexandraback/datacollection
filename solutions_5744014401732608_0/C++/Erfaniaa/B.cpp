#include <bits/stdc++.h>

using namespace std;

int t;
int mat[110][110];

int main()
{
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n;
		long long m;
		cin >> n >> m;
		if ((1ll << (n - 2)) < m)
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		else
			cout << "POSSIBLE" << endl;
		memset(mat, 0, sizeof mat);
		mat[1][n] = 1;
		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n - 1; j++)
				mat[i][j] = 1;
		m--;
		for (int i = 0; i < 60; i++)
			if ((1ll << i) & m)
				mat[i + 2][n] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << mat[i][j];
			cout << endl;
		}
	}
	return 0;
}