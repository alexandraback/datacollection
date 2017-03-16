#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin("c2.txt");
	ofstream fout("c2_sol.txt");

	vector<int> ten(9,1);
	for ( int i = 1; i < 9; ++i ) ten[i] = 10*ten[i-1];

	vector<int> used(10);

	int t;
	fin >> t;
	for ( int tt = 1; tt <=t; ++tt )
	{
		int a, b;
		fin >> a >> b;

		int tmp = a;
		int digits = 1;
		while ( tmp = tmp / 10 ) ++digits;
		
		int res = 0;
		for ( int n = a; n <= b; ++n )
		{
			int numUsed = 0;
			for ( int split = 1; split < digits; ++split )
			{
				int m = (n % ten[split]) * ten[digits - split] + (n / ten[split]);
				bool ok = true;
				for ( int i = 0; i < numUsed; ++i ) if ( m == used[i] ) ok = false;
				if ( ok && n < m && m <= b )
				{
					++res;
					used[numUsed] = m;
					++numUsed;
				}
			}
		}
		
		fout << "Case #" << tt << ": " << res << '\n';
	}

	fin.close();
	fout.close();
}