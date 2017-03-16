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
	string temp;
	
	string translate ("yhesocvxduiglbkrztnwjpfmaq");
	
	ifstream input;
	input.open("input.in");
	
	input >> count;
	getline(input, temp);
	
	vector<string> lines;
	lines.reserve(count);
	
	for (unsigned int x = 0; x < count; ++x)
	{
		getline(input, temp);
		
		for (unsigned int y = 0; y < temp.size(); ++y)
		{
			if (temp[y] > 96 && temp[y] < 123)
				temp[y] = translate[temp[y] - 97];
		}
		
		lines.push_back(temp);
	}
	
	input.close();
	
	ofstream output;
	output.open("output.out");
	
	for (unsigned int x = 0; x < lines.size(); ++x)
	{
		output << "Case #" << (x + 1) << ": " << lines[x] << endl;
	}
	
	output.close();
}
