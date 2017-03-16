#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{ 
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int numCases;
	fin >> numCases;
	
	for (int caseNumber=1; caseNumber<=numCases; caseNumber++)
	{
		fout << "Case #" << caseNumber << ": ";
		
		int D;
		fin >> D;
		
		int P[1000];
		int maxP = 0;
		for (int i=0; i<D; i++)
		{
			fin >> P[i];
			if (maxP < P[i]) maxP = P[i];
		}
		
		int minMinutes = maxP;
		for (int threshhold = 1; threshhold<=maxP; threshhold++)
		{
			int minutes = threshhold;
			for (int i=0; i<D; i++)
				minutes += (P[i]-1)/threshhold;
			if (minMinutes > minutes)
				minMinutes = minutes;
		}
		
		fout << minMinutes << endl;
	}
 
    return 0;
}