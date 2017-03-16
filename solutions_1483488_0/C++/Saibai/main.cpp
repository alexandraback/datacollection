//
//  main.cpp
//  Recycled Numbers
//
//  Created by Sebastian Grail on 14/04/12.
//  Copyright (c) 2012 Sebastian Grail. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int countPermutations(int number, int max);
vector<int>& getNumbersFromLine(ifstream& inputStream);

vector<int>& getNumbersFromLine(ifstream& inputStream)
{
	vector<int>* result = new vector<int>;
	
	string line;
	getline(inputStream,line);
	int startPos = 0;
	int endPos = (int)line.find(" ", startPos);
	
	while (startPos >= 0 )
	{
		int element = atoi(line.substr(startPos, endPos-startPos).c_str());
		result->push_back(element);
		if (endPos < 0)
			break;
		startPos=endPos+1;
		endPos = (int)line.find(" ", startPos);
	}	
	return *result;
}


int countPermutations(int number, int max)
{
	int numberOfDigits = ceil(log10(number+1));	
	set<int> permutations;
	
	for (int i=1; i<numberOfDigits; i++)
	{
		int currentPermutation = number/(int)pow(10,i) + (number%(int)pow(10,i))*(int)pow(10,numberOfDigits-i);
		if (currentPermutation > number && currentPermutation <= max)
		{
			permutations.insert(currentPermutation);
		}
	}
	return (int)permutations.size();	
}

int main (int argc, const char * argv[])
{
	ifstream input;
	ofstream output;
	
	string line;
	
	input.open("/Users/sgrail/Desktop/C-small-attempt1.in.txt");
	output.open("/Users/sgrail/Desktop/results.txt");
	
	getline(input,line);
	int numberOfTestCases = atoi(line.c_str());
	
	for (int i=0; i<numberOfTestCases; i++)
	{
		vector<int> numbers = getNumbersFromLine(input);
		
		int min = numbers.at(0);
		int max = numbers.at(1);
		
		int numberOfPairs = 0;
		for (int i=min; i<=max; i++)
		{
			numberOfPairs += countPermutations(i, max);
		}
		output << "Case #" << i+1 << ": " << numberOfPairs << endl;
	}
	
	input.close();
	output.close();
	
	return 0;
}

