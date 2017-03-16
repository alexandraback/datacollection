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

long solveNth(long n, int digits)
{
	if (digits == 1) return n;

	long power = 1;
	for (int i=0; 2*i<digits; i++)
		power *= 10;
		
	long after = long((n-1) / power) * power + 1;
	long before = reverse(after);
	
	power = 1;
	for (int i=1; i<digits; i++)
		power *= 10;
		
	if (n == power) return 1;
	
	long answer = (before - power) + (n-after) + 2;
	
	if (answer < n - power) return answer;
	else return n - power + 1;
}

long solve(long n)
{
	long power = 10;
	long answer = 0;
	int digits = 1;
	
	while(n >= power)
	{
		answer += solveNth(power-1, digits);
		power *= 10;
		digits++;
	}
	return answer + solveNth(n, digits);
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
		
		long N;
		fin >> N;
		
		fout << solve(N) << endl;
	}
 
    return 0;
}