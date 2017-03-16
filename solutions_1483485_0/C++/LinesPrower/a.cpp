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

int mappings[26] = {121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98, 107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113};
char s[1005], t[1005];
bool f[255];

void init()
{
}

void solvecase()
{
	gets(s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) if (isalpha(s[i])) s[i] = mappings[s[i] - 'a'];
	printf("%s", s);
}

void solve() {
	init();
	int n_tests;
	scanf("%d\n", &n_tests);
	for (int i = 1; i <= n_tests; i++)
	{
		printf("Case #%d: ", i);
		solvecase();
		printf("\n");
	}
}

#define problem_letter "A"
//#define fname "test"
#define fname problem_letter "-small-attempt0"
//#define fname problem_letter "-small-attempt1"
//#define fname problem_letter "-small-attempt2"
//#define fname problem_letter "-large"


void decode()
{
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		gets(s);
		gets(t);
		int len = strlen(s);
		for (int j = 0; j < len; j++) if (isalpha(s[j])) mappings[s[j]-'a'] = t[j];
	}
	mappings[25] = 'q';
	for (int i = 0; i < 26; i++) printf("%d, ", mappings[i]);
	printf("\n");
	for (int i = 0; i < 26; i++) f[mappings[i]] = true;
	for (int i = 0; i < 26; i++) if (!f[i + 'a']) printf("%d", i + 'a');
}

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	//decode();
	return 0;
}