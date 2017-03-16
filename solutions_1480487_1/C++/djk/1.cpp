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

int main()
{
	ifstream input;
	input.open("input.in");
	
	unsigned int count = 0;
	
	vector< vector<double> > results;
	
	input >> count;
	
	results.reserve(count);
	
	for (unsigned int x = 0; x < count; ++x)
	{
		unsigned int num = 0;
		
		input >> num;
		
		unsigned int
			total = 0,
			exempt = 0;
		vector<unsigned int> scores;
		
		scores.reserve(num);
		
		for (unsigned int y = 0; y < num; ++y)
		{
			unsigned int temp = 0;
			input >> temp;
			total += temp;
			scores.push_back(temp);
		}
		
		unsigned int max = total * 2;
		
		double average = (double)max / (double)num;
		
		for (unsigned int y = 0; y < num; ++y)
		{
			if ((double)scores[y] > average)
			{
				++exempt;
				max -= scores[y];
			}
		}
		
		average = (double)max / (double)(num - exempt);
		
		vector<double> percents;
		
		percents.reserve(num);
		
		for (unsigned int y = 0; y < num; ++y)
			percents.push_back(MAX((average - (double)scores[y]) / (double)total, 0.0));
		
		results.push_back(percents);
	}
	
	input.close();
	
	ofstream output;
	output.open("output.out");
	
	for (unsigned int x = 0; x < count; ++x)
	{
		output << "Case #" << x + 1 << ": ";
		for (unsigned int y = 0; y < results[x].size(); ++y)
			output << results[x][y] * 100.0 << " ";
		output << endl;
	}
	
	output.close();
	
	return 0;
}
