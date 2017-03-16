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


/*struct cmp
{
bool operator()(const T& a, const T &b)
{
return a < b;
}
};
*/


class TestCaseSolver
{
public:
	TestCaseSolver() {}

	~TestCaseSolver() {
	}

	// to read/init the test case
	void readTestCase(std::istream &istr)
	{
		istr >> S;
	}

	// to solve the test case and output the value to ostr
	std::string solveTestCase()
	{
		stringstream ss;

		vector<int>  numbers(10, 0);

		numbers[0] = std::count(all(S), 'Z');
		numbers[2] = std::count(all(S), 'W');
		numbers[6] = std::count(all(S), 'X');
		numbers[7] = std::count(all(S), 'S') - numbers[6];
		numbers[5] = std::count(all(S), 'V') - numbers[7];
		numbers[4] = std::count(all(S), 'F') - numbers[5];
		numbers[1] = std::count(all(S), 'O') - numbers[0] - numbers[2] - numbers[4];
		numbers[3] = std::count(all(S), 'R') - numbers[0] - numbers[4];
		numbers[9] = (std::count(all(S), 'N') - numbers[1] - numbers[7])/2;
		numbers[8] = std::count(all(S), 'G');

		FOR(i, 0, 10)
		{
			while (numbers[i])
			{
				numbers[i] -= 1;
				ss << char('0' + i);
			}
		}

		return ss.str();
	}

	string S;
};



int main(int argc, char* argv[])
{
	std::ios_base::sync_with_stdio(false);

	std::string inputFile("C:\\Users\\David\\Downloads\\A-small-attempt1.in");
	std::string outputFile("C:\\GoogleJam\\A.out");

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