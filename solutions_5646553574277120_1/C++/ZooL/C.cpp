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

void solve()
{
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		int c, d, v;
		scanf("%d %d %d", &c, &d, &v);
		vector <int> a(d);
		for (int i = 0; i < d; i++)
			scanf("%d", &a[i]);

		int last = 0;
		int j = 0;
		int ans = 0;
		for (int i = 1; i <= v; i++)
		{
			if (j < d && i == a[j])
			{
				last += a[j];
				j++;
			}
			if (i <= last)
				continue;
			ans++;
			last += i;
		}
		printf("Case #%d: %d\n", q + 1, ans);
	}
}

void solve2()
{
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		int c, d, v;
		scanf("%d %d %d", &c, &d, &v);
		vector <int> a(d);
		for (int i = 0; i < d; i++)
			scanf("%d", &a[i]);

		LL last = 0;
		int j = 0;
		int ans = 0;
		while (last < v)
		{
			while (j < d && a[j] <= (last + 1))
			{
				last += LL(c) * a[j];
				j++;

				if (last >= v)
					break;
			}
			if (last >= v)
				break;

			ans++;
			last += LL(c) * (last + 1);
		}
		printf("Case #%d: %d\n", q + 1, ans);
	}
}
int main()
{

    //START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    solve2();
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