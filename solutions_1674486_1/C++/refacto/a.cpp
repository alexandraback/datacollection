#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <memory>
#include <assert.h>


#define NOT_USED(formal_param)  {(formal_param) = (formal_param);}


template<class T, class E>
inline bool contains(const T & Container, const E & Element)
{
	return find(Container.begin(), Container.end(), Element) != Container.end();
}


template<class T>
inline std::string to_string(const T & value)
{
	std::ostringstream oss;
	std::string res;
	oss.setf(std::ios::fixed); 
	oss.precision(15); 
	oss << value;
	res = oss.str();
	return res;
}


template<class T>
inline T from_string(const std::string & s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}


template<typename T>
inline bool from_string(const std::string & s, T & dest)
{
    std::istringstream iss(s);
    return iss >> dest != 0;
}



#ifdef _DEBUG

	inline void assert_false_plus(const std::string & message)
	{message;
 		assert(false);
	}

	inline void assert_false()				{ assert_false_plus(""); }

	#define assert_plus(expr, message)		{ if (!(expr)) assert_false_plus(message); }
	#define assert_(expr)					{ assert_plus(expr, ""); }

#else

	#define assert_false_plus(message)
	#define assert_false()
	#define assert_plus(expr, message)
	#define assert_(expr)

#endif






using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");






bool diamond(const vector<vector<int>> & Parents, int a, int z)
{
	int count = 0;
	vector<int> ToVisit(1, a);
	vector<bool> Visited(Parents.size(), false);
	Visited[a] = true;
	while (!ToVisit.empty())
	{
		int c = ToVisit.back();
		ToVisit.pop_back();
		if (c == z)
		{
			if (++count == 2) return true;
			fill(Visited.begin(), Visited.end(), false);
			Visited[a] = true;
			continue;
		}
		const auto & ParentsC = Parents[c];
		for (auto ip = ParentsC.cbegin() ; ip != ParentsC.cend() ; ++ip)
			if (!Visited[*ip])
			{
				ToVisit.push_back(*ip);
				Visited[*ip] = true;
			}
	}

	return false;
}



string solveTest(int t)
{
	NOT_USED(t)

	int N;
	fin >> N;
	vector<vector<int>> Parents(N);

	for (int i = 0 ; i < N ; ++i)
	{
		auto & ParentsI = Parents[i];
		int Mi;
		fin >> Mi;
		ParentsI.resize(Mi);

		for (int j = 0 ; j < Mi ; ++j)
		{
			int p;
			fin >> p;
			ParentsI[j] = p-1;
		}
	}

	for (int a = 0 ; a < N ; ++a)
	for (int z = 0 ; z < N ; ++z)
		if (a != z)
			if (diamond(Parents, a, z)) return "Yes";

	return "No";
}



int main()
{
	assert_plus(fin, "could not open input file");
	assert_plus(fout, "could not create output file");
	fout.setf(ios::fixed);
	fout.precision(15);

	int T;
	fin >> T;
	{ string s; getline(fin, s); }
	for (int t = 1 ; t <= T ; ++t)
	{
		cout << "Case #" << t << "..." << endl;
		fout << "Case #" << t << ": " << solveTest(t) << endl;
	}

	return 0;
}

