// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int maxn = 20;
int a[maxn][maxn];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int t = 0;
	cin >> t;
	for (int l = 0; l < t; ++l)
	{
		int x, y, z, k;
		cin >> x >> y >> z >> k;
		if (z < k) k = z;
		cout << "Case #" << (l + 1) << ": " << x * y * k << endl;
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < z; ++j) a[i][j] = (i + j) % z + 1;
		int start = 0;
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				for (int p = 0; p < k; ++p) cout << i + 1 << " " << j + 1 << " " << a[p][(start + j) % y] << endl;
			}
			start++;
		}
	}
	
	
	return 0;
}

