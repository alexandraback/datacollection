#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int compare (const void * a, const void * b)
{
  if ( *(double*)a > *(double*)b )
	  return 1;
  else if (*(double*)a < *(double*)b )
	 return -1;
  return 0;
}

int playWar(int N, double* arr1, double* arr2)
{
	int p1=0,p2=0;
	int wins=0;
	for (p1=0; p1<N && p2<N;p1++)
	{
		while (arr1[p1] > arr2[p2] && p2<N)
		{
			p2++;
		}
		if (p2<N)
			wins++;
		p2++;

	}
	return wins;
}

int main()
{
	ofstream outFile;
	ifstream inFile;
	inFile.open("input.txt");
	outFile.open("output.txt");

	int T;
	inFile >> T;
	int i, N;
	double *hers, *his;
	int herWins, hisWins;
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		inFile >> N;
		hers = new double[N];
		his = new double[N];
		for (i=0; i<N; i++)
			inFile >> hers[i];
		for (i=0; i<N; i++)
			inFile >> his[i];

		qsort(hers,N,sizeof(double),compare);
		qsort(his,N,sizeof(double),compare);

		herWins = playWar(N,his,hers);
		hisWins = playWar(N,hers,his);

		outFile << "Case #" << caseNum+1 << ": " << herWins << " " << N-hisWins << endl;

	}

	return 0;
}