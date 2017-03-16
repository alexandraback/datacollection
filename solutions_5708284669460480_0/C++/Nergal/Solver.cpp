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
		istr >> K;
		istr >> L;
		istr >> S;
		istr >> strIn;
		istr >> strOut;
			
	}

	// to check test case reading was ok
	std::string toString() const 
	{
		stringstream out;
		//out << "spect="<<spect<<endl;
		
		return out.str();
	}


	bool checkIsPossible()
	{
		//if (strOut.length() > S)
		//	return false;

		FOR(i, 0, strOut.length())
		{
			if (strIn.find(strOut[i]) == string::npos)
				return false;
		}

		return true;
	}

	double getMaxNumberOfBananas()
	{
		int el = strOut.length();
		int overlap = 0;

		// nbchar differents ?
		set<char> letters;
		letters.insert(strOut.begin(), strOut.end());

		int nbDifChar = letters.size();
		if (nbDifChar == 1)
		{
			return 1+S-L; // each char can be the right one
		}

		// more than one different char, try to find a repetition
		int curC = 1;
		int begin = 0;
		bool match = true;
		bool internalMatch = false;
		int longestMatch = 0;
		int shiftForNextWord = L;

		int t = strOut.find(strOut[L-1]);
		if (t >= (L-t-1))
		{
			match = false;
			longestMatch = 0;
		}
		else 
		{
			// check string  [0, t] match string [(L-1-t),(L-1)]
			string subStrLeft = strOut.substr(0, t+1);
			string subStrRight = strOut.substr(L-1-t, t+1);
			if (subStrLeft != subStrRight)
			{
				match = false;
			longestMatch = 0;
			}
			else {
				match = true;
				longestMatch = t+1;
				shiftForNextWord = L - longestMatch;

				// ok, so we have a longestMatch, now check if another occurence exist between begin and end of the word, ie ABABAB
				if (L == (3*longestMatch))
				{
					string strMid = strOut.substr(longestMatch, longestMatch);
					if (strMid == subStrLeft)
					{
						internalMatch = true;
						shiftForNextWord = longestMatch;
					}
				}
			}
		}

		double maxBananas = (S - L)/shiftForNextWord;

		cout <<"maxBananas = "<<maxBananas<<endl;

		return maxBananas;	
	}

	list<string>  generateallstr()
	{
		list<string> newGen;
		FOR(i, 0, K)
		{		
			string s ;
			s += strIn[i];
			newGen.push_back(s);
		}

		return generate(1, newGen);
	}

	list<string>  generate(int c, list<string> &generatedstr)
	{

		if (c==S)
			return generatedstr;

		list<string> newGen;
		FOR(i, 0, K)
		{
			list<string>::iterator it = generatedstr.begin();
			list<string>::iterator ite = generatedstr.end();
			for ( ; it != ite; ++it)
			{
				string s = (*it);
				s += strIn[i];
				newGen.push_back(s);
			}
		}

		return generate(c+1, newGen);
	}

	int countOcc(string &s)
	{
		// how many bananas for this string ?
		int t = s.find(strOut);
		int count = 0;
		while (t != string::npos)
		{
			++count;
			t = s.find(strOut, t+1);
		}

		//cout <<"for "<<s<<" nb occ="<<count<<endl;
		return count;
	}

	


	// to solve the test case and output the value to ostr
	std::string solveTestCase()
	{		
		stringstream out;

		double remainingBananas = 0.0;
		
		if (checkIsPossible()) // else always 0
		{
			
			list<string>  generatedStr = generateallstr();
			int maxBan = 0;
			int totalBan = 0;
			
			list<string>::iterator it = generatedStr.begin();
			list<string>::iterator ite = generatedStr.end();
			for ( ; it != ite; ++it)
			{
				int nbBan = countOcc(*it);
				totalBan += nbBan;
				if (nbBan > maxBan)
					maxBan = nbBan;
			}

			double avgPay = double(totalBan)/generatedStr.size();
			remainingBananas = maxBan - avgPay;

		}
		
		out.precision(7);
		out << remainingBananas;
		
		return out.str();
	}

	

private:
	int K;
	int L;
	int S;

	string strIn;
	string strOut;
};


int main(int argc, char* argv[])
{
	std::string inputFile("C:\\Users\\David\\Downloads\\B-small-attempt0.in");
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

	cout <<"Toto"<<endl;
	cin.ignore(1);

	return 0;
}