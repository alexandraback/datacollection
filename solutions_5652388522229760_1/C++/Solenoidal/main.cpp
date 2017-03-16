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


int main(int argc, char* argv[])
{
	using namespace std;
	int nCases;
	
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	scanf( "%d\n", &nCases );
	
	for (int iCase = 1; iCase <= nCases; ++iCase)
	{
		unsigned long long number;
		scanf("%llu", &number);
		
		int i = 1;
		static std::set<int> digits10 = {0,1,2,3,4,5,6,7,8,9};
		std::set<int> digits;
		for (i = 1; i < 123456000; ++i)
		{
			unsigned long long itNumber = number * i;
			for (; itNumber > 0; itNumber/=10)
			{
				digits.insert((int)(itNumber % 10));
			}
			if (digits == digits10) break;
		}
		printf("Case #%d: ", iCase); // Case number
		if (i == 123456000)
			printf("INSOMNIA\n");
		else
			printf("%llu\n", number * i);
		/*
		 * When forking, a sequence A
		 */
		
	}
	
	return 0;
}

