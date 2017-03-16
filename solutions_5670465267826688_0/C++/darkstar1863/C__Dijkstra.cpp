#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
using namespace std;

// Types
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ipair;
const double pi=acos(-1.0);
const double eps=1e-11;

// Generic
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
#define FORD(i, a, b) for(int i=(a); i<(b); i++)
#define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
template<class T> inline T sqr(T x){return x*x;}

// Bit manipulation
template<class T> void setbit(T& v, int position)    { v |= (T)1 << position; }
template<class T> void unsetbit(T& v, int position)  { v &= ~((T)1 << position); }
template<class T> void togglebit(T& v, int position) { v ^= (T)1 << position; }
template<class T> bool isbit(T v, int position) { return (v & ((T)1 << position)) != 0; }
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}

// Input / Output
string ReadToEndLine(istream& s) { string sLine; getline(s, sLine); return sLine; }
char gStr[1024];
// sprintf_s(gStr, "%d", );

struct Runner
{
	Runner(istream& in, ostream& out) : mIn(in), mOut(out), mCase(0) {}
	void RunAll();
	void Run();
	istream& mIn; ostream& mOut;
	size_t mCase;
};

void Runner::RunAll()
{
    size_t caseCount;
    mIn >> caseCount;
    ReadToEndLine(mIn);
    for(size_t c=0; c<caseCount; ++c)
    {
        mCase = c + 1;
		cout << "Case " << mCase << ": ... ";
        Run();
		cout << "done" << endl;
    }
}

enum Letter
{
	eOne = 0,
	eI = 1,
	eJ = 2,
	eK = 3,
};

struct Value
{
	Value() : Ch(eOne), Neg(false) { }
	Value(Letter ch, bool neg) : Ch(ch), Neg(neg) { }

	Letter Ch;
	bool Neg;

	bool isI() { return Ch == eI && !Neg; }
	bool isJ() { return Ch == eJ && !Neg; }
	bool isK() { return Ch == eK && !Neg; }
};

Letter MM[4][4] = 
{
	{eOne, eI, eJ, eK},
	{eI, eOne, eK, eJ},
	{eJ, eK, eOne, eI},
	{eK, eJ, eI, eOne},
};

Value mult(const Value &lh, const Value &rh)
{
	bool neg = lh.Neg != rh.Neg;
	if ((lh.Ch != eOne && lh.Ch == rh.Ch) ||
		(lh.Ch == eI && rh.Ch == eK) ||
		(lh.Ch == eJ && rh.Ch == eI) ||
		(lh.Ch == eK && rh.Ch == eJ))
		neg = !neg;

	return Value(MM[lh.Ch][rh.Ch], neg);
}

Value fromCh(char ch)
{
	switch (ch)
	{
	case 'i':
		return Value(eI, false);
	case 'j':
		return Value(eJ, false);
	case 'k':
		return Value(eK, false);
	}
	throw exception();
}

bool solveSmall(const string &str, int X)
{
	string S;
	FORD(i, 0, X)
		S += str;

	int L = SIZE(S);
	vector<bool> I(L);
	vector<bool> K(L);

	// I
	{
		Value cur(eOne, false);
		for (int end = 0; end < L; ++end)
		{
			cur = mult(cur, fromCh(S[end]));
			I[end] = cur.isI();
		}
	}

	// K
	{
		Value cur(eOne, false);
		for (int start = L - 1; start >= 0; --start)
		{
			cur = mult(fromCh(S[start]), cur);
			K[start] = cur.isK();
		}
	}

	// J
	FORD(start, 1, L - 1)
	{
		Value cur(eOne, false);
		FORD(end, start, L - 1)
		{
			cur = mult(cur, fromCh(S[end]));
			if (cur.isJ() && I[start - 1] && K[end + 1])
				return true;
		}
	}

	return false;
}


void Runner::Run()
{
	int L, X;
	string str;
	mIn >> L >> X >> str;

	bool res = solveSmall(str, X);

	mOut << "Case #" << mCase << ": ";
	mOut << (res ? "YES" : "NO");
	mOut << endl;
}


string pathToCpp = __FILE__;
#ifdef LOCAL
#include "local_IO.cpp"
#endif

void main(int argc, char *argv[])
{
	string pathToFiles = pathToCpp;
	pathToFiles.resize(pathToFiles.size() - 4);
	string pathToInput = pathToFiles + ".in.txt";
	if(argc >= 2)
	{
		pathToFiles = pathToInput = argv[1];
	}

	{
		ifstream sIn(pathToInput);
		ofstream sMy(pathToFiles + ".my.txt");
		Runner runner(sIn, sMy);
		runner.RunAll();
	}

#ifdef LOCAL
	check_Nto1(pathToFiles + ".ok.txt", pathToFiles + ".my.txt");
#endif

	getchar();
}
