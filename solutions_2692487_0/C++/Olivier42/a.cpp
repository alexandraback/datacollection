#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <stdexcept>
#include <fstream>
#include <map>
#include <limits>
#include <math.h>
#include <iomanip>
#include <iomanip>
#include <algorithm>

using namespace std;

template<typename T>
string ToString(T v)
{
	ostringstream ostr;

	ostr << v;

	return ostr.str();
}

typedef __int64 int64_t;



int Solve(int a, vector<int64_t> inputs)
{
	std::sort(inputs.begin(), inputs.end());
	int best = inputs.size();
	int currentResults = 0;

	for (int i = 0; i < inputs.size(); ++i)
	{
		auto v = inputs[i];

		if (a > v)
			a += v;
		else
		{
			best = std::min(best, (int)(currentResults + inputs.size() - i));

			if ( a == 1 )
				++currentResults;
			else
			{
				while (a <= v)
				{
					a += (a - 1);
					++currentResults;
				}
				a += v;
			}
		}
	}
	return std::min(best, currentResults);
}

int main(int argc, char** argv)
{
	const string inputFilename = "A-small-attempt2.in";
	const string outputFilename = inputFilename + ".out";
	ifstream ifs( inputFilename.c_str() );
	ofstream file( outputFilename.c_str());
	int nbTest = 0;

	ifs >> nbTest;
	string line;
	getline(ifs, line);

	for( int test = 1; test <= nbTest; ++test )
	{
		ostringstream ostr;
		int64_t a, n;
				
		ifs >> a >> n;
		vector<int64_t> inputs;

		for (int i = 0 ; i < n; ++i)
		{
			int64_t v;

			ifs >> v;
			inputs.push_back(v);
		}
		
		getline(ifs, line);
		ostr.precision(15);
		ostr << "Case #" << test << ": ";

		ostr << Solve(a, inputs);		
		ostr << endl;

		cout << ostr.str();
		file << ostr.str();
	}

	cout << "Finish" << endl;
	return 0;
}



