#include <functional> 
#include <iostream> 
#include <algorithm> 
#include <sstream> 
#include <string> 
#include <utility> 
#include <vector> 
#include <cmath> 
#include <queue> 
#include <map> 
#include <set>

using namespace std;

#define VT vector 
typedef VT<int> VI; 
typedef VT<VI> VVI; 
typedef VT<string> VS; 
typedef VT<double> VD; 
#define REP(i,n) for(int _n=n, i=0;i<_n;++i) 
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i) 
#define ALL(c) c.begin(),c.end() 
#define PB push_back 
#define MP make_pair 
#define FS first 
#define SC second 
#define SZ size()

int solve(int n, string shy)
{
	int standing = shy[0] - '0';
	int result = 0;

	for (int i = 1; i < shy.size(); ++i)
	{
		if (shy[i] == '0')
			continue;

		int needed = i - standing;

		if (needed > 0)
		{
			result += needed;
			standing += needed;
		}

		standing += shy[i] - '0';
	}

	return result;
}



// BEGIN CUT HERE 
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int n = 0;
		cin >> n;
		string shy;
		cin >> shy;

		int result = solve(n, shy);

		cout << "Case #" << t << ": " << result << endl;

	}

} 
// END CUT HERE 
