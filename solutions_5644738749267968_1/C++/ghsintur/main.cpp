
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

double nomArr[1000];
double kenArr[1000];
double kenArrForCheat[1000];

bool  kenChoose(double nomChoose, unsigned int num, double* pKenArr)
{
	double kenNum = -1;
	 int kenIndex = -1;

	unsigned int i;

	for (i = 0; i < num; i++)
	{
		if (pKenArr[i] < 0)
		{
			continue;
		}

		if ((nomChoose > pKenArr[i]))
		{
			if ((kenIndex > 0))
			{
				continue;
			}
			else
			{
				kenIndex = i;
				kenNum = pKenArr[i];
			}
			
		}
		else
		{
			kenIndex = i;
			kenNum = pKenArr[i];
			break;
		}
	}
	//for bugs
	while (kenIndex < 0);
	while (kenNum < 0);
	//invalid
	pKenArr[kenIndex] = -1;
	return (kenNum > nomChoose);
}

unsigned int war(unsigned int num)
{
	unsigned int i;
	unsigned int res = 0;
	double Ken;

	for (i = 0; i < num; i++)
	{
		if (false == (kenChoose(nomArr[i], num, kenArr)))
		{
			res = num - i;
			break;
		}
	}

	return res;
}

bool isNomWanAll(unsigned int num, unsigned int offset, double* pKenArr)
{
	unsigned int i;
	bool bres = true;

	for (i = offset; i < num; i++)
	{
		if (nomArr[i] < pKenArr[i])
		{
			bres = false;
			break;
		}
	}

	return bres;
}

unsigned int warCheat(unsigned int num)
{
	unsigned int i;
	unsigned int res = 0;
	unsigned int kenIndex =0;
	double nomChoose;

	for (i = 0; i < num; i++)
	{
		if (nomArr[i] < kenArrForCheat[kenIndex])
		{
			kenArrForCheat[num - i - 1] = -1;
		}
		else
		{
			kenArrForCheat[kenIndex] = -1;
			kenIndex++;
			res++;
		}
	}

	return res;
}

void solve(unsigned int num)
{
	unsigned int resWar;
	unsigned int cheatWar;

	sort(nomArr, nomArr+num);
	sort(kenArr, kenArr+num);
	memcpy(kenArrForCheat, kenArr, sizeof(kenArr));

	resWar = war(num);
	cheatWar = warCheat(num);

	fout <<cheatWar<<" " <<resWar<<endl;
}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int j;
	unsigned int num;
	char b;
	fin >> b;
	fin >> b;
	fin >> b;
	fin >> numOfTests;
	

	for (i = 0; i<numOfTests; i++)
	{
		fin >> num;
		for (j= 0; j < num; j++)
		{
			fin >> nomArr[j];
		}
		for (j = 0; j < num; j++)
		{
			fin >> kenArr[j];
		}
	
		fout << "Case #"<<i+1<<": ";
		solve(num);
	}
}
