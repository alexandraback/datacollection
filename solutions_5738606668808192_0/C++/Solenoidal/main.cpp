/* 
 * File:   main.cpp
 * Author: henryw
 *
 * Created on April 4, 2016, 5:58 PM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <cmath>

bool testNumber(std::string number)
{
	std::vector<long long> factors;
	
	for (int base = 2; base <= 10; ++base)
	{
		// Primality test
		long long num = stoll(number, nullptr, base);
		
		if (num <= 1 || num == 2) return false;
	
		for (long long i = 3; i <= sqrtl(num); i += 2)
		{
			if (num % i == 0)
			{
				factors.push_back(i);
				goto nextBase;
			}
		}
		return false;
nextBase:;
	}
	
	printf("%s", number.c_str());
	for (auto&& factor : factors)
	{
		printf("% lld", factor);
	}
	printf("\n");
	return true;
}

int main(int argc, char* argv[])
{
	using namespace std;
	int nCases;
	
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	scanf( "%d\n", &nCases );
	
	for (int iCase = 1; iCase <= nCases; ++iCase)
	{
		int length;
		int count;
		scanf("%d", &length);
		scanf("%d", &count);
		length -= 2;
		
		printf("Case #%d:\n", iCase); // Case number
		
		long long current = 0;
		int i = 0;
		
		while (i < count)
		{
			std::string number = "1";
			for (int j = 0; j < length; ++j)
			{
				number += (current >> j) & 1 ? "1" : "0";
			}
			number += "1";
			
			if (testNumber(number)) ++i;
			++current;
		}
	}
	
	return 0;
}

