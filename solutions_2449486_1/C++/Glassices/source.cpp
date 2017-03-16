#include <iostream>
#include <cstring>
using namespace std;

int a[110][110], l[110][110], r[110][110], u[110][110], d[110][110];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int step = 1; step <= T; step++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				u[i][j] = d[i][j] = i;
				l[i][j] = r[i][j] = j;
			}
		int can = 1;
		for (int h = 1; h <= 100; h++) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) if (a[i][j] <= h) {
					if (i > 0 && a[i-1][j] <= h) u[i][j] = u[i-1][j];
					if (j > 0 && a[i][j-1] <= h) l[i][j] = l[i][j-1];
				}
			for (int i = n-1; i >= 0; i--)
				for (int j = m-1; j >= 0; j--) {
					if (i < n-1 && a[i+1][j] <= h) d[i][j] = d[i+1][j];
					if (j < m-1 && a[i][j+1] <= h) r[i][j] = r[i][j+1];
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (a[i][j] == h && (l[i][j] != 0 || r[i][j] != m-1) && (u[i][j] != 0 || d[i][j] != n-1))
						can = 0;
			if (! can) break;
		}
		cout << "Case #" << step << ": ";
		if (can)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

