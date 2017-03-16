#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <map>
#include <sstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream ifs("C:/yoshiko/programming/gcj/2014/1c/A/A/A-small-attempt0.in");
	ofstream ofs("C:/yoshiko/programming/gcj/2014/1c/A/A/A-small-attempt0.out");
	string line;


	int nCases = 0;
	ifs >> nCases;

	for(int i=0; i<nCases; ++i)
	{
		string input;
		ifs >> input;

		long long numerator = 0;
		long long denominator = 0;
		int index = input.find('/');
		if(index != string::npos)
		{
			string sNumerator = input.substr(0, index);
			istringstream isN(sNumerator);
			isN >> numerator;
			string sDenominator = input.substr(index+1);
			istringstream isD(sDenominator);
			isD >> denominator;
		} 
		else if (input == "1")
		{
			ofs << "Case #" << i+1 << ": 0" << endl;
			continue;
		}

		if(numerator == 1 && denominator == 1)
		{
			ofs << "Case #" << i+1 << ": 0" << endl;
			continue;
		}

		for(long long j=2; j<=numerator; ++j)
		{
			while(numerator % j == 0 && denominator % j == 0)
			{
				numerator /= j;
				denominator /= j;
			}

			if(numerator == 1 || j > numerator)
			{
				break;
			}
		}

		long long denominator_tmp = denominator;
		while(denominator_tmp % 2 == 0)
		{
			denominator_tmp /= 2;
		}

		if(denominator_tmp != 1)
		{
			ofs << "Case #" << i+1 << ": impossible" << endl;
			
		}
		else
		{
			long long count = 0;
			long long denominator_tmp2 = denominator;
			while(true)
			{
				count++;
				denominator_tmp2 /= 2;
				if(numerator >= denominator_tmp2)
				{
					break;
				}
			}

			ofs << "Case #" << i+1 << ": " << count << endl;
		}
	}
}