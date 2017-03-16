#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.in");
ofstream fout("out.txt");

int main(int argc, char *argv[])
{
	int t;
	fin >> t;
	for (int i = 1; i <= t; i++)
	{
		int k, c, s;
		fin >> k >> c >> s;
		fout << "Case #" << i << ": ";
		for (int j = 1; j <= s; j++)
			fout << j << " ";
		fout << "\n";
	}
	return 0;
}
