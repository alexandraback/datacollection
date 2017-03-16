#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int T;
int n;
double tmp;
vector<double> mine, yours;
int y, z;
int main()
{
	ifstream fin("D-large.in");
	ofstream fout("d.out");
	fin >> T;
	for(int t=1; t<=T; ++t)
	{
		fin >> n;
		mine.clear();
		yours.clear();
		for(int i=0; i<n; ++i)
		{
			fin >> tmp;	
			mine.push_back(tmp);
		}
		for(int i=0; i<n; ++i)
		{
			fin >> tmp;
			yours.push_back(tmp);	
		}
		sort(mine.begin(), mine.end());
		sort(yours.begin(), yours.end());
		y = 0;
		z = 0;
		int j = 0;
		for(int i=0; i<n; ++i)
		{
			if (mine[i] > yours[j])
				++j;
		}
		y = j;
		j = 0;
		for(int i=0; i<n; ++i)
		{
			if (yours[i] > mine[j])	
				++j;
		}
		z = n-j;
		
		fout << "Case #" << t << ": "<< y << " " << z << endl;
	}
	fin.close();
	fout.close();
}
