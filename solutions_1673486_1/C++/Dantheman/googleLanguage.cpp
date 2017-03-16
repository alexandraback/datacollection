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

	float *percentArray, *probArray;
	int numTyped, passwordLength;

	float temp;
	float minExpectation, expectation;
	fin >> numCases;

	cout << numCases << endl;

	int keysCorrect, keysWrong;

	for(i = 0; i < numCases; i++)
	{
		fin >> numTyped;
		fin >> passwordLength;
		fout << "Case #" << i+1 << ": ";

		percentArray = new float[numTyped];
		probArray = new float[numTyped];

		for(j = 0; j < numTyped; j++)
		{
			fin >> percentArray[j];
		}

		temp = 1;
		for(j = 0; j < numTyped; j++)
		{
			temp*= percentArray[j];
			probArray[j] = temp;
			cout << probArray[j] << " ";
		}

		//if the number typed is zero then dont consider the single backspace

		//enter now
		minExpectation = 2 + passwordLength;

		cout << keysCorrect << " " << keysWrong << endl;
		cout << "Expec: " << minExpectation << endl;

		//figure out probability that all before are correct
		for(j = 0; j < numTyped; j++)
		{
			//j+1 is the number of backspaces I will do
			//expectation is probability all before are correct * number of keystrokes +
			//probability not all correct * number of keystrokes
			keysCorrect = j + (passwordLength - (numTyped-j)) + 1;
			keysWrong = keysCorrect + passwordLength + 1;
			expectation = keysCorrect * probArray[numTyped-j-1] + keysWrong * (1-probArray[numTyped-j-1]);
			cout << "Expec: " << expectation << endl;
			if(expectation < minExpectation)
			{
				minExpectation = expectation;
			}
			cout << keysCorrect << " " << keysWrong << endl;
		}

		//backspace all the way
		expectation = numTyped + passwordLength + 1;

		if(expectation < minExpectation)
		{
			minExpectation = expectation;
		}
		cout << "Answer: " << minExpectation << endl;

		fout.setf(ios::fixed,ios::floatfield);
		fout.precision(6);
		fout << minExpectation;
		fout << endl;

		delete[] percentArray;
	}
}



