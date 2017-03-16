#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>
 
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;
 
#define mp make_pair
#define pb push_back
#define X first
#define Y second
 
#define dbg(x) { cerr << #x << " = " << x << endl; }
 
// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);
 
#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;
 
#define NAME "basket"


LL rev(LL x)
{
	vector <int> a;
	while (x)
	{
		a.pb(x % 10);
		x /= 10;
	}
	if (!a.size())
		a.pb(0);

	LL res = 0;
	for (int i = 0; i < a.size(); i++)
		res = res * 10 + a[i];

	return res;
}


LL badSolve(LL n)
{
	vector <int> dp(10000000, inf);
	set<pii> q;
	dp[1] = 1;
	q.insert(mp(dp[1], 1));
	while (!q.empty())
	{
		int v = q.begin() ->Y;
		q.erase(q.begin());
		if (v >= 10000000)
			continue;

		if (v == n)
		{
			return dp[v];
		}
		vector <int> p;
		p.pb(v + 1);
		p.pb(rev(v));

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] >= 10000000)
				continue;
			if (dp[p[i]] > dp[v] + 1)
			{
				q.erase(mp(dp[p[i]], p[i]));
				dp[p[i]] = dp[v] + 1;
				q.insert(mp(dp[p[i]], p[i]));
			}
		}
	}
	return dp[n];
}

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cerr << i << endl;
		int x;
		scanf("%d", &x);
		printf("Case #%d: %d\n", i + 1, (int)badSolve(x));
	}
}
    
int main()
{

    //START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    solve();
    //END
    return 0;
}
/*******************************************
*******************************************/
 
template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif