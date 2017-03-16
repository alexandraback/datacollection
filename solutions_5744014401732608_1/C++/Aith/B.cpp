#include <bits/stdc++.h>

using namespace std;

ifstream fin("B.in");
ofstream fout("output.out");

// #define fin cin
// #define fout cout

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	fin >> t;
	int u = 0;
	while (u++ < t)
	{
		fout << "Case #" << u << ": ";
		long long int b, m;
		fin >> b >> m;
		long long int maxN = 1 << (b - 2);
		if (maxN < m) fout << "IMPOSSIBLE\n";
		else
		{
			fout << "POSSIBLE\n";
			if (maxN == m)
			{
				for (int i = 0; i < b; ++i)
				{
					for (int j = 0; j < b; ++j)
					{
						if (j > i) fout << 1;
						else fout << 0;
					}
					fout << endl;
				}
			}
			else
			{
				for (int i = 0; i < b; ++i)
				{
					for (int j = 0; j < b; ++j)
					{
						if (j == b-1)
						{
							fout << (bool)(m & (1 << (i - 1)));
						}
						else if (j > i) fout << 1;
						else fout << 0;
					}
					fout << endl;
				}
			}
		}
	}
	return 0;
}