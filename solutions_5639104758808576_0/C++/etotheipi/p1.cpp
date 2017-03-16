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
		
		int S_max;
		fin >> S_max;
		
		int y = 0;
		int sum = 0;
		for (int i=0; i<=S_max; i++)
		{
			char c;
			fin >> c;
			sum += 1-int(c - '0');
			if (sum>y) y=sum;
		}
		
		fout << y << endl;
	}
 
    return 0;
}