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

unsigned long long length;

unsigned long long powull(unsigned long long x, unsigned long long p)
{
	if (p == 0) return 1;
	if (p == 1) return x;

	int half = powull(x, p/2);
	if (p % 2 == 0) return half * half;
	else return x * half * half;
}
std::set<unsigned long long>
determinedIndices(unsigned long long i,
				unsigned long long complexity)
{
	if (complexity == 1) return std::set<unsigned long long>({i});
	std::set<unsigned long long> indices;
	while (complexity > 0)
	{
		indices.insert(i % length);
		i / length;
	}
	return indices;
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
		printf("Case #%d:", iCase); // Case number
		
		unsigned long long complexity, budget;
		
		scanf("%llu %llu %llu", &length, &complexity, &budget);
		
		std::vector<unsigned long long> indices;
		
		unsigned long long n;
		if (complexity >= length) n = 1;
		else n = 1 + (length - 1) / complexity;
		for (unsigned long long i = 0; i < n; ++i)
		{
			unsigned long long index = 0;
			
			for (unsigned long long j = 0; j < complexity; ++j)
			{
				if (i * complexity + j < length)
				{
					index = index * length + j + i * complexity;
				}
				else
				{
					index *= length;
				}
			}
			indices.push_back(index);
		}
		
		if (indices.size() > budget)
		{
			printf(" IMPOSSIBLE");
		}
		else
		{
		for (auto&& index : indices)
		{
			printf(" %llu", index + 1);
		}
			
		}
		printf("\n");
	}
	
	return 0;
}

