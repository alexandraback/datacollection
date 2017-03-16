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
		cout << "Case #" << caseNumber << ": " << endl;
		
		int N;
		fin >> N;
		
		int numHiker = 0;
		long D[10], M[10];
		
		for (int i=0; i<N; i++)
		{
			long d, h, m;
			
			fin >> d >> h >> m;
			for (int j=0; j<h; j++)
			{
				D[numHiker] = d;
				M[numHiker] = m + j;
				
				numHiker++;
				
				cout << numHiker << ": " << D[numHiker-1] << "," << M[numHiker-1] << endl;
			}
		}
		
		int f = 0;
		for (int i=1; i<numHiker; i++)
		{
			if (M[i] < M[f])
				f = i;
			else if (M[i] == M[f] && D[i] > D[f])
				f = i;
		}
		
		int new_f = f;
		for (int i=0; i<numHiker; i++)
		{
			if (i==f) continue;
		
			if (M[f] * (720 - D[f]) >= M[i] * (720 - D[i]))
				new_f = i;
		}
		
		int count = 0;
		for (int i=0; i<numHiker; i++)
		{
			if (i==new_f) continue;
		
			if (M[new_f] * (720 - D[new_f]) <= M[i] * (360 - D[i]))
				count++;
		}
		
		fout << count << endl;
	}
 
    return 0;
}