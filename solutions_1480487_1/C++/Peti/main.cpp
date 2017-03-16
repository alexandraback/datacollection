#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("a2.txt");
	ofstream fout("a2_sol.txt");

	int t;
	fin >> t;
	for ( int tt = 1; tt <= t; ++tt )
	{
		int n;
		fin >> n;
		vector<int> a(n);
		for ( int i = 0; i < n; ++i ) fin >> a[i];
		vector<int> v(a);

		int sum = 0;
		for ( int i = 0; i < n; ++i ) sum += a[i];
		a.push_back(sum*201);
		a.push_back(0);
		sort(a.begin(),a.end());
		double vsum = (double)sum;

		double level = 0;
		int next = 0;
		while ( next <= n )
		{
			if ( sum < (a[next+1]-a[next])*next )
			{
				level += ((double)sum)/((double)next);
				break;
			}
			sum -= (a[next+1]-a[next])*next;
			next += 1;
			level = (double)a[next];
		}

		fout << "Case #" << tt << ":";
		for ( int i = 0; i < n; ++i )
		{
			if ( (double)v[i] >= level )
			{
				fout << " 0.0";
			}
			else
			{
				fout.precision(10);
				fout << " " << (level - (double)v[i]) * 100.0 / vsum;
			}
		}
		fout << "\n";
	}

	fin.close();
	fout.close();
}