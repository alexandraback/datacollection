#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <utility>
#include <memory>
#include <malloc.h>
#include <string>
#include <string.h>
#include <fstream>
#include <set>
#include <map>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

typedef long long ll;

int a[150][150];

int main()
{
	int t;
	cin >> t;
	for (int q = 0; q < t; ++q)
	{
		cout << "Case #" << q + 1 << ": ";
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> a[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				bool b = true;
				for (int k = 0; k < n; ++k)
					if (a[i][j] < a[k][j])
					{
						b = false;
						break;
					}
				if (b)
					continue;
				b = true;
				for (int k = 0; k < m; ++k)
					if (a[i][j] < a[i][k])
					{
						b = false;
						break;
					}
				if (b)
					continue;
				cout << "NO\n";
				goto l123;
			}
		cout << "YES\n";
		l123: ;
	}
	return 0;
}