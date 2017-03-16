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

bool can(int m, vector<int>&cakes)
{
	for (int changes = 0; changes <= m - 1; ++changes)
	{
		int level = m - changes;

		int amount = 0;
		for (int i = 0; i < cakes.size(); ++i)
		{
			if (cakes[i] <= level)
				break;

			else
			{
				int overdose = cakes[i] - level;
				amount += (overdose + level - 1) / level;
			}
		}

		if (amount <= changes)
			return true;
	}

	return false;
}

int solve(vector<int> cakes)
{
	sort(cakes.rbegin(), cakes.rend());

	if (cakes.size() == 0 || cakes[0] == 0)
		return 0;

	int high = cakes[0], low = 0;

	while (low + 1 < high)
	{
		int m = (high + low) / 2;
		if (can(m, cakes))
			high = m;
		else
			low = m;
	}

	return high;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{

		int d;
		cin >> d;

		vector<int> cakes(d);
		for (int i = 0; i < d; ++i)
			cin >> cakes[i];



		int result = solve(cakes);

		cout << "Case #" << t << ": " << result << endl;
		cerr << "Case #" << t << ": " << result << endl;

	}

}
