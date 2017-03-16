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
	std::vector<std::vector<char>> input;
	std::vector<std::vector<std::vector<char>>> cases;
	std::vector<bool> bHasDotes;
	char *inname = "C:/Test/Debug/A-small.in";
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
		bool bDot = false;
		char c;
		for (int iRow=0; iRow<4; iRow++)
		{
			std::vector<char> colon;
			for (int iCol=0; iCol<4;iCol++)
			{
				infile>>c;
				if (c=='.') bDot = true;
				colon.push_back(c);			
			}
			input.push_back(colon);
		}
		bHasDotes.push_back(bDot);		
		cases.push_back(input);
	}	

	FILE * pFile;
    pFile = fopen ("out.txt","w+");

	for (int i=0; i<numCases; i++)
	{			
		input = cases[i];	
		int score = -1;
		
		for (int iRow=0; iRow<4;iRow++)
		{
			if (((input[iRow][0]=='X')||(input[iRow][0]=='T')) && ((input[iRow][1]=='X')||(input[iRow][1]=='T')) && ((input[iRow][2]=='X')||(input[iRow][2]=='T')) && ((input[iRow][3]=='X')||(input[iRow][3]=='T')))
			{
				score = 0;
				break;
			}
			if (((input[iRow][0]=='O')||(input[iRow][0]=='T')) && ((input[iRow][1]=='O')||(input[iRow][1]=='T')) && ((input[iRow][2]=='O')||(input[iRow][2]=='T')) && ((input[iRow][3]=='O')||(input[iRow][3]=='T')))
			{
				score = 1;
				break;
			}
		}

		if (score==-1)
		{
			for (int iCol=0; iCol<4;iCol++)
			{
				if (((input[0][iCol]=='X')||(input[0][iCol]=='T')) && ((input[1][iCol]=='X')||(input[1][iCol]=='T')) && ((input[2][iCol]=='X')||(input[2][iCol]=='T')) && ((input[3][iCol]=='X')||(input[3][iCol]=='T')))
				{
					score = 0;
					break;
				}
				if (((input[0][iCol]=='O')||(input[0][iCol]=='T')) && ((input[1][iCol]=='O')||(input[1][iCol]=='T')) && ((input[2][iCol]=='O')||(input[2][iCol]=='T')) && ((input[3][iCol]=='O')||(input[3][iCol]=='T')))
				{
					score = 1;
					break;
				}
			}
		}

		if (score==-1)
		{
			if (((input[0][0]=='X')||(input[0][0]=='T')) && ((input[1][1]=='X')||(input[1][1]=='T')) && ((input[2][2]=='X')||(input[2][2]=='T')) && ((input[3][3]=='X')||(input[3][3]=='T')))
				score = 0;
			else if (((input[0][0]=='O')||(input[0][0]=='T')) && ((input[1][1]=='O')||(input[1][1]=='T')) && ((input[2][2]=='O')||(input[2][2]=='T')) && ((input[3][3]=='O')||(input[3][3]=='T')))
				score = 1;
			else if (((input[0][3]=='X')||(input[0][3]=='T')) && ((input[1][2]=='X')||(input[1][2]=='T')) && ((input[2][1]=='X')||(input[2][1]=='T')) && ((input[3][0]=='X')||(input[3][0]=='T')))
				score = 0;
			else if (((input[0][3]=='O')||(input[0][3]=='T')) && ((input[1][2]=='O')||(input[1][2]=='T')) && ((input[2][1]=='O')||(input[2][1]=='T')) && ((input[3][0]=='O')||(input[3][0]=='T')))
				score = 1;
		}
		

		{
			char* strScore;
			if (score == 0)
				strScore = "X won";
			else if (score == 1)
				strScore = "O won";
			else
			{
				if (bHasDotes[i])
					strScore = "Game has not completed";
				else
					strScore = "Draw";
			}
			
			fprintf (pFile, "Case #%d: ",i+1);
			fprintf (pFile, strScore);
			fprintf (pFile, "\n");
		}		
	}
	fclose (pFile);
	
	return 0;
}

