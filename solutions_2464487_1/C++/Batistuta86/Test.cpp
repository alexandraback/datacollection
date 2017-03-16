// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<__int64> r_s;
	std::vector<__int64> t_s;
	//std::vector<__int64> n_s;
	char *inname = "C:/Test/Debug/A-large.in";
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
		__int64 c;
		infile>>c;
		r_s.push_back(c);
		infile>>c;
		t_s.push_back(c);
	}	
	
	FILE * pFile;
    pFile = fopen ("out.txt","w+");	

	for (int i=0; i<numCases; i++)
	{			
		__int64 n= 0;
		__int64 limit = (__int64)(sqrt(t_s[i]*0.5))+1;
		while(true)
		{
			__int64 n2 = n+1;			
			if (n>limit)
			{
				n = (n+1)/2;
				continue;
			}
			if ((n*(2*(n+r_s[i])-1)<=t_s[i]) && (n2*(2*(n2+r_s[i])-1)>t_s[i])) break;
			
			if ((n*(2*(n+r_s[i])-1)<=t_s[i]) && (n*(2*(n+r_s[i])-1)>=0))
				n = (n+limit)/2;
			else
			{
				limit = n;
				n = (n+1)/2;				
			}
		}
		fprintf (pFile, "Case #%d: %d\n",i+1,n);
		cout<<i;
	}
	fclose (pFile);
	
	return 0;
}

