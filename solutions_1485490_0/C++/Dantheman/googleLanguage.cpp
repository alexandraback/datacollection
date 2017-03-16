/*
 * googleLanguage.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: Danny
 */

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct boxStyle {
	long long numBoxes, boxType;
}boxStyle;

//void doTree(classStruct *start, classStruct *classPtr, int numClass);
//void resetTree(classStruct *classPtr, int numClass);
void doBoxes(boxStyle *rowA, boxStyle *rowB, int numRowA, int numRowB, int rowAIteration, int rowBIteration, long long rowAOffset, long long rowBOffset, long long numSuccess);


long long maxCombo;

int main(int argc, char* argv[])
{
	/*if(argc < 2)
	{
		cout << "Not enough arguments." << endl;
		return 1;
	}*/

	ifstream fin;
	fin.open("inputfile7.txt");

	ofstream fout;
	fout.open("Output7.txt");

	if(!fin.is_open())
	{
		cout << "File open failed." << endl;
	}

	int numCases = 0, i, j;

	fin >> numCases;

	cout << numCases << endl;

	long long numRowA, numRowB, numBoxesA = 0, numBoxesB = 0;

	boxStyle *rowA, *rowB;


	for(i = 0; i < numCases; i++)
	{
		fout << "Case #" << i+1 << ": ";
		cout << "Case #" << i+1 << ": " << endl;

		fin >> numRowA;
		fin >> numRowB;

		rowA = new boxStyle[numRowA];
		rowB = new boxStyle[numRowB];

		for(j = 0; j < numRowA; j++)
		{
			fin >> rowA[j].numBoxes;
			fin >> rowA[j].boxType;
			numBoxesA += rowA[j].numBoxes;
		}

		for(j = 0; j < numRowB; j++)
		{
			fin >> rowB[j].numBoxes;
			fin >> rowB[j].boxType;
			numBoxesB += rowB[j].numBoxes;
		}

		//cout << "A: " << numBoxesA << " B: " << numBoxesB << endl;

		maxCombo = 0;
		doBoxes(rowA, rowB, numRowA, numRowB, 0, 0, 0, 0, 0);

		cout << maxCombo << endl;
		fout << maxCombo << endl;
		//fout.setf(ios::fixed,ios::floatfield);
		//fout.precision(7);


		//backspace all the way
		//fout << endl;

		delete[] rowA;
		delete[] rowB;
	}
}



void doBoxes(boxStyle *rowA, boxStyle *rowB, int numRowA, int numRowB, int rowAIteration, int rowBIteration, long long rowAOffset, long long rowBOffset, long long numSuccess)
{
	if(rowAIteration >= numRowA || rowBIteration >= numRowB)
	{
		if(numSuccess > maxCombo)
		{
			maxCombo = numSuccess;
		}
		return;
	}

	//cout << "ITA: " << rowAIteration << " ItB: " << rowBIteration << endl;
	if(rowA[rowAIteration].boxType == rowB[rowBIteration].boxType)
	{
		if(rowA[rowAIteration].numBoxes - rowAOffset > rowB[rowBIteration].numBoxes - rowBOffset)
		{
			//cout << "Adding B to success: " << rowB[rowBIteration].numBoxes - rowBOffset << " of type " << rowB[rowBIteration].boxType << " Offset: " << rowBOffset << " Current: " << numSuccess <<  endl;
			numSuccess += rowB[rowBIteration].numBoxes - rowBOffset;
			doBoxes(rowA, rowB, numRowA, numRowB, rowAIteration, rowBIteration+1, rowB[rowBIteration].numBoxes-rowBOffset+ rowAOffset, 0, numSuccess);
		}
		else
		{
			//cout << "Adding A to success: " << rowA[rowAIteration].numBoxes - rowAOffset << " of type " << rowA[rowAIteration].boxType << " Offset: " << rowAOffset << " Current: " << numSuccess << endl;
			numSuccess += rowA[rowAIteration].numBoxes - rowAOffset;
			doBoxes(rowA, rowB, numRowA, numRowB, rowAIteration+1, rowBIteration, 0, rowA[rowAIteration].numBoxes-rowAOffset + rowBOffset, numSuccess);
		}
	}
	else
	{
		doBoxes(rowA, rowB, numRowA, numRowB, rowAIteration, rowBIteration+1, rowAOffset, 0, numSuccess);
		doBoxes(rowA, rowB, numRowA, numRowB, rowAIteration+1, rowBIteration, 0, rowBOffset, numSuccess);
	}
}
