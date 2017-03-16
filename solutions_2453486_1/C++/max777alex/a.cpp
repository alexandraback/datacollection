#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <memory.h>
#include <complex>
using namespace std;
#pragma comment(linker, "/STACK:512000000")
#define mp make_pair
#define pb push_back
#define all(C) (C).begin(), (C).end()
#define sz(C) (int)(C).size()
#define PRIME 1103
#define INF (1 << 30)
#define MOD 1000000007
#define FAIL ++*(int*)0
#define EPS 1e-9
template<class T> T sqr(T a) {return a * a;} 
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int64> vi64;
typedef vector<pii> vpii;
typedef vector<vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<pair<int, int > > > vvpii;
typedef complex<long double> cd;
#define TASK "A-large"

string s[4];

void init()
{
	for(int i = 0; i < 4; ++i)
		cin >> s[i];
}

bool win(string &s)
{
	for(int i = 0; i < 4; ++i)
		if(s[i] == '.') return 0;
	if(s[0] == 'T') swap(s[0], s[1]);
	for(int i = 0; i < 4; ++i)
	{
		if(s[i] == s[0] || s[i] == 'T')
			continue;
		return 0;
	}
	return 1;
}

void solve(int test) 
{
	vector<string> v;
	string d1 = "", d2 = "";
	for(int i = 0; i < 4; ++i)
	{
		v.pb(s[i]);

		string cur = "";
		for(int j = 0; j < 4; ++j)
			cur += s[j][i];
		v.pb(cur);

		d1 += s[i][i];
		d2 += s[i][3 - i];
	}
	v.pb(d1);
	v.pb(d2);
	printf("Case #%d: ", test);
	for(int i = 0; i < 10; ++i)
	{
		if(win(v[i]))
		{
			puts(v[i][0] == 'X' ? "X won" : "O won");
			return;
		}
	}
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			if(s[i][j] == '.')
			{
				puts("Game has not completed");
				return;
			}
		}
	}
	puts("Draw");
}

int main() 
{
#ifndef ONLINE_JUDGE
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
	int test;
	cin >> test;
	for(int i = 0; i < test; ++i)
	{
		init();
		solve(i + 1);
	}
    return 0;
}