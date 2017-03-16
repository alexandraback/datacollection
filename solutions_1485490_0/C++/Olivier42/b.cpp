#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <stdexcept>
#include <fstream>
#include <map>
#include <limits>
#include <math.h>

template<typename T>
void FillVector(std::istream& istr, std::vector<T>& values, size_t n)
{
	for( size_t i = 0; i < n; ++i)
	{
		T value;

		istr >> value;
		values.push_back(value);
	}
}

template<typename T1, typename T2>
void FillVector(std::istream& istr, std::vector<std::pair<T1, T2> >& values, size_t n)
{
	for( size_t i = 0; i < n; ++i)
	{
		T1 value1;
		T2 value2;

		istr >> value1;
		istr >> value2;
		values.push_back(std::make_pair(value1, value2));
	}
}

typedef std::pair<int64_t, int64_t> T_Pair;

int64_t SolveRec(std::map<T_Pair, int64_t>& results, const std::vector<T_Pair>& values1, int64_t i, const std::vector<T_Pair>& values2, int64_t j)
{
	auto it = results.find(std::make_pair(i, j));

	if( it != results.end())
	{
	//	std::cout << i << "  "  << j << std::endl;
	//	std::cout << it->second << std::endl;
		return it->second;
	}

	if( i == 0 || j == 0)
	{
		//std::cout << i << "  "  << j << std::endl;
	//	std::cout << 0 << std::endl;
		return 0;
	}


	auto& p1 = values1[i-1];
	auto& p2 = values2[j-1];

	int64_t res = 0;

	if( p1.second == p2.second)
	{
		int64_t nbMatch = std::min(p1.first, p2.first);
		res = nbMatch;

		if(p1.first == p2.first)
			res += SolveRec(results, values1, i - 1, values2, j - 1);
		else if (p1.first < p2.first )
		{
			std::vector<T_Pair> values2Updated = values2;
			std::map<T_Pair, int64_t> resultsUpdated;

			values2Updated[j-1].first = values2Updated[j-1].first - nbMatch;
			res += SolveRec(resultsUpdated, values1, i - 1, values2Updated, j);
		}
		else
		{
			std::vector<T_Pair> values1Updated = values1;
			std::map<T_Pair, int64_t> resultsUpdated;

			values1Updated[i-1].first = values1Updated[i-1].first - nbMatch;
			res += SolveRec(resultsUpdated, values1Updated, i, values2, j - 1);
		}
	}
	else
	{
		int64_t case1 = SolveRec(results, values1, i - 1, values2, j);
		int64_t case2 = SolveRec(results, values1, i, values2, j - 1);

		res =  std::max(case1, case2);
	}

	results.insert(std::make_pair(T_Pair(i, j), res ));
//	std::cout << i << "  "  << j << std::endl;
	//std::cout << res << std::endl;
	return res;
}

int64_t Solve(std::vector<T_Pair>& values1, std::vector<T_Pair>& values2)
{
	std::map<T_Pair, int64_t> results;
	return SolveRec(results, values1, values1.size(), values2, values2.size());
}

int main(int argc, char** argv)
{
	const std::string inputFilename = "src/C-small-attempt2.in";
	const std::string outputFilename = inputFilename + ".out";
	std::ifstream ifs( inputFilename.c_str() );
	std::ofstream file( outputFilename.c_str());
	int nbTest = 0;

	ifs >> nbTest;
	std::string line;
	std::getline(ifs, line);

	for( int test = 1; test <= nbTest; ++test )
	{
		std::ostringstream ostr;

		int64_t n, m;

		ifs >> n >> m;

		std::vector<std::pair<int64_t, int64_t> > values1;
		std::vector<std::pair<int64_t, int64_t> > values2;

		FillVector(ifs, values1, n);
		FillVector(ifs, values2, m);

		ostr << "Case #" << test << ": ";
		ostr << Solve(values1, values2);
		ostr << std::endl;

		std::cout << ostr.str();
		file << ostr.str();
	}

	std::cout << "Finish" << std::endl;
	return 0;
}


