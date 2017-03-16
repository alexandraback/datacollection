#include <iostream>
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





vector<pair<int, int>> Requirements;
int stars = 0;
int times = 0;
int levels2 = 0;


bool turn()
{
	const int L = Requirements.size();

	++times;

	{
		for (int i = 0 ; i < L ; ++i)
			if (Requirements[i].second <= stars)
				if (Requirements[i].first == -1)
				{
					stars += 1;
					++levels2;
					Requirements[i] = Requirements.back();
					Requirements.resize(L-1);
					return true;
				}

		int best = 0;
		int max1 = -1;
		for (int i = 0 ; i < L ; ++i)
			if (Requirements[i].second <= stars)
				if (Requirements[i].first > max1)
				{
					best = i;
					max1 = Requirements[i].first;
				}

		if (Requirements[best].second <= stars)
		{
			stars += 2;
			++levels2;
			Requirements[best] = Requirements.back();
			Requirements.resize(L-1);
			return true;
		}
	}

	{
		int best = 0;
		int max2 = -1;
		for (int i = 0 ; i < L ; ++i)
			if (Requirements[i].first != -1)
				if (Requirements[i].first <= stars)
					if (Requirements[i].second > max2)
					{
						best = i;
						max2 = Requirements[i].second;
					}

		if ((Requirements[best].first <= stars) && (Requirements[best].first != -1))
		{
			Requirements[best].first = -1;
			++stars;
			return true;
		}
	}

	return false;
}



string solveTest(int t)
{
	NOT_USED(t)

	int N;
	fin >> N;
	Requirements.resize(N);
	for (int n = 0 ; n < N ; ++n)
	{
		fin >> Requirements[n].first >> Requirements[n].second;
	}
	stars = 0;
	times = 0;
	levels2 = 0;

	while (!Requirements.empty())
	{
		if (!turn())
			return "Too Bad";
	}

	return to_string(times);
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
		fout << "Case #" << t << ": " << solveTest(t) << endl;

	return 0;
}

