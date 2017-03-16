//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int getMod (const string & s, int base, int divisor)
{
	int res = 0;

		for (size_t i = 0; i < s.size(); ++i)
			res *= base, res += s[i]-'0', res %= divisor;

		return res;
}

bool isPrime(const string & s, int base, int & div)
{
	for (int i = 2; i <= 10000; ++i)
		if(getMod(s, base, i) == 0)
		{
			div = i;
			return false;
		}
	div = 0;
	return true;
}

int getFromBase(const string & s, int base)
{
	int res = 0;

	for (size_t i = 0; i < s.size(); ++i)
		res *= base, res += s[i]-'0';

	return res;
}

int main()
{
	// open a file in read mode.
	ifstream infile;
//	infile.open("src/in");
	infile.open("src/C-small-attempt0.in");
//	infile.open("src/B-large.in");

	// open a file in write mode.
	ofstream outfile;
	outfile.open("src/out");

	int T;
	infile>>T;
	for (int i = 1; i <= T; ++i)
	{
		int N,J;
		infile>>N>>J;
		int maxCount = pow(2,N-2);


		outfile<<"Case #"<<i<<":"<<endl;

		for (int k = 0; J && k < maxCount; ++k)
		{
			string s = string(N, '1');
			int k_ = k;
			for(int j = N-2; j>0; --j)
			{
				s[j] = '0'+k_%2;
				k_/=2;
			}

			vector<int>div(11,0);
			bool prime = false;
			for (int h = 2; h <= 10 && !prime; ++h)
			{
                prime = isPrime(s, h, div[h]);
			}
			if(!prime)
			{
				--J;
				outfile<<s;
				for (int h = 2; h <= 10; ++h)
					outfile<<" "<<div[h];
				outfile<<endl;
			}
		}
	}
	return 0;
}
