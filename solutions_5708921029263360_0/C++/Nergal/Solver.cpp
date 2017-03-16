#include <memory>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <math.h>  
#include <cmath>  
#include <bitset>

#include "bigint-2010.04.30/BigInteger.hh"

using namespace std;

#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (long i(a), _b(b); i < _b; ++i)
const double pi = 2 * acos(0.0);
// greatest common divisor
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
// square
template<class T> T sqr(T a) { return (a)* (a); }

/*
struct cmpParty
{
	bool operator()(const party& a, const party &b)
	{
		return a.second > b.second;
	}
};*/


BigInteger absBigInt(const BigInteger &bg)
{
	if (bg < 0)
		return bg*BigInteger(-1);
	return bg;
}


class TestCaseSolver
{
public:
	TestCaseSolver() {}

	~TestCaseSolver() {
	}

	// to read/init the test case
	void readTestCase(std::istream &istr)
	{
		istr >> J >> P >> S >> K;

		
	}

	map<long, int> pairOccurences;
	bool addAsPairs(int j, int p, int s)
	{
		long js = 10000 * (1+j) + s+1;
		if (pairOccurences[js] >= K)
			return false;

		long jp = 10000 * (1+j) + 100 * (1+p);
		if (pairOccurences[jp] >= K)
			return false;
		
		long ps = 100 * (1+p) + 1+s;
		if (pairOccurences[ps] >= K)
			return false;

		pairOccurences[jp] += 1;
		pairOccurences[js] += 1;
		pairOccurences[ps] += 1;
		return true;
	}


	// to solve the test case and output the value to ostr
	std::string solveTestCase()
	{
		stringstream ss, tmp;

		long total = 0;
		FOR(j, 0, J)
		{
			FOR (p, 0, P)
			{
				FOR (s, 0, S)
				{
					if (addAsPairs(j, p, s))
					{
						++total;
						tmp << "\n" << 1 + j << " " << 1 + p << " " << 1 + s;
					}
				}
			}
		}

		/*

		int total = 0;
		FOR (k, 0, K)
		{
			FOR(j, 0, J)
			{
				for (int p = 0 + j; p < P && p < 1 + K + j; ++p)
				{
					for (int s = 0 + j; s < S; s += 2)
					{
						++total;
						tmp << "\n" << 1 + j << " " << 1 + p << " " << 1 + s;
					}
				}
			}
		}*/

		ss << total ;
		ss  << tmp.str();
		
		return ss.str();
	}


	int P, S, J, K;

};



int main(int argc, char* argv[])
{
	std::ios_base::sync_with_stdio(false);

	std::string inputFile("C:\\Users\\David\\Downloads\\C-small-attempt0.in");
	std::string outputFile("C:\\GoogleJam\\C.out");

	ofstream out;
	ifstream in;

	//in.open(argv[1]);
	//out.open(argv[2]);
	in.open(inputFile);
	out.open(outputFile);

	unsigned int nbTestCases;
	in >> nbTestCases;

	for (unsigned int curTest = 1; curTest <= nbTestCases; ++curTest)
	{
		TestCaseSolver testcaseSolver;

		testcaseSolver.readTestCase(in);
		std::string answer = testcaseSolver.solveTestCase();
		out << "Case #" << curTest << ": " << answer << '\n';
		cout << "Case #" << curTest << ": " << answer << endl;

	}
	out << flush;

	return 0;
}