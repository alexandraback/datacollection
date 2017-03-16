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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

map<char, char> h;
char buf[100000];

void init(string s1, string s2){
	forn(i, s1.size())
		h[s1[i]] = s2[i];
}

string solve(string s){
	forn(i, s.size())	
		s[i] = h[s[i]];
	return s;
}

int main ()
{
	init("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	init("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	init("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
	
	h['q'] = 'z';
	h['z'] = 'q';
	
	int n;
	cin >> n;
	gets(buf);
	forn(i, n){
		printf("Case #%d: ", i + 1);
		gets(buf);
		string s = buf;
		cout << solve(s) << endl;
	}

	
	return 0;
}
