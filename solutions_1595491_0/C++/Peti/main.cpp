#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("b.txt");
	ofstream fout("b_sol.txt");

	int t;
	fin >> t;
	for ( int tt = 1; tt <=t; ++tt )
	{
		int n,s,p;
		fin >> n >> s >> p;
		vector<int> a(n);
		for ( int i = 0; i < n; ++i ) fin >> a[i];

		int res = 0;
		int amin = p + (p-1) + (p-1);
		if ( amin < p ) amin = p;
		int smin = p + (p-2) + (p-2);
		if ( smin < p ) smin = p;

		for ( int i = 0; i < n; ++i )
		{
			if ( a[i] >= amin )
				++res;
			else
			{
				if ( s && a[i] >= smin )
				{
					++res;
					--s;
				}
			}
		}

		fout << "Case #" << tt << ": " << res << '\n';
	}

	fin.close();
	fout.close();
}