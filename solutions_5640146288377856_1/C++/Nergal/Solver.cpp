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

//#include "bigint-2010.04.30\BigInteger.hh"

using namespace std;

#define FOR(i,a,b) for(long i=(a), _b=(b); i < _b;++i)
#define all(a) (a).begin(), (a).end()

const double pi = 2 * acos(0.0);
// greatest common divisor
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
// square
template<class T> T sqr(T a) { return (a) * (a); }

typedef std::vector<int> vi;
typedef std::vector<long> vl;
typedef pair<int, int> pii;
typedef std::vector< pii > vii;
typedef std::list< std::string > lss;
typedef std::list<int> lsi;
typedef std::list<long> lsl;
//typedef vector<BigInteger> vbi;
//typedef list<BigInteger> lbi;

struct cmp
{
	bool operator()(int i, int j)
	{
		return i >j;
	}
};

class TestCaseSolver 
{
public:
	TestCaseSolver() {
		

	}

	// to read/init the test case
	void readTestCase(std::istream &istr)
	{
		istr >> R;
		istr >> C;
		istr >> W;
			
	}

	// to check test case reading was ok
	std::string toString() const 
	{
		stringstream out;
		//out << "spect="<<spect<<endl;
		
		return out.str();
	}

	int treatLineMiss(int x1, int x2)
	{
		int t = x1 + W -1;
		if (t >= (C-W+1))
			return (C-W+1);
		else
			return x1 + W-1;
	}

	int playToSink(int x)
	{

	}



	// to solve the test case and output the value to ostr
	std::string solveTestCase()
	{		
		stringstream out;

		int currentLine = 0;

		int target = (C-W+1);


		int totalmove = 0;
		int movePerLine = C/W;
		
		totalmove = (R-1) * movePerLine;

		// last line
	//	int t = 0 + movePerLine*W;
	//	if (t < (C-W+1))
	//		++ totalmove;

		int r = C;
		while (r>=2*W)
		{
			r -= W;
			++totalmove;
		}
		if (C%W > 0)
			++totalmove;
		
		totalmove  += W ;

		out << totalmove;
		
		
		return out.str();
	}

	

private:


	int C;
	int R;
	int W;
};


int main(int argc, char* argv[])
{
	std::string inputFile("C:\\Users\\David\\Downloads\\A-large.in");
	std::string outputFile("C:\\\Users\\David\\out.txt");

	ofstream out;
	ifstream in;

	in.open(inputFile);
	out.open(outputFile);

	unsigned long nbTestCases;
	in >> nbTestCases;

	char buffer[256];

	for (unsigned long curTest = 1 ; curTest <= nbTestCases ; ++curTest)
	{
		TestCaseSolver testCaseSolver;

		// 1-read test case
		testCaseSolver.readTestCase(in);

		//cout << testCaseSolver.toString() << endl;

		// 2-process test case
		std::string answer = testCaseSolver.solveTestCase();

		// 3-output test case result		
		sprintf_s(buffer, "Case #%d: ", curTest);
		string res=buffer + answer;

		cout << res<<endl;
		out << res << endl;
	}

	return 0;
}