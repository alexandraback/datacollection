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
 
const LD eps = 1e-13;
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

int get(vector <vector <int> > a)
{
	int n = a.size();
	int cnt = 0;
	vector <pair<int, int> > p;
	for (int i = 0; i < n; i++)
	{
		cnt += a[i][1];
		for (int k = 0; k < a[i][1]; k++)
			p.pb(mp(a[i][0], a[i][2] + k));
	}

	if (cnt <= 1)
		return 0;

	if (p[0].X < p[0].X)
		swap(p[0], p[1]);

	if (p[0].X == p[1].X && p[0].Y > p[1].Y)
		swap(p[0], p[1]);

	LD dist = (p[0].Y < p[1].Y) ? (360 - (p[0].X - p[1].X)) : (p[0].X - p[1].X);

	if (p[0].X == p[1].X)
		dist = 360;

	LD v = fabs(LD(360) / p[0].Y - LD(360) / p[1].Y);

	LD tMeet = dist / v;

	LD pos = min(p[0].X + LD(360) / p[0].Y * tMeet, p[1].X + LD(360) / p[1].Y * tMeet);

	if (pos > 360 + eps)
		return 0;

	if (p[0].Y < p[1].Y)
		return 1;

	LD pp = pos;

	dist = 360;

	tMeet = dist / v;

	pos = min(pp + LD(360) / p[0].Y * tMeet, pp + LD(360) / p[1].Y * tMeet);
	if (pos > 360 + eps)
		return 0;
	else
		return 1;
}

void solve()
{
	int T;
	scanf("%d", &T);
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		int N;
		scanf("%d", &N);
		vector <vector<int> > a(N, vector<int> (3));
		for (int i = 0; i < N; i++)
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

		printf("Case #%d: %d\n", q + 1, get(a));
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