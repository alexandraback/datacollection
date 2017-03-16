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

	for (int tt = 0; tt<TT; tt++)
	{
		bool win = false;

		int x, r, c;
		fin >> x >> r >> c;

		switch (x)
		{
    		case 1:
				break;
			case 2:
				if ((r*c) % 2 == 1)
					win = true;
				break;
			case 3:
				switch (r)
				{
				   case 1:
					   win = true;
					   break;
				   case 2:
					   if (c != 3)
						   win = true;
					   break;
				   case 3:
					   if (c == 1)
						   win = true;
					   break;
				   case 4:
					   if (c != 3)
						   win = true;
					   break;
				}
				break;
			case 4:
				switch (r)
				{
    				case 1:
						win = true;
						break;
					case 2:
						win = true;
						break;
					case 3:
						if (c != 4)
							win = true;
						break;
					case 4:
						if (c < 3)
							win = true;
						break;
				}
				break;
		}

		if (win)
		    fout << "Case #" << tt + 1 << ": " << "RICHARD" << endl;
		else
			fout << "Case #" << tt + 1 << ": " << "GABRIEL" << endl;
	}

	return 0;
}

