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
string s;
int n;

vi allowed(26, 1);

int GetNValue()
{
	int len = s.size();


	int res = 0;

	FORI(k, 1, len + 1) FOR(i, len - k + 1)
	{
		int cnt = 0;
		FORI(j, i, i + k)
		{
			int v = s[j] - 'a';
			if (allowed[v]) ++cnt;
			else cnt = 0;
			if (cnt == n)
			{
				++res;
				break;
			}
		}
	}
	
	return res;
}

int main()
{
	ofstream cout ("A-small-attempt0.out");
	ifstream cin ("A-small-attempt0.in");


	int cases;
	cin >> cases;


	allowed[int('a' - 'a')] = 0;
	allowed[int('e' - 'a')] = 0;
	allowed[int('i' - 'a')] = 0;
	allowed[int('o' - 'a')] = 0;
	allowed[int('u' - 'a')] = 0;

	FOR(cs, cases)
	{
		cin >> s >> n;

		cout << PrintCase(cs) << GetNValue() << endl;
	}

	int i;
	cin >> i;

	return 0;
}
#endif