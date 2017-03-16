#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

#include <cstdlib>
#include <cstring>

unsigned int numDigits(unsigned int n)
{
	unsigned int
		b = 1,
		x = 0;
	for (; b <= n; b *= 10, ++x)
	{ }
	return x;
}

unsigned int digit(unsigned int n, unsigned int p)
{
	return (n / (unsigned int)pow(10, p)) % 10;
}

unsigned int recycle(unsigned int n, unsigned int d, unsigned int c)
{
	unsigned int l = pow(10, c);
	return n / l + (n % l) * (unsigned int)pow(10, d - c);
}

int main()
{
	ifstream input;
	input.open("input.in");
	
	unsigned int count = 0;
	vector<unsigned long long> results;
	
	input >> count;
	
	results.reserve(count);
	
	for (unsigned int x = 0; x < count; ++x)
	{
		unsigned int
			lower = 0,
			upper = 0;
		
		input >> lower >> upper;
		
		unsigned long long count = 0;
		
		unsigned int masksize = upper - lower + 1;
		char mask[masksize];
		memset(mask, 0, masksize);
		
		for (unsigned int y = lower, i = 0; y <= upper; ++y, ++i)
		{
			if (mask[i])
				continue;
			
			unsigned int
				n = numDigits(y),
				o = 0,
				found = 0;
			
			for (unsigned int z = 1; z < n; ++z)
			{
				o = recycle(y, n, z);
				
				if (o >= lower && o <= upper && o != y)
				{
					if (!mask[o - lower])
					{
						mask[o - lower] = 1;
						++found;
					}
				}
			}
			
			if (found)
				count += (found + 1) * found / 2;
		}
		
		results.push_back(count);
	}
	
	input.close();
	
	ofstream output;
	output.open("output.out");
	
	for (unsigned int x = 0; x < results.size(); ++x)
		output << "Case #" << (x + 1) << ": " << results[x] << endl;
}
