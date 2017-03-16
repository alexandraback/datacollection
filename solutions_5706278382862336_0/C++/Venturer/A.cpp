#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <utility>
#include <math.h>

using namespace std;

#define MAX_INPUT_SIZE 105

int main()
{	
	ifstream reader; ofstream writer;
	reader.open("A-small4.in"); writer.open("result.out");

	char inputBuffer[MAX_INPUT_SIZE] = {'\0'}; int noTestCases = 0;

	reader.getline(inputBuffer, MAX_INPUT_SIZE, '\n');
	noTestCases = atoi(inputBuffer);

	long num = 0, den = 0;
	for(int testNo = 1; testNo<=noTestCases; testNo++)
	{
		reader.getline(inputBuffer, MAX_INPUT_SIZE, '/');
		num = atol(inputBuffer);
		reader.getline(inputBuffer, MAX_INPUT_SIZE, '\n');
		den = atoi(inputBuffer);

		int generations = 0;
		float p1 = -1.0f, p2 = -1.0f;
		bool reached = false;
		while(den%2 == 0 && !((p1 == 0 || p1 == 1) && (p2 == 0 || p2 == 1)))
		{
			if(!reached)
				generations++;

			den /= 2;
			if(num > den){
				p1 = 1; p2 = (float)(num-den)/den;
				num = num-den;
				reached = true;
			}
			else
			{
				p1 = 0; 
				p2 = (float)num/den;
			}
		}

		if(den%2 != 0 && !((p1 == 0 || p1 == 1) && (p2 == 0 || p2 == 1)))
			generations = -1;

		string outputString;
		char resultValue[20] = {'\0'};
		outputString.append("Case #");
		itoa(testNo, resultValue,10);
		outputString.append(resultValue);
		outputString.append(": ");

		// Result String
		memset(resultValue, '\0', 20);
		if(generations != -1) {
			sprintf(resultValue, "%d", generations);
			outputString.append(resultValue);
		}
		else
			outputString.append("impossible");

		outputString.append("\n");
		writer.write(outputString.c_str(), outputString.length());
	}

	reader.close();
	writer.close();

	return 1;
}
