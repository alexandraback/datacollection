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
		if ((R*C) % 6 != 0) return false;
		// minimal cases are 3*8, 4*6
		// figuring these out requires some manual work, but it's not too hard
		// if you consider the fact that all hexominos fit in 3*4 rectangle
		if (R<3 || C<3) return false;
		if (R>3 && C>3) return true;
		if (R==3) return C>=8;
		else return R>=8;
		
		// heptominos and above fail for a well known reason: we can make holes
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