#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int main()
{
	double r, t, a, b;
	int i, ii;
	long long ans;

	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");
	fin >> ii;
	for (i=1; i<=ii; i++)
	{
		fin >> r >> t;
		a = (1-2*r+sqrt((2*r-1)*(2*r-1)+8*t))/4;
		a += 3;
		ans = long(a);
		while (2*ans*ans-ans+2*ans*r>t) ans--;

		fout << "Case #" << i << ": " << ans << endl;

	}

}