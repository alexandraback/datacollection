#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("c.txt");
	ofstream fout("c_sol.txt");

	int t;
	fin >> t;
	for ( int tt = 1; tt <= t; ++tt )
	{
		int n;
		fin >> n;
		vector<int> a(n);
		for ( int i = 0; i < n; ++i ) fin >> a[i];

		vector<int> sum(1<<20);
		for ( int i = 1; i < (1<<20); ++i )
		{
			for ( int j = 0; j < n; ++j ) if (i & (1<<j))
			{
				sum[i] += a[j];
			}
		}
		
		int maxsum = 20*100001;
		vector<vector<int>> mark(maxsum);
		for ( int i = 1; i < (1<<20); ++i )
		{
			mark[sum[i]].push_back(i);
		}

		fout << "Case #" << tt <<":\n";
		bool imp = true;
		for ( int i = 0; imp && i < maxsum; ++i ) if (mark[i].size() > 1)
		{
			for ( int j = 0; imp && j < (int)mark[i].size(); ++j )
			{
				for ( int k = j+1; imp && k < (int)mark[i].size(); ++k )
				{
					if ( (mark[i][j] & mark[i][k]) == 0 )
					{
						imp = false;
						bool first = true;
						for ( int ii = 0; ii < n; ++ii )
						{
							if ( mark[i][j] & (1<<ii) )
							{
								if ( first )
								{
									first = false;
								}
								else
								{
									fout << " ";
								}
								fout << a[ii];
							}
						}
						fout <<" \n";
						first = true;
						for ( int ii = 0; ii < n; ++ii )
						{
							if ( mark[i][k] & (1<<ii) )
							{
								if (first)
								{
									first = false;
								}
								else
								{
									fout << " ";
								}
								fout << a[ii];
							}
						}
						fout <<" \n";
					}
				}
			}
		}
		if ( imp )
		{
			fout << "Impossible\n";
		}
	}

	fin.close();
	fout.close();
}