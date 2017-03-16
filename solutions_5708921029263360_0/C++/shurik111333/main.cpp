#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("3.in");
ofstream fout("3.out");

ll t, J, P, S, K;

int jp[20][20], js[20][20], ps[20][20];

int main()
{
	fin >> t;
	for (int qq = 0; qq < t; qq++)
	{
		fout << "Case #" << qq + 1 << ": ";
		fin >> J >> P >> S >> K;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
			{
				jp[i][j] = 0;
				js[i][j] = 0;
				ps[i][j] = 0;
			}
		int cnt = 0;
		for (int i = 1; i <= J; i++)
		{
			for (int j = 1; j <= P; j++)
			{
				for (int k = 1; k <= S; k++)
				{
					if (jp[i][j] < K && js[i][k] < K && ps[j][k] < K)
					{
						cnt++;
						jp[i][j]++;
						js[i][k]++;
						ps[j][k]++;
					}
				}
			}
		}
		fout << cnt << "\n";
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
			{
				jp[i][j] = 0;
				js[i][j] = 0;
				ps[i][j] = 0;
			}
		for (int i = 1; i <= J; i++)
		{
			for (int j = 1; j <= P; j++)
			{
				for (int k = 1; k <= S; k++)
				{
					if (jp[i][j] < K && js[i][k] < K && ps[j][k] < K)
					{
						fout << i << " " << j << " " << k << "\n";
						jp[i][j]++;
						js[i][k]++;
						ps[j][k]++;
					}
				}
			}
		}
	}
	cout << "OK";
	return 0;
}
