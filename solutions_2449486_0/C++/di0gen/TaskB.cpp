#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 101, INF = 1000000000;
int a[MAXN][MAXN];
int maxc[MAXN],
	maxr[MAXN];

int main()
{
	ifstream cin ("input.txt");
	ofstream cout("output.txt");

	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		int	n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		for (int i = 0; i < n; i++)
		{
			maxr[i] = -INF;
			for (int j = 0; j < m; j++)
				maxr[i] = max(maxr[i], a[i][j]);
		}

		for (int j = 0; j < m; j++)
		{
			maxc[j] = -INF;
			for (int i = 0; i < n; i++)
				maxc[j] = max(maxc[j], a[i][j]);
		}

		bool ok = true;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!(a[i][j] == maxr[i] || a[i][j] == maxc[j]))
					ok = false;

		cout << "Case #" << test + 1 << ": ";
		cout << (ok ? "YES" : "NO");
		cout << endl;
	}
	return 0;
}