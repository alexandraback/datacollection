#include <fstream>
#include <iostream>
#include <string.h>

#define SIZE 1200

using namespace std;

int main()
{
	ifstream infile("C-small-attempt0.in");
	ofstream outfile("C-output");

	int t;
	infile >> t;
	for (int ca = 1; ca <= t; ++ca)
	{
		int n;
		infile >> n;

		int ans = 0;
		int a[SIZE];
		memset(a, '\0', sizeof(a));
		int b[SIZE][SIZE];
		memset(b, '\0', sizeof(b));

		for (int i = 1; i <= n; ++i)
			infile >> a[i];

		for (int i = 1; i <= n; ++i)
		{
			bool f[SIZE];
			memset(f, '\0', sizeof(f));
			f[i] = true;
			int x = a[i];
			int cnt = 1;
			int prev = i;
			while (!f[x])
			{
				if (cnt > b[x][prev]) b[x][prev] = cnt;
				++cnt;
				f[x] = true;
				prev = x;
				x = a[x];
			}
		}

		for(int i = 1; i <= n; ++i)
		{
			bool f[SIZE];
			memset(f, '\0', sizeof(f));
			f[i] = true;
			int x = a[i];
			int cnt = 1;
			while (!f[x])
			{
				++cnt;
				f[x] = true;
				x = a[x];
			}
			if (x == i && cnt > ans) ans = cnt;
			if (cnt == 2)
			{
				int x1 = 0, x2 = 0;
				for (int j = 1; j <= n; ++j)
					if (j != i && j != a[i])
					{
						if (b[i][j] > x1) x1 = b[i][j];
						if (b[a[i]][j] > x2) x2 = b[a[i]][j];
					}
				cnt = cnt + x1 + x2;
				if (cnt > ans) ans = cnt;
			}
		}
		outfile << "Case #" << ca << ": " << ans << endl; 
	}

	return 0;
}