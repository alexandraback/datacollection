#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cctype>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vs;

#define SIZE(x) ((int)(x.size()))
#define LET(var, val) auto var = (val)
#define FOR(k, a, b) for(auto k = (a); k < (b); ++k)
#define FORR(k, a, b) for(auto k = (a); k >= (b); --k)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(LET(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define PF push_front

const int INF = 1000000001;
const double EPS = 10e-9;
const double PI = acos(-1.0);

ostringstream out;

void B()
{
	int A, B, K;
	ll sum = 0;
	cin >> A >> B >> K;
	REP(i, A)
	{
		REP(j, B)
		{
			if ((int)(i & j) < K)
				sum++;
		}
	}
	out << sum << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i, t)
	{
		out << "Case #" << i + 1 << ": ";
		B();
	}

	cout << out.str();
	return 0;
}