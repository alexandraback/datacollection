#include <iostream>
#include <vector>
using namespace std;
int d[101][31][101];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		for (int i = 0; i < 101; ++i)
			for (int j = 0; j <= 30; ++j)
				for (int z = 0; z < 101; ++z)
					d[i][j][z] = 0;
		cout << "Case #" << counter << ": ";
		int n, s, p;
		cin >> n >> s >> p;
		vector<int> a(n + 1);
		for (int i = 0; i < n; ++i)
			cin >> a[i + 1];
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= 30; ++j)
				for (int z = 0; z <= n; ++z)
				{
					for (int t = 0; t <= a[i]; ++t)
						if (a[i] == 3 * t || a[i] - 2 * t + 1 == t || a[i] - 2 * t + 1 == t - 1)
								d[i][j][z] = max(d[i][j][z], d[i - 1][j][z] + (t >= j));
						else
							if (z >= 1 && a[i] - 2 * t + 2 <= t && a[i] - 2 * t + 2 >= t - 2)
								d[i][j][z] = max(d[i][j][z], d[i - 1][j][z - 1] + (t >= j));
				}
		cout << d[n][p][s] << endl;
	}
}