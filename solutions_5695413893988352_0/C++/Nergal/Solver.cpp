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
		istr >> C >> J;
	}

	long bruteSolver(int index, string &c, string &j, long curDif)
	{
		if (index >= C.size())
			return curDif;

		while (C[index] != '?' && J[index] != '?' && index < C.size())
		{

			curDif *= 10;
			curDif += C[index] - J[index];
			++index;
		}
		if (index >= C.size())
			return curDif;

		if (C[index] == '?' && J[index] == '?')
		{
			long min = LONG_MAX;
			long absmin = LONG_MAX;
			string cc = c;
			string cj = j;
			FOR(ii, 0, 10)
			{
				FOR(ji, 0, 10)
				{
					cc[index] = '0' + ii;
					cj[index] = '0' + ji;
					long d = bruteSolver(index + 1, cc, cj, curDif * 10 + ii - ji);
					if (abs(d) < absmin)
					{
						min = d;
						absmin = abs(d);
						c = cc;
						j = cj;
					}
				}
			}
			curDif = min;
		}
		else if (C[index] == '?')
		{
			long min = LONG_MAX;
			long absmin = LONG_MAX;
			string cc = c;
			string cj = j;
			FOR(ii, 0, 10)
			{
				cc[index] = '0' + ii;
				long d = bruteSolver(index + 1, cc, cj, curDif * 10 + cc[index] - cj[index]);
				if (abs(d) < absmin)
				{
					min = d;
					absmin = abs(d);
					c = cc;
					j = cj;
				}
			}
			curDif = min;
		}
		else if (J[index] == '?')
		{
			long min = LONG_MAX;
			long absmin = LONG_MAX;
			string cc = c;
			string cj = j;
			FOR(ji, 0, 10)
			{
				cj[index] = '0' + ji;
				long d = bruteSolver(index + 1, cc, cj, curDif * 10 + cc[index] - cj[index]);
				if (abs(d) < absmin)
				{
					min = d;
					absmin = abs(d);
					c = cc;
					j = cj;
				}
			}
			curDif = min;
		}

		return curDif;
	}

	BigInteger getDif(int index, string &c, string &j, BigInteger curDif)
	{
		while (C[index] != '?' && J[index] != '?' && index < C.size())
		{
			
			curDif *= 10;
			curDif += C[index] - J[index];
			++index;
		}
	
		if (index >= C.size())
			return curDif;

		// else, we reach a '?'
		if (C[index] == '?' && J[index] == '?')
		{
			if (curDif == 0)
			{
				
				string cc = c;
				string cj = j;
				BigInteger absMin;
				BigInteger min;
				// test both 0
				cc[index] = cj[index] = '0';
				BigInteger d0 = getDif(index + 1, cc, cj, 0);
				absMin = absBigInt(d0);
				min = d0;
				c = cc;
				j = cj;
				// test 1, 0
				cc[index] = '1';
				cj[index] = '0';
				BigInteger d1 = getDif(index + 1, cc, cj, 1);
				if (absBigInt(d1) < absMin)
				{
					c = cc;
					j = cj;
					absMin = absBigInt(d1);
					min = d1;
				}
				// test 0, 1
				cc[index] = '0';
				cj[index] = '1';
				BigInteger d2 = getDif(index + 1, cc, cj, -1);
				if (absBigInt(d2) < absMin)
				{
					c = cc;
					j = cj;
					absMin = absBigInt(d2);
					min = d2;
				}
				curDif = min;
			}
			else if (curDif < 0)
			{
				// C must be maximized and J minimized
				c[index] = '9';
				j[index] = '0';
				return getDif(index + 1, c, j, curDif * 10 + 9);
			}
			else // curStatus > 0
			{
				c[index] = '0';
				j[index] = '9';
				return getDif(index + 1, c, j, curDif * 10 - 9);
			}
			
		}
		else if (C[index] == '?')
		{
			j[index] = J[index];
			if (curDif < 0)
			{
				// C must be maximized 
				c[index] = '9';
				return getDif(index + 1, c, j, curDif * 10 + '9' - j[index]);
			}
			else if (curDif > 0)
			{
				// minimize C
				c[index] = '0';
				return getDif(index + 1, c, j, curDif * 10 - ('0' - j[index]));
			}
			else // curDif == 0
			{
				string cc = c;
				string cj = j;
				BigInteger absMin;
				BigInteger min;
				// test same value as J
				cc[index] = j[index];
				BigInteger d0 = getDif(index + 1, cc, cj, 0);
				min = d0;
				absMin = absBigInt(d0);
				c = cc;
				j = cj;
				// test value of J + 1
				if (cj[index] < '9')
				{
					cc[index] = cj[index] + 1;
					BigInteger d1 = getDif(index + 1, cc, cj, 1);
					if (absBigInt(d1) < absMin)
					{
						c = cc;
						j = cj;
						min = d1;
						absMin = absBigInt(d1);
					}
				}
				// test value of J - 1
				if (cj[index] > '0')
				{
					cc[index] = cj[index] - 1;
					BigInteger d2 = getDif(index + 1, cc, cj, -1);
					if (absBigInt(d2) < absMin)
					{
						c = cc;
						j = cj;
						min = d2;
						absMin = absBigInt(d2);
					}
				}

				curDif = min;
			}
		}
		else //if (J[index] == '?')
		{
			c[index] = C[index];
			if (curDif < 0)
			{
				// J must be minized
				j[index] = '0';
				return getDif(index + 1, c, j, curDif * 10 + c[index]);
			}
			else if(curDif > 0)
			{
				// maximize J
				j[index] = '9';
				return getDif(index + 1, c, j, curDif * 10 + (c[index]-'9'));
			}
			else // curDif == 0
			{
				string cc = c;
				string cj = j;
				// test same value as J
				cj[index] = C[index];
				BigInteger d0 = getDif(index + 1, cc, cj, 0);
				BigInteger min = d0;
				BigInteger absMin = absBigInt(d0);
				c = cc;
				j = cj;
				// test value of C + 1
				if (cc[index] < '9')
				{
					cj[index] = cc[index]+1;
					BigInteger d1 = getDif(index + 1, cc, cj, -1);
					if (absBigInt(d1) < absMin)
					{
						c = cc;
						j = cj;
						min = d1;
						absMin = absBigInt(d1);
					}
				}
				// test value of J - 1
				if (cc[index] > '0')
				{
					cj[index] = cc[index] - 1;
					BigInteger d2 = getDif(index + 1, cc, cj, 1);
					if (absBigInt(d2) < absMin)
					{
						min = d2;
						c = cc;
						j = cj;
					}
				}
				curDif = min;
			}
		}
	
		return curDif;
	}

	// to solve the test case and output the value to ostr
	std::string solveTestCase()
	{
		stringstream ss;

		string fc = C;
		string fj = J;
		getDif(0, fc, fj, 0);

		cout << "Smart Solver ";
		cout << fc << " " << fj;

		string bc = C;
		string bj = J;
		bruteSolver(0, bc, bj, 0);
		cout << "Brute Solver ";
		cout << bc << " " << bj;
		if (bc != fc || bj != fj)
		{
			cout << "ERROR";
		}
		ss << bc << " " << bj;
		return ss.str();
	}

	string C, J;
};



int main(int argc, char* argv[])
{
	std::ios_base::sync_with_stdio(false);

	std::string inputFile("C:\\Users\\David\\Downloads\\B-small-attempt4.in");
	std::string outputFile("C:\\GoogleJam\\B.out");

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