#include <fstream>
#include <iostream>
#include <string>

using namespace std;

long reverse(long n)
{
	long out = 0;
	while(n > 0)
	{
		out *= 10;
		out += n%10;
		n = long(n/10);
	}
	return out;
}

long numSteps[1000001];

void precompute()
{
	numSteps[1] = 1;
	
	for (long n=2; n<=1000000; n++)
	{
		numSteps[n] = numSteps[n-1]+1;
	
		long r = reverse(n);
		if (reverse(r) == n && r<n && numSteps[r] < numSteps[n-1]) 
			numSteps[n] = numSteps[r]+1;
	}
}

int main()
{ 
	precompute();

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int numCases;
	fin >> numCases;
	
	for (int caseNumber=1; caseNumber<=numCases; caseNumber++)
	{
		fout << "Case #" << caseNumber << ": ";
		
		long N;
		fin >> N;
		
		fout << numSteps[N] << endl;
	}
 
    return 0;
}