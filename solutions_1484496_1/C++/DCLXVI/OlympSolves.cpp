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

vector<pair<ll, ll> > v;

//na kray
vll ans;
bool brute(int pos, ll cv, bool ok = false)
{
	if (cv == 0 && ok)
		return true;
	if (pos == sz(v))
		return false;

	for (int sign = -1; sign <= 1; sign++)
	{
		if (sign)
			ans.push_back(sign * v[pos].second);
		if (brute(pos + 1, cv + sign*v[pos].first, ok || sign != 0))
			return true;
		if (sign)
			ans.pop_back();
	}
	return false;
}

vector<pair<ll, ll> > values;
vector<pair<ll, ll> > genArg;

void gen(int pos, int mask, ll cv)
{
	if (pos == sz(genArg))
	{
		if (cv)
			values.push_back(pair<ll, ll>(cv, mask));
		return;
	}
	gen(pos + 1, mask, cv);
	gen(pos + 1, (mask | (1 << pos)), cv + genArg[pos].first);
}

void solve(vll &v1, vll &v2)
{
	vector<pair<ll, ll> > vc = v;
	for (int i=0;i<1000;i++)
	{
		std::cout<<"Iteration i"<<endl;

		random_shuffle(all(vc));
		int n2 = min(sz(vc)/2, 22);
		
		genArg = vector<pair<ll, ll> >(vc.begin(), vc.begin() + n2);
		gen(0, 0, 0);
		vector<pair<ll, ll> > val1 = values;
		values.clear();

		genArg = vector<pair<ll, ll> >(vc.begin() + n2, vc.begin() + n2 + n2);
		gen(0, 0, 0);
		vector<pair<ll, ll> > val2 = values;
		values.clear();

		map<ll, ll> mpSum;
		foria(val1) mpSum[val1[i].first] = val1[i].second;
		foria(val2) if (mpSum.find(val2[i].first) != mpSum.end())
		{
			ll mv1 = mpSum[val2[i].first];
			ll mv2 = val2[i].second;

			for (int j = 0; j < n2; j++)
				if (mv1 & (1LL << j))
					v1.push_back(vc[j].second);

			for (int j = 0; j < n2; j++)
				if (mv2 & (1LL << j))
					v2.push_back(vc[j + n2].second);

			ll sum = 0;
			foria(v1)
				sum += v[v1[i] - 1].first;
			foria(v2)
				sum -= v[v2[i] - 1].first;
			if (sum != 0)
				throw 0;
			return;
		}
	}

	std::cout<<"PALEVO!";
	if (!brute(0,0))
		throw 0;
	foria(ans)
		if (ans[i] > 0)
			v1.push_back(ans[i]);
		else
			v2.push_back(-ans[i]);
}

int main()
{
#ifndef _MSC_VER
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#else
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif 

/*	{
		cout<<1<<endl;
		cout<<500<<endl;
		fori(500)
			cout<<(i+1)*(i+1)<<' ';
		return 0;
	}*/
	readt;
	fort
	{
		int n;
		read n;
		v = vector<pair<ll, ll> >(n);
		forin read v[i].first;
		forin v[i].second = i+1;
		vll v1,v2;
		solve(v1,v2);
		cout << "Case #" << gett << ": ";
		std::cout << "Case #" << gett << ": ";
		writeln;
		foria(v1){write v[v1[i]-1].first; write ' ';}
		writeln;
		foria(v2){write v[v2[i]-1].first; write ' ';}
		writeln;
	}

    return 0;
}