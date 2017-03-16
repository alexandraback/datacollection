#define _CRT_SECURE_NO_DEPRECATE
#pragma comment (linker, "/stack:256000000")

#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <map>
#include <memory.h>
#undef NDEBUG
#include <cassert>
#include <ctime>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> pii;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("b-small.in", "r", stdin);
	freopen("b-small.out", "w", stdout);
	//freopen("-large.in", "r", stdin);
	//freopen("-large.out", "w", stdout);
}

const int maxn = 105;

int nK, tLen, sLen;
string keys, target;
int res, cnt;
int p[maxn];

void read()
{
	nK = ni();
	tLen = ni();
	sLen = ni();
	keys = ns();
	target = ns();
}

int calc(string &s)
{
	int ret = 0;
	fi(sz(s) - sz(target) + 1)
	{
		if (s.substr(i, sz(target)) == target)
			ret++;
	}
	return ret;
}

void go(string &s)
{
	if (sz(s) == sLen)
	{
		res += calc(s);
		cnt++;
	}
	else
	{
		fi(sz(keys))
		{
			s.pb(keys[i]);
			go(s);
			s.pop_back();
		}
	}
}

void calcP(string s)
{
	p[0] = 0;
	fi(sz(s)) if (i)
	{
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
}

bool goodLetters(string s, string t)
{
	fi(sz(t))
	{
		auto f = s.find(t[i]);
		if (f == string::npos)
			return false;
	}
	return true;
}

void solve(int test_num)
{
	cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	if (!goodLetters(keys, target))
		printf("0\n");
	else
	{
		res = 0;
		cnt = 0;
		string s = "";
		go(s);
		calcP(target);
		int q = sz(target) - p[sz(target) - 1];
		int a = (sLen - sz(target)) / q + 1;
		printf("%.10lf\n", a - (double)res / cnt);
	}
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
	{
		read();
		solve(i + 1);
	}
	return 0;
}