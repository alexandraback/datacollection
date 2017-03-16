
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

unsigned char pPeopleArray[1000];

void solve(unsigned char numOfPeople)
{
	unsigned int	i;
	unsigned int	currentStandingPeople =0;
	unsigned int	res =0;

	for (i=0; i<numOfPeople;i++)
	{
		if ((i > currentStandingPeople)&&(pPeopleArray[i] >0))
		{
			res+= i-currentStandingPeople;
			currentStandingPeople += i-currentStandingPeople;
		}

		currentStandingPeople+=pPeopleArray[i];
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
		first++;
		for (j = 0; j < first; j++)
		{
			fin >> pPeopleArray[j];
			pPeopleArray[j]-= '0';
		}

		fout << "Case #"<<i+1<<": ";
		solve(first);
	}
}
