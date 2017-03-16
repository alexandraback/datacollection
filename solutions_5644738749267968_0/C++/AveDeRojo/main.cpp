#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <set>
#include <iomanip>
#include <cstdio>

using std::vector;
using std::ostream;
using std::istream;
using std::set;

void readAndSortBlocks(int numBlocks, std::ifstream &in, vector<float>& person)
{
	person.clear();
	for (int j = 0; j < numBlocks; ++j)
	{
		float weight = 0.0f;
		in >> weight;
		person.push_back(weight);
	}
	std::sort(person.begin(), person.end());
}

int playDeceitfulWar(vector<float> &naomiBlocks, vector<float> &kenBlocks)
{
	int naomiResult = 0;
	int left = 0;
	int right = kenBlocks.size() - 1;
	for (int i = 0; i < naomiBlocks.size(); ++i)
	{	
		if (naomiBlocks[i] < kenBlocks[left])
		{
			right--;
		}
		else
		{
			naomiResult++;
			left++;
		}
			
	}
	return naomiResult;
}

int playWar(vector<float> naomiBlocks, vector<float> kenBlocks)
{
	int naomiResult = 0;
	for (int i = 0; i < naomiBlocks.size(); ++i)
	{
		std::vector<float>::iterator it = std::find_if(kenBlocks.begin(), kenBlocks.end(), 
			[&naomiBlocks, i](float n){ return n > naomiBlocks[i];});
		if (it == kenBlocks.end())
		{
			naomiResult++;
			kenBlocks.erase(kenBlocks.begin());
		}
		else
		{
			kenBlocks.erase(it);
		}			
	}
	return naomiResult;
}

int main()
{
	std::ifstream in("D-small-attempt0.in");
	std::ofstream out("textOut.txt");

	int numberOfCases = 0;
	in >> numberOfCases;

	for (int i = 1; i < numberOfCases + 1; ++i)
	{
		int numberOfblocks = 0;
		in >> numberOfblocks;
		vector<float> naomiBlocks;
		readAndSortBlocks(numberOfblocks, in, naomiBlocks);
		vector<float> kenBlocks;
		readAndSortBlocks(numberOfblocks, in, kenBlocks);

		out << "Case #" << i << ": " << 
			playDeceitfulWar(naomiBlocks, kenBlocks) << " " 
			<< playWar(naomiBlocks, kenBlocks) << std::endl;
	}
	return 0;
}