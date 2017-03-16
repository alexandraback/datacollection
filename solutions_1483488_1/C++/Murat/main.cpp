#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
#include <ctime>

#include <iostream>

#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>

//#pragma comment(linker, "/stack:64000000")

using namespace std;

template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 2000100;

int orig[N];
char s[20];
char str[20];

int st[N];

void init()
{
	for1(i, N) {
	//for (int i = 20; i <= 20; ++i) {
        	int t = i;
        	int j = 0;
        	while (t) {
        		s[j++] = char('0' + t % 10);
        		t /= 10;
        	}		
        	forn(k, j)
        		str[k] = str[k + j] = s[j - 1 - k];
		str[j * 2] = '\0';
		string z = string(str);
		int miv = INF;
		forn(k, j) {
			string c = z.substr(k, j);
			if (c[0] != '0') {
				int numb = 0;
				forn(t, j)
					numb = numb * 10 + (c[t] - '0');
				miv = min(miv, numb);
			}               
		}
		if (miv < INF)
			orig[i] = miv;
	}	
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	init();

	int tests;
	scanf("%d\n", &tests);
	for1(it, tests) {
		int a, b;
		scanf("%d%d\n", &a, &b);
		memset(st, 0, (b + 10) * sizeof(int));
		for (int i = a; i <= b; ++i)
			++st[orig[i]];
		li res = 0;
		for1(i, b)
			if (st[i] > 1) {
				res += (st[i] * (st[i] - 1)) >> 1;
			}
		printf("Case #%d: %I64d\n", it, res);
	}

	return 0;
}
