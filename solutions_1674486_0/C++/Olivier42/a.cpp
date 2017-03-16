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
void FillVector(std::istream& istr, std::set<T>& values, size_t n)
{
	for( size_t i = 0; i < n; ++i)
	{
		T value;

		istr >> value;
		values.insert(value);
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

typedef std::map<int, int>  T_Dep;



T_Dep FullDepencies(std::map< int, T_Dep>& depCompute, const std::vector<std::set<int> >& values, int n)
{
	auto it = depCompute.find(n);

	if( it != depCompute.end())
		return it->second;

	const auto& depencies = values[n-1];

	T_Dep allDep;
	for(auto dep : depencies)
	{
		++allDep[dep];
		T_Dep currentDep = FullDepencies(depCompute, values, dep);
		for(auto dep2: currentDep)
			allDep[dep2.first] += dep2.second;
	}

	depCompute.insert(std::make_pair(n, allDep));
	return allDep;
}

std::string Solve(std::vector<std::set<int> >& values)
{
	std::map< int, T_Dep> depCompute;

	for( int i = 1; i <= values.size(); ++i)
	{
		T_Dep dep = FullDepencies(depCompute, values, i);
	//	std::cout << i << std::endl;
		for(const auto& d : dep)
		{
		//	std::cout << d.first << " " << d.second << std::endl;
			if(d.second >= 2)
				return "Yes";
		}
	//	std::cout << std::endl;
	}

	return "No";
}

int main(int argc, char** argv)
{
	const std::string inputFilename = "src/A-small-attempt0.in";
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

		int n;

		ifs >> n;
		std::getline(ifs, line);
		std::vector<std::set<int> > values;

 		for( int i = 0; i < n; ++i)
		{
			int m;

			ifs >> m;

			std::set<int> value;
			FillVector(ifs, value, m);
			values.push_back(value);
		}

		ostr << "Case #" << test << ": ";
		ostr << Solve(values);
		ostr << std::endl;

		std::cout << ostr.str();
		file << ostr.str();
	}

	std::cout << "Finish" << std::endl;
	return 0;
}


