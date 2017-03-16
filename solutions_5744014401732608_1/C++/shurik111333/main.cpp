#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("2.in");
ofstream fout("2.out");

ll t, n, m;

const string impos = "IMPOSSIBLE";
const string poss = "POSSIBLE";
int a[100][100] = {};

ll pow1(ll a, ll b)
{
	if (b == 0)
		return 1;
	if ((b & 1) == 0)
	{
		ll t = pow1(a, b / 2);
		return t * t;
	}
	return a * pow1(a, b - 1);
}

void print()
{
	fout << poss << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fout << a[i][j];
		fout << "\n";
	}
}

int main()
{
	fin >> t;
	for (int qq = 0; qq < t; qq++)
	{
		fout << "Case #" << qq + 1 << ": ";
		fin >> n >> m;
		ll maxRes = pow1(2, n - 2);
		if (m > maxRes)
		{
			fout << impos << "\n";
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				a[i][j] = 1;
		}
		if (m == maxRes)
		{
			print();
			continue;
		}
		a[0][n - 1] = 0;
		ll q = 1;
		for (int i = 0; i < n - 2; i++)
		{
			if ((m & q) == 0)
			{
				a[0][n - 2 - i] = 0;
			}
			q *= 2;
		}
		print();
		fout << "\n";
	}
	//cout << "OK";
	return 0;
}
