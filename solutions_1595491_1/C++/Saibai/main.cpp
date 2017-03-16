//
//  main.cpp
//  Dancing with the Googlers
//
//  Created by Sebastian Grail on 14/04/12.
//  Copyright (c) 2012 Sebastian Grail. All rights reserved.
//


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int min(int a, int b);
int maxSpecialCase(int number);
int maxNormalCase(int number);
vector<int>& getNumbersFromLine(ifstream& inputStream);

int min(int a, int b)
{
	return a<b ? a : b;
}

int maxNormalCase(int number)
{
	return number/3 + (number%3!=0);
}

int maxSpecialCase(int number)
{
	return number/3 +1 + (number%3==2);
}

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


int main (int argc, const char * argv[])
{
	ifstream input;
	ofstream output;
	
	string line;
	
	input.open("/Users/sgrail/Desktop/B-large.in.txt");
	output.open("/Users/sgrail/Desktop/results.txt");
	
	getline(input,line);
	int numberOfTestCases = atoi(line.c_str());
	
	
	for (int i=0; i<numberOfTestCases; i++)
	{
		vector<int> numbers = getNumbersFromLine(input);
		
		//int N = numbers.at(0);
		int S = numbers.at(1);
		int p = numbers.at(2);
		
		int result = 0;
		int inSpecialCase = 0;
		
		for (int i=3; i<numbers.size(); i++)
		{
			int currentScore = numbers[i];
			if (maxNormalCase(currentScore) >= p)
				result++;
			else if (currentScore > 1 && currentScore < 29)
				if (maxSpecialCase(currentScore) >= p)
					inSpecialCase++;
		}
		result += min(inSpecialCase, S);
		output << "Case #" << i+1 << ": " << result << endl;
	}
	
	
	input.close();
	output.close();
	
    return 0;
}

