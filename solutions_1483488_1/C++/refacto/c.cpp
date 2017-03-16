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


int nbDigits(int n)
{
	int cpt = 1;
	while (n > 9)
	{
		n /= 10;
		++cpt;
	}
	return  cpt;
}


int rot(int n, int power)
{
	int q = n / power;
	int r = n % power;
	assert_(q < 10);
	return r*10 + q;
}


int solveTest(int t)
{
	int res = 0;

	int A, B;
	fin >> A >> B;

	assert_(nbDigits(A) == nbDigits(B));
	const int digits = nbDigits(A);
	const int power = (int)pow(10.0, digits-1);

	int alreadyFounds[10];
	for (int n = A ; n < B ; ++n)
	{
		int founds = 0;
		int m = n;
		for (int i = 0 ; i < digits-1 ; ++i)
		{
			m = rot(m, power);
			if ((m > n) && (m <= B))
			{
				if (find(alreadyFounds, alreadyFounds+founds, m) != alreadyFounds+founds) continue;
				alreadyFounds[founds++] = m;
			}
		}
		res += founds;
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

