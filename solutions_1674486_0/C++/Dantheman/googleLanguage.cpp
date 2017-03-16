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

typedef struct classStruct {
	int numInherit, numTimes, index;
	bool visited;
	struct classStruct **inheritArray;
}classStruct;

void doTree(classStruct *start, classStruct *classPtr, int numClass);
void resetTree(classStruct *classPtr, int numClass);

int main(int argc, char* argv[])
{
	/*if(argc < 2)
	{
		cout << "Not enough arguments." << endl;
		return 1;
	}*/

	ifstream fin;
	fin.open("inputfile.txt");

	ofstream fout;
	fout.open("Output.txt");

	if(!fin.is_open())
	{
		cout << "File open failed." << endl;
	}

	int numCases = 0, i, j;

	fin >> numCases;

	cout << numCases << endl;

	int numClasses, tempVal, k;

	classStruct *classPtr;

	bool diamond;

	for(i = 0; i < numCases; i++)
	{
		fout << "Case #" << i+1 << ": ";
		cout << "Case #" << i+1 << ": ";

		fin >> numClasses;
		//cout << numClasses << endl;

		classPtr = new classStruct[numClasses];

		for(j = 0; j < numClasses; j++)
		{
			fin >> classPtr[j].numInherit;
			//cout << classPtr[j].numInherit << endl;
			classPtr[j].inheritArray = new classStruct*[classPtr[j].numInherit];
			classPtr[j].visited = false;
			classPtr[j].numTimes = 0;
			classPtr[j].index = j;
			for(k = 0; k < classPtr[j].numInherit; k++ )
			{
				fin >> tempVal;
				//cout << tempVal << endl;
				classPtr[j].inheritArray[k] = classPtr + tempVal-1;
			}
		}

		diamond = false;
		for(j = 0; j < numClasses; j++)
		{
			doTree(&classPtr[j], classPtr, numClasses);
			for(k = 0; k < numClasses; k++)
			{
				if(classPtr[k].numTimes > 1)
				{
					//cout << "YES" << endl;
					diamond = true;
				}
				classPtr[k].numTimes = 0;
			}
		}

		if(diamond)
		{
			fout << "Yes" << endl;
		}
		else
		{
			fout << "No" << endl;
		}

		//fout.setf(ios::fixed,ios::floatfield);
		//fout.precision(7);


		//backspace all the way
		//fout << endl;

		delete[] classPtr;
	}
}


void doTree(classStruct *start, classStruct *classPtr, int numClass)
{
	int i;
	/*if(start->visited)
	{
		return;
	}*/

	cout << "Node: " << start->index << endl;

	start->numTimes++;
	start->visited = true;

	for(i = 0; i < start->numInherit; i++)
	{
		//resetTree(classPtr, numClass);
		doTree(start->inheritArray[i], classPtr, numClass);
	}

}

void resetTree(classStruct *classPtr, int numClass)
{
	int i;

	for(i = 0; i < numClass; i++)
	{
		classPtr[i].visited = false;
	}
}

