#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("B-small-attempt3.in");
ofstream fout("output.txt");

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": ";
		
		int d, p, div[1001]={0};

		fin >> d;

		for(int i=0; i<d; i++)
		{
			fin >> p;
			for(int maxp=1; maxp<=1000; maxp++)
			{
				if(p%maxp)
					div[maxp] += p/maxp;
				else
					div[maxp] += p/maxp-1;
			}
		}
		
		int ans = div[1]+1;
		for(int i=2; i<=1000; i++)
			if(div[i]+i < ans)
				ans = div[i]+i;

		fout << ans << endl;
	}

	return 0;
}