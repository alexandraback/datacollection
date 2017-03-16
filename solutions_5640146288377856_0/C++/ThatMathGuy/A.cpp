#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tc;
int r,c,w;
int rez=0;

int main()
{
	fin>>tc;

	for (int tt=1; tt<=tc; tt++)
	{
		rez=0;
		fin>>r>>c>>w;

		if (c%w) rez= c/w+1;
		else rez = c/w;
		rez*=r;

		rez+=w-1;

		fout<<"Case #"<<tt<<": ";
		fout<<rez;
		fout<<'\n';
	}

	return 0;
}