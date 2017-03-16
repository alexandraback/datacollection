// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> mins;
	std::vector<int> maxs;
	char *inname = "C:/Test/Debug/C-small.in";
    ifstream infile(inname);

	if (!infile) {
        cout << "There was a problem opening file "
             << inname
             << " for reading."
             << endl;
        return 0;
    }

	cout << "Opened " << inname << " for reading." << endl;

	int numCases;

    infile >> numCases;
    cout << "Num of cases is " << numCases << endl;
	
	for (int i=0; i<numCases; i++)
	{
		int c;
		infile>>c;
		mins.push_back(c);
		infile>>c;
		maxs.push_back(c);
	}	

	FILE * pFile;
    pFile = fopen ("out.txt","w+");

	for (int i=0; i<numCases; i++)
	{			
		int cnt=0;
		if ((mins[i]<=1) && (maxs[i]>=1)) cnt++;
		if ((mins[i]<=4) && (maxs[i]>=4)) cnt++;
		if ((mins[i]<=9) && (maxs[i]>=9)) cnt++;
		if ((mins[i]<=121) && (maxs[i]>=121)) cnt++;
		if ((mins[i]<=484) && (maxs[i]>=484)) cnt++;					
		fprintf (pFile, "Case #%d: %d\n",i+1,cnt);
	}
	fclose (pFile);
	
	return 0;
}

