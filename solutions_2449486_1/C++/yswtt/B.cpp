#include <iostream>
using namespace std;

int main()
{
	int i, j, n, m, t, tt;
	int a[102][102];
	int mr[102];
	int mc[102];
	bool s;
	
	cin >> t;
	for (tt = 1; tt <= t; ++tt)
	{
		cin >> n >> m;
		for (i = 0; i < n; ++i)
			mr[i] = 0;
		for (i = 0; i < m; ++i)
			mc[i] = 0;
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
			{
				cin >> a[i][j];
				if (a[i][j] > mr[i])
					mr[i] = a[i][j];
				if (a[i][j] > mc[j])
					mc[j] = a[i][j];
			}
		s = true;
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
			{
				if ((a[i][j] < mr[i]) && (a[i][j] < mc[j]))
					s = false;
			}
		cout << "Case #" << tt << ": ";
		if (s)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
