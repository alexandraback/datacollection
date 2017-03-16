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

const ll mod = 1000000007;

bool isMono(string s)
{
	foris if (s[i] != s[0]) return false;
	return true;
}

bool isPaired(const string &s1, const string &s2)
{
	if (s1.back() == s2[0])
		return true;
	return false;
}

bool check(string s)
{
	foris if (i != 0)
	{
		if (s[i - 1] != s[i])
		{
			if (count(s.begin() + i, s.end(), s[i - 1]) != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	readt;
	fort
	{
		cout <<  "Case #" << gett << ": ";

		int n;
		read n;
		vs v(n);
		forin read v[i];

		vi mcnt(256);
		vi mlocked(256);
		forin if (isMono(v[i])) ++mcnt[v[i][0]];

		vvs groups;
		vi gused(n);
		forin if (!isMono(v[i]) && !gused[i])
		{
			groups.push_back(vs(1, v[i]));
			gused[i] = true;
			bool changed = true;
			while (changed)
			{
				changed = false;
				forjn if (!isMono(v[j]) && !gused[j])
				{
					if (isPaired(v[j], groups.back()[0]))
					{
						groups.back().insert(groups.back().begin(), v[j]);
						gused[j] = true;
						changed = true;
					}
					else if (isPaired(groups.back().back(), v[j]))
					{
						groups.back().push_back(v[j]);
						gused[j] = true;
						changed = true;
					}
				}
			}
		}

		string result;
		foria(groups) forja(groups[i]) result += groups[i][j];

		vll fact;
		fact.push_back(1);
		fori(200)
			fact.push_back((fact.back() * (i + 1)) % mod);

		if (check(result))
		{
			foria(result) mlocked[result[i]] = true;
			int mucnt = 0;
			foria(mcnt) if (mcnt[i] != 0 && !mlocked[i]) ++mucnt;
			
			ll result = 1;
			result = (result * fact[mucnt + sz(groups)]) % mod;
			foria(mcnt) result = (result * fact[mcnt[i]]) % mod;
			cout << result;
		}
		else
		{
			cout << 0;
		}

		cout << endl;
	}
}