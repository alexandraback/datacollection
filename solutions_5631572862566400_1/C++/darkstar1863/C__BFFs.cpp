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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ipair;
const double pi=acos(-1.0);
const double eps=1e-11;
const ll MOD = 1000000007;

// Generic
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
#define FORD(i, a, b) for(int i=(a); i<(b); i++)
#define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
#define two(X) (1<<(X))
#define twoL(X) (((ll)(1))<<(X))
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

int dfs(const vector<vector<int> > &F2K, int S, const set<int> &Ends)
{
	int ret = 0;
	FORS(i, F2K[S])
	{
		if (Ends.find(F2K[S][i]) != Ends.end())
			continue;

		ret = max(ret, 1 + dfs(F2K, F2K[S][i], Ends));
	}

	return ret;
}

void Runner::Run()
{
	int N;
	mIn >> N;

	vector<int> F(N);
	FORS(i, F)
		mIn >> F[i];
	FORS(i, F)
		--F[i];

	vector<vector<int> > F2K(N);
	FORS(i, F)
	{
		F2K[F[i]].push_back(i);
	}

	int res = 1;

	// Circles
	vector<bool> U(N);
	set<int> Ends;
	FORS(s, F)
	{
		fill(U.begin(), U.end(), false);
		U[s] = true;
		int cur = s;
		int len = 1;
		while (!U[F[cur]])
		{
			U[F[cur]] = true;
			cur = F[cur];
			++len;
		}

		if (F[cur] != s)
			continue;

		res = max(res, len);
		if (len == 2)
		{
			Ends.insert(s);
			Ends.insert(F[s]);
		}
	}

	// Try to group ends
	int sum = SIZE(Ends);
	for (auto it : Ends)
	{
		sum += dfs(F2K, it, Ends);
	}
	res = max(res, sum);

	mOut << "Case #" << mCase << ": ";
	mOut << res;
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
