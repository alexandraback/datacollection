
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


	


void solve(int r, int c, int x)
{
	bool res;
	
	do 
	{
		if (x == 1)
		{
			res =true;
			break;
		}
		else if ((1 == r)||(1 == c))
		{
			res = false;
			break;
		}
		else if ((r*c)%x)
		{
			res =false;
			break;
		}
		else if ((x >r )&& (x >c))
		{
			res =false;
			break;
		}
		if ((x == 4)&&((r ==2 )||(c ==2 )))
		{
			res =false;
			break;
		}
		res = true;
	} while (false);
	

	if (false == res)
	{
		fout << "RICHARD" << endl;
	}
	else
	{
		fout << "GABRIEL" << endl;
	}

	
}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int j;
	
	int x;
	int r;
	int c;

	fin >> numOfTests;

	for (i = 0; i<numOfTests; i++)
	{
		fin >> x>>r>>c;

		fout << "Case #"<<i+1<<": ";
		solve(r,c,x);
	}
}
