#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

string problemFile = "C-small-attempt0";

//Globals
fstream input;
fstream output;
int CaseNum; //track what case # we are up to

//Declarations
void SolveInstance();

template <class T>
void LoadVector(vector<T>& v, int n) 
{
	int i, x;
	for (i = 0; i < n; ++i)
	{
		input >> x;
		v.push_back(x);
	}
}


int main()
{
	input.open(problemFile+".in", ios::in);
	output.open(problemFile+".out", ios::out);

	int T;
	input >> T;
	for (CaseNum = 1; CaseNum <= T; ++CaseNum)
	{
		SolveInstance();
	}

	return 0;
}

bool IsPalindrome(long long x);

void SolveInstance()
{
	long long A,B;
	input >> A >> B;

	long result = 0;

	for (long long i = (long long)ceil(sqrt(A)); i <= (long long)sqrt(B); ++i)
	{
		if(IsPalindrome(i) && IsPalindrome(i*i))
		{
			//output << i << "," << i*i << endl;
			result++;
		}
	}


	output << "Case #" << CaseNum << ": " << result << endl;
}


bool IsPalindrome(long long x)
{
	char buf[102];
	sprintf(buf, "%lli", x);

	int length;
	for (int i = 0; i < sizeof(buf); ++i)
	{
		if (buf[i] == '\0')
			length = i;
	}

	//Check palindromeness
	for (int i = 0; i < (length+1)/2; ++i)
	{
		if (buf[i] != buf[length - 1 - i])
			return false;
	}

	return true;
}