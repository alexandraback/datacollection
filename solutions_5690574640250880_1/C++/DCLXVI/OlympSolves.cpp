#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <ctime>
#include <bitset>
using namespace std;

#pragma comment(linker, "/stack:64000000")

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mpii;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())

#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define forin fori(n)
#define forjn forj(n)
#define forjm forj(m)
#define forkm fork(m)
#define foria(a) fori(sz(a))
#define foriv foria(v)
#define foris fori(len(s))
#define forja(a) forj(sz(a))
#define forjv forj(v)
#define forjs forj(len(s))

#define read cin>>
#define write cout<<
#define writeln write endl

#define readt int aaa; read aaa;
#define gett (bbb+1)
#define fort forr(bbb,aaa)

#define issa(a,s) istringstream a(s);
#define iss(s) issa(ss,s);

ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;

ll gcd(ll a, ll b){return b ? gcd(b,a%b) : a;}

template<class T>
struct makev
{
    vector<T> v;
    makev& operator << (const T& x)
    {
        v.push_back(x);
        return *this;
    }
    operator vector<T>& ()
    {
        return v;
    }
};

void assert(bool b)
{
    if (!b)
        throw 0;
}

template <int n>
struct nbest
{
    vector<pair<ll, int> > p;
    nbest():p(n+1)
    {
        foria(p) p[i].first = p[i].second = -1;
    }
    void add(ll value, int key)
    {
        p[n] = make_pair(value, key);
        sort(rall(p));
    }
    ll getValue(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].first;
    }
    int getKey(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second;
    }
    bool has(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second != -1;
    }
};

bool rcheck(vvi &v, int x, int y)
{
	if (!(x >= 0 && x < sz(v)))
		return false;
	if (!(y >= 0 && y < sz(v[x])))
		return false;
	return true;
}

bool calc(vvi &v, int x, int y)
{
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			if (rcheck(v, x + dx, y + dy) && v[x + dx][y + dy] == '*')
				return 1;
	return 0;
}


bool validate(vvi v, int c)
{
	vvi visit(v);
	foria(visit) forja(visit[i]) visit[i][j] = 0;
	vii q;
	q.push_back(ii(0, 0));
	visit[0][0] = 1;

	foria(q)
	{
		ii cur = q[i];
		if (calc(v, cur.first, cur.second) != 0)
			continue;
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				if (rcheck(v, cur.first + dx, cur.second + dy) && !visit[cur.first + dx][cur.second + dy])
				{
					visit[cur.first + dx][cur.second + dy] = 1;
					q.push_back(ii(cur.first + dx, cur.second + dy));
				}
	}
	return sz(q) == c;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	readt;
	cout.setf(ios::fixed);
	cout.precision(20);
	fort
	{
		int n, m, c;
		read n;
		read m;
		read c;

		vvi v(n, vi(m, '.'));
		vector<pair<int, ii> > order;
		forin forjm order.push_back(make_pair(max(i, j), ii(i,j)));
		sort(all(order));
		reverse(all(order));

		int ctest = n * m - c;
		int itest = 1;
		bool rdy = false;
		for (; itest < min(n, m); itest += 1) 
		{
			if (ctest >= itest) ctest -= itest; else {rdy = true; --itest;  break;}
			if (ctest >= itest) ctest -= itest; else {rdy = true; break;}
		}
		if (!rdy)
		{
			for (; ; itest += 1)
			{
				if (ctest >= min(n,m)) ctest -= min(n,m); else {--itest; break;}
			}
		}
		v[0][0] = 'c';
		int wayc = 2;
		for (int i = 0, k = c; i < sz(order) && k > 0; i++)
		{
			if (min(n,m) > 2 && ctest == 1 && order[i].first == itest && k == 1 && wayc != 0)
			{
				--wayc;
				continue;
			}
			v[order[i].second.first][order[i].second.second] = '*';
			--k;
		}

		cout <<  "Case #" << gett << ":";

		bool bad = false;

		if (n == 1 || m == 1)
		{
			//never bad
		}
		else if (n == 2 || m == 2)
		{
			if (c == n * m - 2 || (c != n * m - 1 && (n * m - c) % 2 != 0))
				bad = true;
		}
		else
		{
			if (c == n * m - 2 || c == n * m - 3 || c == n * m - 5 || c == n * m - 7)
				bad = true;
		}

		if (bad)
		{
			cout << endl;
			cout << "Impossible";
			if (validate(v, n * m - c))
				throw 0;
		}
		else
		{
			if (!validate(v, n * m - c))
			{
				throw 0;
				//cout << "BAD :" << n << ' ' << m << ' ' << c << endl;
			}
			fori(n)
			{
				cout << endl;
				forj(m) cout << char(v[i][j]);
			}
		}

		cout << endl;
		//std::cout <<  "Case #" << gett << ": " << ans << endl;
	}
}