#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
#define ALL(x) x.begin(), x.end()
#define LL long long
#define MP make_pair
#define PB push_back
#define CLR(a,b) memset(a, b, sizeof(a))
template<class T> inline T Sqr(const T &x) { return x*x; }
template<class T> inline T Abs(const T &x) { return x >= 0 ? x : -x; }
#define fo(i, n) for (int i = 0; i < (n); i++)
#define foz(i, a) for (int i = 0; i < (a).size(); i++)

void init()
{

}

typedef unsigned int uint;
//typedef long long numt;
//typedef __int128 numt;



void solvecase()
{
	char s[2000];
	cin >> s;
	string r(s, s+1);
	for (int i = 1; s[i]; ++i) {
		string s2 = r + s[i];
		string s3 = s[i] + r;
		r.swap(s2 < s3 ? s3 : s2);
	}
	printf("%s", r.c_str());
}

void solve() {
	init();
	int n_tests;
	scanf("%d", &n_tests);
	for (int i = 1; i <= n_tests; i++)
	{
		printf("Case #%d: ", i);
		solvecase();
		printf("\n");
	}
}

#define dir "C:/Users/dmarin3/Downloads/"
#define problem_letter "A"
//#define fname "test"
#define fname dir problem_letter "-small-attempt0"
//#define fname dir problem_letter "-small-attempt1"
//#define fname dir problem_letter "-small-attempt2"
//#define fname dir problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}
