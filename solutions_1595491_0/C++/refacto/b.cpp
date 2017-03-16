#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <memory>
#include <assert.h>



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


int solveTest(int t)
{
	int res = 0;

	int N, S, p;
	fin >> N >> S >> p;

	vector<int> Sums(N);
	for (int n = 0 ; n < N ; ++n)
		fin >> Sums[n];

	for (auto iSum = Sums.cbegin() ; iSum != Sums.cend() ; ++iSum)
	{
		const int sum = *iSum;

		if (sum >= 3*p)			{ ++res; continue; }

		if (p >= 1)
		{
			if (sum >= 3*p-1-1)		{ ++res; continue; }

			if ((p >= 2) && (S > 0))
			{
				if (sum >= 3*p-2-2)		{ ++res; --S; continue; }
			}
		}
	}

	return res;
}




int main()
{
	assert_plus(fin, "could not open input file");
	assert_plus(fout, "could not create output file");

	string s;
	int T;
	fin >> T;
	getline(fin, s);
	for (int t = 1 ; t <= T ; ++t)
		fout << "Case #" << t << ": " << solveTest(t) << endl;

	return 0;
}

