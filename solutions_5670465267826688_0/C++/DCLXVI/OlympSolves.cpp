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

int q_multiply[4][4];

int sign(int c)
{
	return c > 0 ? 1 : -1;
}

struct q
{
	int c;
	q(int c_):c(c_){}
	q operator * (const q & other) const
	{
		return q(sign(c) * sign(other.c) * q_multiply[abs(c)][abs(other.c)]);
	}
};

int q_code(char c)
{
	if (c == '1') return 1;
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	if (c == 'k') return 4;
	throw 0;
	return 0;
}

void q_init()
{
	q_multiply[q_code('1')][q_code('1')] = q_code('1');
	q_multiply[q_code('1')][q_code('i')] = q_code('i');
	q_multiply[q_code('1')][q_code('j')] = q_code('j');
	q_multiply[q_code('1')][q_code('k')] = q_code('k');

	q_multiply[q_code('i')][q_code('1')] = q_code('i');
	q_multiply[q_code('i')][q_code('i')] = -q_code('1');
	q_multiply[q_code('i')][q_code('j')] = q_code('k');
	q_multiply[q_code('i')][q_code('k')] = -q_code('j');

	q_multiply[q_code('j')][q_code('1')] = q_code('j');
	q_multiply[q_code('j')][q_code('i')] = -q_code('k');
	q_multiply[q_code('j')][q_code('j')] = -q_code('1');
	q_multiply[q_code('j')][q_code('k')] = q_code('i');

	q_multiply[q_code('k')][q_code('1')] = q_code('k');
	q_multiply[q_code('k')][q_code('i')] = q_code('j');
	q_multiply[q_code('k')][q_code('j')] = -q_code('i');
	q_multiply[q_code('k')][q_code('k')] = -q_code('1');
}

q qpow(q v, ll n)
{
	n %= 4;
	q result(1);
	forin result = result * v;
	return result;
}

bool solve(string s, ll n)
{
	q current(1);
	foris current = current * q(q_code(s[i]));
	if (qpow(current, n).c != -1)
		return false;

	ll flen = n * len(s);

	string s4 = s + s + s + s;

	ll ipos = flen;
	q ivalue(1);
	fori(len(s4))
	{
		ivalue = ivalue * q(q_code(s4[i]));
		if (ivalue.c == q_code('i'))
		{
			ipos = i + 1;
			break;
		}
	}

	ll kpos = flen;
	q kvalue(1);
	fori(len(s4))
	{
		kvalue = q(q_code(s4[len(s4) - i - 1])) * kvalue;
		if (kvalue.c == q_code('k'))
		{
			kpos = i + 1;
			break;
		}
	}
	return ipos + kpos < flen;
}

int main()
{
	ios::sync_with_stdio(false);
#ifdef _MSC_VER
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#else
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif
	q_init();

	readt;
	fort
	{
		ll l, n;
		read l >> n;
		string s;
		read s;
		cout << "Case #" << gett << ": " << (solve(s, n) ? "YES" : "NO") << endl;
	}

	return 0;
}