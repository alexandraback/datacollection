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

bool IsCons(char c)
{
	return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

int64_t Solve(string name, int n)
{

	vector<int> pos;
	int count = 0;

	for (int i = 0; i < name.size(); ++i)
	{
		if (IsCons(name[i]))
		{
			++count;
			if (count >=n)
				pos.push_back(i - n);
		}
		else
			count = 0;
	}

	int64_t res = 0;
	int j = 0;
	for (int i = 0; i < name.size() && j < pos.size(); ++i)
	{		
		res += name.size() - pos[j] - n;
		if (i > pos[j])
			++j;
	}
	return res;
}

int main(int argc, char** argv)
{
	const string inputFilename = "A-small-attempt0.in";
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
								
		getline(ifs, line);
		auto pos = line.find(' ' );
		auto name = line.substr(0, pos);

		istringstream istr(line.substr(pos));

		istr >> n;

		ostr.precision(15);
		ostr << "Case #" << test << ": ";

		ostr << Solve(name, n);		
		ostr << endl;

		cout << ostr.str();
		file << ostr.str();
	}

	cout << "Finish" << endl;
	return 0;
}



