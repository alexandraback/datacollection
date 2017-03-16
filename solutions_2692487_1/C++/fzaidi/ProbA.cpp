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

int N;
vi motes;

int GetMinOperations(int curIdx, int curSize)
{
	if (curIdx == N)
		return 0;

	int cnt = N - curIdx; // Remove all until the end

	// Count the number of operations needed to eat the next mote	
	int target = motes[curIdx];

	int ops = 0;

	while (curSize <= target)
	{
		curSize += (curSize - 1);
		++ops;
	}

	if (ops >= cnt)
		return cnt;

	cnt = min(cnt, ops + GetMinOperations(curIdx + 1, curSize + target));

	return cnt;
}

int main()
{
	ofstream cout ("A-large.out");
	ifstream cin ("A-large.in");

	int cases;
	cin >> cases;

	FOR(cs, cases)
	{
		int A;
		cin >> A >> N;
		motes.clear();
				
		motes.resize(N);
		FOR(i, N) cin >> motes[i];

		int total = accumulate(motes.begin(), motes.end(), 0);

		sort(motes.begin(), motes.end());

		int mn = (A == 1) ? N : GetMinOperations(0, A);

		cout << PrintCase(cs) << mn << endl;
	}

	int i;
	cin >> i;

	return 0;
}
#endif