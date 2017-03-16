#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ofstream outFile;
	ifstream inFile;
	inFile.open("input.txt");
	outFile.open("output.txt");

	int T;
	double C,F,X;
	
	double timeSoFar, timeToGoal, timeWithFactory;
	int n;
	double rate;


	inFile >> T;
	outFile.precision(7);
	outFile << fixed;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		inFile >> C >> F >> X;
		rate=2;
		timeSoFar = 0;
		while(1)
		{
			timeToGoal = X/rate;
			timeWithFactory = C/rate;
			
			rate += F;
			timeWithFactory = timeWithFactory + X/rate;
			if (timeToGoal < timeWithFactory)
			{
				break;
			}

			timeSoFar += (timeWithFactory - X/rate);

		}

		outFile << "Case #" << caseNum+1 << ": " << timeToGoal+timeSoFar << endl;

	}

	return 0;
}