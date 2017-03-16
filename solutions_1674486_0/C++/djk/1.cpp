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

const bool browseGraph(vector<bool> &mask, const vector< vector<unsigned int> > &tos, unsigned int start)
{
	mask[start] = true;
	
	for (unsigned int x = 0; x < tos[start].size(); ++x)
	{
		if (mask[tos[start][x]])
			return true;
		else
			if (browseGraph(mask, tos, tos[start][x]))
				return true;
	}
	
	return false;
}

int main()
{
	ifstream input;
	input.open("input.in");
	
	unsigned int count = 0;
	input >> count;
	
	vector<bool> results;
	results.reserve(count);
	
	for (unsigned int x = 0; x < count; ++x)
	{
		unsigned int num = 0;
		input >> num;
		
		vector< vector<unsigned int> > tos;
		tos.resize(num);
		
		for (unsigned int y = 0; y < num; ++y)
		{
			unsigned int c = 0;
			input >> c;
			
			unsigned int temp = 0;
			
			for (unsigned int z = 0; z < c; ++z)
			{
				input >> temp;
				tos[temp - 1].push_back(y);
			}
		}
		
		bool flag = false;
		
		for (unsigned int y = 0; y < tos.size() && !flag; ++y)
		{
			vector<bool> mask;
			mask.resize(tos.size());
			
			for (unsigned int z = 0; z < mask.size(); ++z)
				mask[z] = false;
			
			if (browseGraph(mask, tos, y))
				flag = true;
		}
		
		results.push_back(flag);
	}
	
	input.close();
	
	ofstream output;
	output.open("output.out");
	
	for (unsigned int x = 0; x < results.size(); ++x)
	{
		output << "Case #" << x + 1 << ": " << ((results[x]) ? "Yes" : "No") << endl;
	}
	
	output.close();
}
