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
	ifstream ifs("C:/yoshiko/programming/gcj/2014/1c/A/A/A-large.in");
	ofstream ofs("C:/yoshiko/programming/gcj/2014/1c/A/A/A-large.out");
	string line;


	int nCases = 0;
	ifs >> nCases;

	for(int i=0; i<nCases; ++i)
	{
		cout << i << endl;
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

		long long a = denominator;
		long long b = numerator;
		while(a > 0 && b > 0)
		{
			long long larger = max(a, b);
			long long smaller = min(a, b);
			a = smaller;
			b = larger % smaller;
		}

		if(a == 0)
		{
			denominator /= b;
			numerator /= b;
		}
		else
		{
			denominator /= a;
			numerator /= a;
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
			long long denominator_tmp = denominator;
			while(denominator_tmp % 2 == 0)
			{
				count++;
				denominator_tmp /= 2;
				if(numerator >= denominator_tmp)
				{
					break;
				}
			}

			ofs << "Case #" << i+1 << ": " << count << endl;

		}
	}
}