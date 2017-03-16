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
	unsigned int count = 0;
	vector<unsigned int> results;
	
	string temp;
	stringstream curline;
	
	ifstream input;
	input.open("input.in");
	
	input >> count;
	getline(input, temp);
	
	for (unsigned int x = 0; x < count; ++x)
	{
		unsigned int
			numscores = 0,
			surprises = 0,
			bar = 0;
		
		vector<unsigned int> scores;
		
		getline(input, temp);
		
		curline << temp;
		
		curline >> numscores >> surprises >> bar;
		
		scores.reserve(numscores);
		
		while (!curline.eof())
		{
			unsigned int t = 0;
			curline >> t;
			scores.push_back(t);
		}
		
		curline.clear();
		
		unsigned int
			guaranteed = 0,
			tentative = 0;
		
		for (unsigned int y = 0; y < scores.size(); ++y)
		{
			unsigned int
				n = scores[y] / 3,
				r = scores[y] % 3;
			
			if (scores[y] < 3)
			{
				if (scores[y] < 2)
				{
					if (scores[y] >= bar)
						++guaranteed;
				}
				else
					if (1 >= bar)
						++guaranteed;
					else
						if (2 >= bar)
							++tentative;
				
				continue;
			}
			
			switch (r)
			{
				case 0:
					if (n >= bar)
						++guaranteed;
					else
						if (n + 1 >= bar)
							++tentative;
					
					break;
				case 1:
					if (n + 1 >= bar)
						++guaranteed;
					
					break;
				case 2:
					if (n + 1 >= bar)
						++guaranteed;
					else
						if (n + 2 >= bar && tentative < surprises)
							++tentative;
					break;
				default:
					break;
			}
		}
		
		results.push_back(guaranteed + MIN(tentative, surprises));
	}
	
	input.close();
	
	ofstream output;
	output.open("output.out");
	
	for (unsigned int x = 0; x < count; ++x)
		output << "Case #" << (x + 1) << ": " << results[x] << endl;
	
	return 0;
}
