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

typedef struct level {
  bool easy;
  bool hard;
  int easyScore;
  int hardScore;
} level;

void orderArray(level *array, int size);
void printArray(level *array, int size);

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

	int numLevels, numStars = 0;

	bool compete;
	level *levelArray;

	fin >> numCases;

	cout << numCases << endl;

	int numComplete = 0, numTries;

	for(i = 0; i < numCases; i++)
	{
		fin >> numLevels;
		fout << "Case #" << i+1 << ": ";
		cout << "Case #" << i+1 << ": " << endl;

		numTries = 0;
		numComplete= 0;
		numStars = 0;
		levelArray = new level[numLevels];

		for(j = 0; j < numLevels; j++)
		{
			fin >> levelArray[j].easyScore;
			fin >> levelArray[j].hardScore;
			levelArray[j].easy = false;
			levelArray[j].hard = false;
		}

		printArray(levelArray, numLevels);
		orderArray(levelArray, numLevels);
		printArray(levelArray, numLevels);

		compete = true;
		while(compete)
		{
			//numTries++;
			compete = false;

			for(j = 0; j < numLevels; j++)
			{
				if(levelArray[j].hard)
				{
					continue;
				}

				cout << "Checking level " << j << " hard " << endl;
				if(levelArray[j].hardScore <= numStars)
				{
					cout << "Level :" << j << " Hard Stars: " << levelArray[j].hardScore << " NUMStars: " << numStars << endl;
					if(levelArray[j].easy)
					{
						numStars+=1;
					}
					else
					{
						numStars+= 2;
					}
					numComplete++;
					numTries++;
					levelArray[j].hard = true;
					levelArray[j].easy = true;
					compete = true;
					break;
				}
			}

			if(compete)
			{
				continue;
			}

			for(j = 0; j < numLevels; j++)
			{
				if(levelArray[j].easy)
				{
					continue;
				}

				cout << "Checking level " << j << " easy " << endl;

				if(levelArray[j].easyScore <= numStars)
				{

					cout << "Level :" << j << " Easy Stars: " << levelArray[j].easyScore << " NUMStars: " << numStars << endl;
					numTries++;
					numStars+= 1;
					levelArray[j].easy = true;
					compete = true;
					break;
				}
			}

		}

		if(numComplete == numLevels)
		{
			fout << numTries;
		}
		else
		{
			fout << "Too Bad";
		}

		fout << endl;

		delete[] levelArray;
	}
}


void orderArray(level *array, int size)
{
	int i;
	level temp;

	bool swap = true;
	while(swap)
	{
		swap = false;
		for(i = 0; i < size-1; i++)
		{
			if(array[i].hardScore < array[i+1].hardScore)
			{
				swap = true;
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
	}
}

void printArray(level *array, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		cout << array[i].easyScore << " " << array[i].hardScore << endl;
	}
}
