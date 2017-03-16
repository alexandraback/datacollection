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
vi found(10000000);
int cnt;

ull Convert(int prefix, int suffix)
{
	return ull(prefix + 1) * ull(suffix + 1);
}
	
ull GetNValue()
{
	int len = s.size();
	

	ll res = 0;
	cnt = 0;
	int sz = 0;
	FOR(i, len)
	{
		int v = s[i] - 'a';
		if (allowed[v]) ++sz;
		else sz = 0;
		
		if (sz == n)
		{
			found[cnt++] = i - n + 1;
			--sz;
		}
	}
	 
	if (!cnt)
		return 0;

	res = Convert(found[0], len - (found[0] + n));

	FORI(i, 1, cnt)
	{
		int prefix = found[i] - (found[i - 1] + 1);
		int suffix = len - (found[i] + n);
		res += Convert(prefix, suffix);
	}
	
	return res;
}

int main()
{
	ofstream cout ("A-large.out");
	ifstream cin ("A-large.in");


	int cases;
	cin >> cases;


	allowed[int('a' - 'a')] = 0;
	allowed[int('e' - 'a')] = 0;
	allowed[int('i' - 'a')] = 0;
	allowed[int('o' - 'a')] = 0;
	allowed[int('u' - 'a')] = 0;

	ostringstream os;
	FOR(cs, cases)
	{
		cin >> s >> n;
		os << PrintCase(cs) << GetNValue() << endl;
	}

	cout << os.str();

	int i;
	cin >> i;

	return 0;
}
#endif