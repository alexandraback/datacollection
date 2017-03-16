#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool gabWins(int X, int R, int C)
{
	switch(X)
	{
		case 1: return true;
		case 2: return (R*C) % 2 == 0;
		case 3: return (R*C) % 3 == 0 && R*C != 3;
		case 4: return (R*C) % 4 == 0 && R>2 && C>2;
		
		case 5: 
		// minimal cases are 5*4, 10*3. W ruins 5*3, surprisingly
		if (R%5 == 0)
		{
			if (R == 5) return C>=4;
			else return C>=3;
		}
		else if (C%5 == 0)
		{
			if (C == 5) return R>=4;
			else return R>=3;
		}
		return false;
		
		case 6: 
		// hard case. Solve later
		return false;
		
		default: return false;
	}
}

int main()
{ 
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int numCases;
	fin >> numCases;
	
	for (int caseNumber=1; caseNumber<=numCases; caseNumber++)
	{
		fout << "Case #" << caseNumber << ": ";
		
		int X, R, C;
		fin >> X >> R >> C;
		
		fout << (gabWins(X, R, C)?"GABRIEL":"RICHARD") << endl;
	}
 
    return 0;
}