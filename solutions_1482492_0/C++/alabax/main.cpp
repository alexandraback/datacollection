#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

double D;
int N, A;
double x[2];
double t[2];
double a[10];

void solve()
{
	fout << endl;
	for (int k=0;k<A;++k)
	{
		double total = sqrt(2.0*D/a[k]);
		if (N!=1)
		{
			double v = (x[1] - x[0])/(t[1] - t[0]);
			double cross = (v + sqrt(v*v + 2.0*a[k]*x[0])) / a[k];
			if (cross < total)
			{
				total = cross;
				double p = a[k] * cross * cross / 2.0;
				total += (D - p) / v;
			}
		}
		fout << total << endl;
	}
}

int main()
{
	int T;
	fin >> T;
	fout.precision(8);
	fout.setf(ios::fixed, ios::floatfield);	
	for (int i=0;i<T;++i)
	{
		fin >> D >> N >> A;
		
		for (int k=0;k<N;++k) fin >> t[k] >> x[k];
		for (int k=0;k<A;++k) fin >> a[k];
		
		fout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}