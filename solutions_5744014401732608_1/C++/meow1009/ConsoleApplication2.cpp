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

const int maxn = 60;

long long two[maxn];
long long m;
int b;

int a[maxn][maxn];


void init()
{
	two[0] = 1;
	for (int i = 1; i < maxn; ++i) two[i] = (long long)2 * two[i - 1];
}


int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int t = 0;
	init();
	cin >> t;
	for (int l = 0; l < t; ++l)
	{
		memset(a, 0, sizeof(a));
		cin >> b >> m;
		cout << "Case #" << l + 1 << ": ";
		int k = 0;
		while (two[k + 1] <= m) k++;
		if (two[k] == m) {
			if (b - 2 < k)
			{
				cout << "IMPOSSIBLE" << endl;
				continue;
			}
			cout << "POSSIBLE" << endl;
			a[k][b - 1] = 1;
			for (int i = k - 1; i >= 0; --i)
			{
				for (int j = i + 1; j <= k; ++j) a[i][j] = 1;
				a[i][b - 1] = 1;
			}
			for (int i = 0; i < b; ++i)
			{
				for (int j = 0; j < b; ++j) cout << a[i][j];
				cout << endl;
			}
		}
		else
		{
			if (b - 3 < k)
			{
				cout << "IMPOSSIBLE" << endl;
				continue;
			}
			cout << "POSSIBLE" << endl;
			a[k + 1][b - 1] = 1;
			for (int i = k; i >= 1; --i)
			{
				for (int j = i + 1; j <= k + 1; ++j) a[i][j] = 1;
				a[i][b - 1] = 1;
			}
			int k0 = k;
			while (k >= 0 && m != 0)
			{
				while (two[k] > m) --k;
				m -= two[k];
				a[0][k0 - k + 1] = 1;
			}
			if (m != 0) a[0][b - 1] = 1;
			for (int i = 0; i < b; ++i)
			{
				for (int j = 0; j < b; ++j) cout << a[i][j];
				cout << endl;
			}
		}
		
	}
	
	
	return 0;
}

