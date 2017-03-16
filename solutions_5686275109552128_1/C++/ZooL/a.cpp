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

const int maxn = 1005;
int dp[maxn][maxn] = {};

void solve()
{
	int T;
	scanf("%d", &T);
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		int D;
		scanf("%d", &D);
		vector <int> P(D);
		int ans = 0;
		for (int i = 0; i < D; i++)
		{
			scanf("%d", &P[i]);
			ans = max(ans, P[i]);
		}

		for (int v = 0; v <= 1005; v++)
		{
			int tmp = 0;
			for (int i = 0; i < D; i++)
				tmp += dp[P[i]][v];
			tmp += v;
			ans = min(ans, tmp);
		}
		

		printf("Case #%d: %d\n", q + 1, ans);
	}
}

int main()
{
	for (int k = 0; k < maxn; k++)
	{
		for (int i = 0; i < maxn; i++)
		{
			if (i <= k)
			{
				dp[i][k] = 0;
				continue;
			}
			dp[i][k] = i;
			for (int j = 0; j <= i; j++)
			{
				dp[i][k] = min(dp[i][k], dp[j][k] + dp[i - j][k] + 1);
			}
		}
	}

	//START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
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