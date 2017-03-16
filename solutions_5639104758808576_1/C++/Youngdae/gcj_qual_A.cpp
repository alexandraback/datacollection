#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("output.txt");

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": ";
		
		int smax;
		string s;
		int sum=0, ans=0;

		fin >> smax >> s;

		for(int i=0; i<smax; i++)
		{
			sum += s[i]-'0';

			if(s[i+1]!='0' && sum<(i+1))
			{
				ans += i+1-sum;
				sum = i+1;
			}
		}

		fout << ans << endl;
	}

	return 0;
}