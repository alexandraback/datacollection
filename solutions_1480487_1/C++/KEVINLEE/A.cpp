#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

main()
{
	ifstream fin("A-large.in");
	ofstream fout("Al.txt");
	fout << fixed << setprecision(6);
	int x, n;
	fin >> x;
	for (int cnt = 1; cnt <= x; ++cnt)
	{
		fin >> n;
		int v[n];
		double t = 0;
		for (int i = 0; i < n; ++i)
		{
			fin >> v[i];
			t += v[i];
		}
		double p = t * 2 / n, pi = t * 2, ni = n;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] >= p)
			{
				pi -= v[i];
				--ni;
			}
		}
		fout << "Case #" << cnt << ": ";
		//fout << pi << endl;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] >= p)
				fout << 0.00000 << ' ';
			else
				fout << (pi / ni - v[i]) / (t) * 100 << ' ';
		}
		fout << endl;
	}	
}
