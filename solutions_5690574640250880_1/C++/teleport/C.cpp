#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define y0 isdnfviu
#define y1 asinhiv
#define fst first
#define snd second
#define count sdifnsugh

char a[55][55];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	for (int g = 1; g <= q; g++)
	{
		cout << "Case #" << g << ":";
		int n, m, kol;
		cin >> n >> m >> kol;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] = '.';
		a[1][1] = 'c';
		bool flag = false;
		if (n == 1 || m == 1)
		{
			flag = true;
			for (int i = n; i >= 1; i--)
				for (int j = m; j >= 1; j--)
					if (kol > 0)
					{
						kol--;
						a[i][j] = '*';
					}
		}
		else if (kol == n * m - 1)
		{
			flag = true;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					a[i][j] = '*';
			a[1][1] = 'c';
		}
		else
		{
			int kol1 = n * m - kol;
			for (int f = 2; f <= n; f++)
				for (int pos = 2; pos <= m; pos++)
					for (int last = 2; last <= f; last++)
					{
						if (flag)
							break;
						int vmax = f * pos, vmin = f * pos - (pos-2) * (f-last);
						if (kol1 >= vmin && kol1 <= vmax)
						{
							flag = true;
							int c = 0;
							for (int i = n; i >= 1; i--)
								for (int j = m; j >= ((i > f) ? 1 : pos + 1); j--)
								{
									c++;
									a[i][j] = '*';
								} 
							for (int i = f; i > last; i--)
								for (int j = pos; j > 2; j--)
								{
									if (c == kol)
										break;
									c++;
									a[i][j] = '*';
								}
						}
					}
		}
		if (!flag)
			cout << "\nImpossible\n";// " << n << " " << m << " " << kol << "\n";
		else
		{
			cout << endl;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
					cout << a[i][j];
				cout << endl;
			}
		}
	}
	cin >> q;
	return 0;
}
