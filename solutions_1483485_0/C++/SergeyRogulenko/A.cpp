#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int f[256];
bool u[26];
char buf[1000];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta (f, 0);
	f['y'] = 'a';
	f['q'] = 'z';
	f['e'] = 'o';
	string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string t1 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	forn (i, s1.length())
		f[s1[i]] = t1[i];
	seta (u, 0);
	for (int i = 'a'; i <= 'z'; i ++)
		if (f[i])
			u[f[i]-'a'] = 1;
	int v = 0;
	forn (i, 26)
		if (!u[i])
			v = i + 'a';
	f['z'] = v;
	int tt;
	cin >> tt;
	gets (buf);
	for (int i = 1; i <= tt; i ++) {
		printf ("Case #%d: ", i);
		gets (buf);
		string s = buf;
		forn (j, s.length())
			if (f[s[j]])
				printf ("%c", f[s[j]]);
			else
				printf ("%c", s[j]);
		cout << endl;
	}
	return 0;
}
