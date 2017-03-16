#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool check(ll N)
{
	vector<int> v;
	while (N)
	{
		v.push_back(N%10);
		N /= 10;
	}
	REP(i, v.size())
		if (v[i] != v[v.size()-1-i])
			return false;
	return true;
}

vector<ll> good;

void Solve(int tc)
{
	ll A, B;
	scanf("%lld%lld", &A, &B);

	int res = 0;
	REP(i, good.size())
		if (A <= good[i] && good[i] <= B)
			++res;

	printf("Case #%d: %d\n", tc, res);
}

int main()
{
	for (ll i = 1; i <= 10000000; ++i)
		if (check(i) && check(i*i))
		{
			//cout << i << " -> " << i*i << endl;
			good.push_back(i*i);
		}

	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}