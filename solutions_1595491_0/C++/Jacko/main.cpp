#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

int main()
{
    ifstream input;		
	input.open("C:\\codejam\\probB\\input.txt", ifstream::in);
	ofstream output;
	output.open("C:\\codejam\\probB\\output.txt");
	string currentLine;
	string outputLine;
	int numberOfGooglers, surpriseNumber, p, currentTriplet, remainingSurprises, numberOfGG; 
	int threshold1, threshold2;
	int lineNumber = 0;
	string numb;
	getline(input, numb);
	lineNumber = atoi(numb.c_str());
	for(int i = 1; i < lineNumber+1; ++i)
	{
		input >> numberOfGooglers;
		input >> surpriseNumber;
		input >> p;
		threshold1 = 3*p-2;
		threshold2 = threshold1 -2;
		remainingSurprises = surpriseNumber;
		numberOfGG = 0;
		ostringstream oss;
		oss << i;
		string result = oss.str();
		outputLine = "Case #" + result + ": ";
		for(int j = 0; j != numberOfGooglers; ++j)
		{
			input >> currentTriplet;
			if(currentTriplet >= p)
			{
				if(currentTriplet>=threshold1)
					++numberOfGG;
				else if(currentTriplet>=threshold2 && remainingSurprises>0)
				{
					++numberOfGG;
					--remainingSurprises;
				}
			}
		}
		ostringstream oss2;
		oss2 << numberOfGG;
		outputLine += oss2.str();
		output<<outputLine<<endl;
	}
	input.close();
	output.close();
    return 0;
}
