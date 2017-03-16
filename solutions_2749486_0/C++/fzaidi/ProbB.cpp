#define ENABLE_MAIN 1
#if ENABLE_MAIN


#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <list>
#include <queue>
#include <numeric>
#include <iomanip>
#include <fstream>


using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<ll, ll> PLL;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;

const ll oo = 1LL << 60;
const int kNumMoves = 4;
const int kMoves[kNumMoves][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

#define FOR(i, n) for (int i = 0; i < int(n); ++i)
#define FORI(i, s, n) for (int i = s; i < int(n); ++i)
#define FORD(i, n) for (int i = n - 1; i >= 0; --i)
#define VALID(i, mx) (i >= 0 && i < mx)

string PrintCase(int i)
{     
	ostringstream os;
	os << "Case #" << (i + 1) << ": ";
	return os.str();
}

int x, y;

string GetDir(int xx, int yy)
{
	if (xx == -1)
		return "EW";
	else if (xx == 1)
		return "WE";
	else if (yy == -1)
		return "NS";
	return "SN";
}

string GetResult()
{
	string res;

	while (x)
	{
		if (x > 0)
		{ res += GetDir(1, 0); --x;}
		else
		{ res += GetDir(-1, 0); ++x; }
	}

	while (y)
	{
		if (y > 0)
		{ res += GetDir(0, 1); --y;}
		else
		{ res += GetDir(0, -1); ++y; }
	}
	
	return res;
}

int main()
{
	ofstream cout ("B-small-attempt0.out");
	ifstream cin ("B-small-attempt0.in");

	int cases;
	cin >> cases;

	FOR(cs, cases)
	{
		cin >> x >> y;

		cout << PrintCase(cs) << GetResult() << endl;
	}

	int i;
	cin >> i;

	return 0;
}
#endif