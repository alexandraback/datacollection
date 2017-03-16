#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.in");
ofstream fout("out.txt");

int ans[3500] = {};

int main()
{
	int t;
	fin >> t;
	for (int q = 1; q <= t; q++)
	{
		fout << "Case #" << q << ": ";
		int n;
		fin >> n;
		for (int i = 0; i < 3500; i++)
			ans[i] = 0;
		for (int i = 0; i < 2 * n - 1; i++)
			for (int j = 0; j < n; j++)
			{
				int x;
				fin >> x;
				ans[x]++;
			}
		int c = 0;
		for (int i = 1; i < 3500; i++)
			if ((ans[i] % 2) == 1)
			{
				fout << i << " ";
				c++;
			}
		assert(c == n);
		fout << "\n";
	}
	return 0;
}
