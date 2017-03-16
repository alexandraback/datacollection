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
	int A,B,K;
	inFile >> T;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		int k=0;

		inFile >> A >> B >> K;
		for (int a=0; a<A; a++)
		{
			for (int b=0; b<B; b++)
			{
				if ((a&b) < K)
				{
					k++;
				}
			}
		}
		outFile << "Case #" << caseNum+1 << ": " << k << endl;




	}


	inFile.close();
	outFile.close();

	return 0;
}