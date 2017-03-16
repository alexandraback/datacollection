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

int mp[30][30];

bool rc(int i, int j, int n, int m)
{
	return 0 <= i && i < n && 0 <= j && j < m;
}

int getAns(int n, int m)
{
	vvi visit(n, vi(m));
	vii q;
	forin forjm if (i == 0 || i == n - 1 || j == 0 || j == m - 1) if (!mp[i][j])
	{
		visit[i][j] = true;
		q.push_back(ii(i,j));
	}
	foria(q)
	{
		ii cur = q[i];
		for (int dx = -1; dx <= 1; dx++)
			for (int dy = -1; dy <= 1; dy++)
				if (labs(dx) + labs(dy) == 1)
					if (rc(cur.first + dx, cur.second + dy, n, m) && !mp[cur.first + dx][cur.second + dy] && !visit[cur.first + dx][cur.second + dy])
					{
						q.push_back(ii(cur.first + dx, cur.second + dy));
						visit[cur.first + dx][cur.second + dy] = true;
					}
	}
	return n * m - sz(q);
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	readt;
	fort
	{
		cout <<  "Case #" << gett << ": ";

		int n, m, k;
		read n;
		read m;
		read k;
		int r = n * m;

		forr(msk2, 1 << (n * m))
		{
			int msk = msk2;
			forin forjm
			{
				mp[i][j] = (msk & 1);
				msk >>= 1;
			}
			int bcnt = 0;
			forin forjm if (mp[i][j]) ++bcnt;
			if (bcnt >= r)
				continue;
			if (getAns(n, m) >= k)
				r = bcnt;
		}

		cout << r;

		cout << endl;
	}
}