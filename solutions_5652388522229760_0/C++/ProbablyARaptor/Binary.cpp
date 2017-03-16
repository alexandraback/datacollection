#include <iostream>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <cmath>

#include "Binary.h"

std::string GetBinary(int val, int pad)
{
	std::stringstream oss;
	while(val/2 != 0) 
	{
		oss << val % 2;
		val/=2;
	}
	oss << val % 2;
	
	while(oss.tellp() < pad)
	{
		oss << 0;
	}
	
	auto solution = oss.str();
	reverse(solution.begin(), solution.end());
	return solution;
}

std::vector<std::string> GetOptions(int bits)
{
	std::vector<std::string> solution;
	if(bits == 0)
	{
		return solution;
	}
	
	std::string state;
	for(int i = 0; i < bits; ++i)
	{
		state += '0';
	}
	auto firstIndex = state.length() - 1;
	auto zeroState = state;	
	solution.push_back(state);
	state[firstIndex] = '1';
		
	while(state != zeroState)
	{
		solution.push_back(state);
		state[firstIndex] = state[firstIndex] == '1' ? '2' : '1';	
		
		for(int i = firstIndex; i > -1; --i)
		{
			int finished = 0;
			switch(state[i])
			{
				case '2':
					state[i] = '0';
					if(i-1 > -1)
					{
						state[i-1] = state[i-1] == '1' ? '2' : '1';					
					}
					break;
				default:					
					finished = 1;
					break;
			}
			if(finished == 1)
			{
				break;
			}
		}		
	}
	return solution;
}