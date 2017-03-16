
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
#include <iomanip>
#define UINT64 unsigned __int64
using namespace std;
ifstream  fin("b.txt");
ofstream  fout("c.txt");

void solve(double x, double c, double f)
{
	double time		= x / 2;
	double diffTime;
	double rate = 2;
	unsigned int i;
	unsigned int j;
	
	while (true)
	{
		diffTime = ((c-x)/(rate))+(x/(rate+f));
		//got the best result
		if (diffTime > 0)
		{
			break;
		}
		rate += f;
		time += diffTime;
	}

	fout << time << endl;
	

}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int j;
	double x;
	double f;
	double c;
	char b;
	fin >> b;
	fin >> b;
	fin >> b;
	fin >> numOfTests;
	fout.precision(10);
	fout.setf(std::ios::fixed, std::ios::floatfield);

	for (i = 0; i<numOfTests; i++)
	{
		fin >> c>>f>>x;
	
		fout << "Case #"<<i+1<<": ";
		solve(x,c,f);
	}
}
