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
		// Solving area
		
		char* string = new char[100];
		
		scanf("%s", string);
		int n = 0;
		while (string[n] != '\0') ++n;
		std::reverse(string, string + n);
		
		int count = string[0] == '+' ? 0 : 1;
		for (int i = 1; string[i] != '\0'; ++i)
		{
			if (string[i] != string[i-1]) ++count;
		}
		
		// End Solving area
		
		printf("Case #%d: %d\n", iCase, count); // Case number
		
		delete[] string;
		
	}
	
	return 0;
}

