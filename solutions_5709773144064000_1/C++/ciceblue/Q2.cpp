#include <iostream>
#include <fstream>
#define REP(i,s,n) for(int i=s;i<n;i++)
using namespace std;
ifstream fin("B-large.in");
ofstream fout("out.txt");
int main()
{
	int T;
	fin >> T;
	double c, f, x,r;
	double n;
	double time;
	int i;
	REP(caseNumber, 1, T + 1)
	{
		r = 2.0;
		fin >> c >> f >> x;
		n = (x*f - c*r - c*f) / (c*f);
		time = 0;
		for (i = 0; i < n; ++i)
		{
			time += c / (r + i*f);
		}
		time += x / (r + i*f);
		fout.precision(7);
		fout << "Case #" << fixed << caseNumber << ": "<<time<<"\n";
	}
	return 0;
}