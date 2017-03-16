
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

unsigned int pArray[1000];

void solve(unsigned int numOfPeople)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	split;
	unsigned int	temp;
	unsigned int	res =1001;

	for (i=1; i<1001;i++)
	{
		temp = i;
		for (j=0; j<numOfPeople;j++)
		{
			if (pArray[j] <= i)
			{
				continue;
			}
			else if (pArray[j]%i)
			{
				temp+= (pArray[j]/i);
			}
			else
			{
				temp+= (pArray[j]/i)-1;
			}
		}

		if (temp< res)
		{
			res = temp;
		}
	}

	fout << res << endl;

}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int j;
	unsigned int first;
	

	fin >> numOfTests;

	for (i = 0; i<numOfTests; i++)
	{
		fin >> first;
		for (j = 0; j < first; j++)
		{
			fin >> pArray[j];
		}

		fout << "Case #"<<i+1<<": ";
		solve(first);
	}
}
