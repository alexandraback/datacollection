
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


void solveAndPrint(unsigned int a, unsigned int b, unsigned int k)
{
	int res =0;
	unsigned int i;
	unsigned int j;
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if((i&j)<k)
			{
				res++;
			}
		}
	}
	
	fout << res <<endl;
}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int l;
	unsigned int j;
	unsigned int c;
	fin >> numOfTests;
	fout << std::setprecision(9) << fixed;
	for (i = 0; i<numOfTests; i++)
	{
		fin >> l;
		fin>>j;
		fin>>c;
		fout << "Case #" << i + 1 << ": ";
		solveAndPrint(l,j,c);

	}
	
}
