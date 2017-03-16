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
	std::vector<std::vector<int>> input;
	std::vector<std::vector<std::vector<int>>> cases;
	char *inname = "C:/Test/Debug/B-small.in";
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
		input.clear();
		
		int nRows;
		infile>>nRows;
		int nCols;
		infile>>nCols;
		int c;

		for (int iRow=0; iRow<nRows; iRow++)
		{
			std::vector<int> row;
			for (int iCol=0; iCol<nCols;iCol++)
			{
				infile>>c;				
				row.push_back(c);			
			}
			input.push_back(row);
		}
		cases.push_back(input);
	}	

	FILE * pFile;
    pFile = fopen ("out.txt","w+");

	for (int i=0; i<numCases; i++)
	{			
		input = cases[i];	
		bool bValid = true;

		for (int iRow=0; iRow<input.size(); iRow++)
		{
			std::vector<int> row = input[iRow];
			int max=-1;
			for (int iCol=0; iCol<row.size(); iCol++)
				if (row[iCol]>max) max = row[iCol];
			for (int iCol=0; iCol<row.size(); iCol++)
			{
				if (row[iCol]<max)
				{
					for (int iRow2=0; iRow2<input.size(); iRow2++)
					{
						if (input[iRow2][iCol]>row[iCol])
						{
							bValid = false;
							break;
						}
					}
				}
				if (!bValid) break;
			}
			if (!bValid) break;			
		}

		if (bValid)
		{
			std::vector<int> col;
			for (int iCol = 0; iCol<input[0].size(); iCol++)
			{
				col.clear();
				int max=-1;
				for (int iRow=0; iRow<input.size(); iRow++)
				{
					col.push_back(input[iRow][iCol]);
					if (max<input[iRow][iCol]) max = input[iRow][iCol];
				}
				for (int iRow=0; iRow<input.size(); iRow++)
				{
					if (col[iRow]<max)
					{
						for (int iCol2=0; iCol2<input[0].size(); iCol2++)
						{
							if (input[iRow][iCol2]>col[iRow])
							{
								bValid = false;
								break;
							}
						}
					}
					if (!bValid) break;
				}
				if (!bValid) break;
			}
		}

		{
			char* strScore = (bValid) ? "YES" : "NO";
			
			fprintf (pFile, "Case #%d: ",i+1);
			fprintf (pFile, strScore);
			fprintf (pFile, "\n");
		}		
	}
	fclose (pFile);
	
	return 0;
}

