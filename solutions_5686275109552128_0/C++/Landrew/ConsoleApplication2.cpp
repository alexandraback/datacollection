#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin("INP111.txt");

string M[10];

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");


int main() {

	//FILE* pFile;
	//pFile = fopen("ou.txt","w");

	// string na;
	// if (tt == 0)
	//  getline(fin,na);

	// getline(fin,na);

	// istringstream sin(na); 
	// string v; 
	// while (sin>>v) 
	//   names.push_back(v); 

	//fprintf(pFile, "Case #%d: ", t+1);
	//fprintf(pFile,"%d\n",res);

	int TT;
	fin >> TT;

	for (int tt = 0; tt < TT; tt++)
	{
		int d;
		fin >> d;
		int a[1001];
		for (int i = 0; i < d; i++)
		{
			fin >> a[i];
		}

		long long bes = 100000001;

		for (int lev = 1; lev <= 1000; lev++)
		{
			int split = 0;
			for (int i = 0; i < d; i++)
			{
				if (a[i] > lev)
				{
					split += a[i] / lev - 1;
					if (a[i] % lev != 0)
						split++;
				}
			}
			if (bes > lev + split)
				bes = lev + split;
		}

		fout << "Case #" << tt + 1 << ": " << bes << endl;
	}

	return 0;
}

