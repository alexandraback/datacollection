#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[200][200];

#define for if (0) ; else for

int maxn(int a, int b)
{
	return a > b ? a : b;
}

int minn(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	ifstream ifs("2.in");
	ofstream ofs("2.out");


	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n,m;
		ifs >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ifs >> a[i][j];

		vector<int> rmax(n, 0);
		vector<int> cmax(m, 0);
		for (int i = 0; i < n; ++i)
		{
			rmax[i] = 0;
			for (int j = 0; j < m; ++j)
			{
				rmax[i] = maxn(rmax[i], a[i][j]);
			}
		}
		for (int j = 0; j < m; ++j)
		{
			cmax[j] = 0;
			for (int i = 0; i < n; ++i)
			{
				cmax[j] = maxn(cmax[j], a[i][j]);
			}
		}
		bool ok = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (minn(rmax[i], cmax[j]) != a[i][j])
					ok = false;
		ofs << "Case #" << test+1 << ": " << (ok ? "YES\n" : "NO\n");

	}
	return 0;
}

