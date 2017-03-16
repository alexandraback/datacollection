#include <iostream>
#include <fstream>

using namespace std;
int T;
int n, r, e;
int v[100];
int d[100][100];
bool f[100][100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		cout << "Case #" << test << ": ";
		cin >> e >> r >> n;
		for (int i = 0; i <= e; i++)
			for (int j = 0;  j <= n; j++)
				d[i][j] = 0;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int j = 1; j <= n; j++)
			for (int i = 0; i <= e; i++)
				for (int q = 0; q <= i; q++)
					d[min(e, i - q + r)][j] = max(d[min(e, i - q + r)][j], d[i][j - 1] + q*v[j]);
		int ans = 0;
		for (int i = 0; i <= e; i++)
			ans = max(ans, d[i][n]);
		cout << ans << endl;
	}
}