// probB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

int a[1000];
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("data.in");
	ofstream fout("data.out");
	int tt;
	fin >> tt;
	int j;
	for (j = 1; j <= tt; j++)
	{
		int b;
		long long m;
		fin >> b >> m;
		long long aux = m;
		int t = 0;
		for (int i = 0; i<200; i++) a[i] = 0;
		while (aux > 0)
		{
			t++;
			a[t] = aux % 2;
			aux /= 2;
		}
		fout << "Case #" << j << ": ";
		if (t >= b) fout << "IMPOSSIBLE" << '\n';
		else
		{
			fout << "POSSIBLE" << '\n';
			int i;
			for (i = 1; i <= b; i++)
			{
				for (int l = 1; l < b; l++)
				{
					if (l <= i) fout << '0';
					else fout << '1';
				}
				fout << a[i] << '\n';
			}
		}
	}
	return 0;
}

