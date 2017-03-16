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
		int X, R, C;
		scanf("%d %d %d", &X, &R, &C);
		if (R > C)
			swap(R, C);
		int ans = 0;
		if (X == 1)
			ans = 1;
		if (X == 2)
		{
			if(R == 1 && C == 1 || R == 1 && C == 3 || R == 3 && C == 3)
				ans = 0;
			else
				ans = 1;
		}
		if (X == 3)
		{
			if (R ==2 && C == 3 || R == 3 && C == 3 || R == 3 && C == 4)
				ans = 1;
			else
				ans = 0;
		}
		if (X == 4)
		{
			if (R == 4 && C == 4 || R == 3 && C == 4)
				ans = 1;
			else
				ans = 0;
		}
		printf("Case #%d: %s\n", q + 1, ans? "GABRIEL" : "RICHARD");
	}
}

int main()
{

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