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
	//std::vector<__int> r_s;
	//std::vector<__int64> t_s;
	//std::vector<__int64> n_s;
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
	
	//for (int i=0; i<numCases; i++)
	int r,n,m,k;
	{
		
		infile>>r;
		infile>>n;
		infile>>m;
		infile>>k;
		
	}	
	
	FILE * pFile;
    pFile = fopen ("out.txt","w+");	
	fprintf (pFile, "Case #1:\n");
	for (int i=0; i<r; i++)
	{	
		int proizvod;
		int cnt1, cnt2, cnt3;
		int num1=2;
		int num2=2;
		int num3=2;
		
		for (int j=0; j<k; j++)
		{
			bool bNadjen = false;
			infile>>proizvod;
			if (proizvod<num1*num2*num3) continue;
			for (cnt1=m; cnt1>1; cnt1--)
			{
				for (cnt2=m; cnt2>1; cnt2--)
				{
					for (cnt3=m; cnt3>1; cnt3--)
					{
						if (cnt1*cnt2*cnt3==proizvod)
						{
							bNadjen = true;
							break;
						}
					}
					if (bNadjen) break;
				}
				if (bNadjen) break;
			}

			if (bNadjen)
			{
				num1 = cnt1;
				num2 = cnt2;
				num3 = cnt3;
			}
		}
		

		
		fprintf (pFile, "%d%d%d\n",num1, num2, num3);		
	}
	fclose (pFile);
	
	return 0;
}

