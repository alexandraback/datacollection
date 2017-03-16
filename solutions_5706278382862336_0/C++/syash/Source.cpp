#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;


int main()
{
	ofstream outFile;
	ifstream inFile;
	inFile.open("input.txt");
	outFile.open("output.txt");

	int T,P,Q;
	char dummy;
	inFile >> T;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		inFile >> P >> dummy >> Q;

		int qq = Q;
		int possible = 1;
		while (qq>1)
		{
			if ((qq % 2) == 1)
			{
				if (!(((P % qq) == 0) || ((qq % P) ==0)))
				{
					possible = 0;
				}
				break;
			}
			qq=qq/2;
		}

		if (possible)
		{
			int gen = 0;
			int pp = P;
			while (pp<Q)
			{
				pp = pp*2;
				gen++;
			}

			outFile << "Case #" << caseNum+1 << ": " << gen << endl;



		}
		else
		{
			outFile << "Case #" << caseNum+1 << ": " << "impossible" << endl;
		}



	}


	inFile.close();
	outFile.close();

	return 0;
}