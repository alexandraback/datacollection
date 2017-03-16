#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

char to[300];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	string t1 = "our language is impossible to understand";
	string t2 = "there are twenty six factorial possibilities";
	string t3 = "so it is okay if you want to just give up";
	
	memset(to, -1, sizeof(to));
	
	forn(i, sz(s1))
		to[s1[i]] = t1[i];
	forn(i, sz(s2))
		to[s2[i]] = t2[i];
	forn(i, sz(s3))
		to[s3[i]] = t3[i];
	to['z'] = 'q';
	
	for (char c = 'a'; c <= 'z'; c++)
	{
		bool ok = true;
		forn(i, 26)
			if (to['a' + i] == c)
				ok = false;
				
		if (ok)
			to['q'] = c;
	}
	
	int testCount;
	scanf("%d\n", &testCount);
	
	forn(test, testCount)
	{
		string s;
		getline(cin, s);
		
		printf("Case #%d: ", test + 1);
		
		forn(i, sz(s))
			if (isalpha(s[i]))
				putchar(to[s[i]]);
			else
				putchar(s[i]);
			
		puts("");
	}

	return 0;
}
























































