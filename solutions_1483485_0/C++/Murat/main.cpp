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
const int N = 26;

bool u0[N], u1[N];
map<char, char> ab;

void do_map(char a, char b)
{
	int x = a - 'a';
	int y = b - 'a';
	assert(u0[x] == u1[y]);
	u0[x] = 1;
	u1[y] = 1;
	ab.insert(mp(x, y));
}

char conv(char a)
{
	if (ab.count(a))
		return ab[a];
	return -1;
}

void init()
{
ab['a'] = 'y';
ab['b'] = 'h';
ab['c'] = 'e';
ab['d'] = 's';
ab['e'] = 'o';
ab['f'] = 'c';
ab['g'] = 'v';
ab['h'] = 'x';
ab['i'] = 'd';
ab['j'] = 'u';
ab['k'] = 'i';                                  
ab['l'] = 'g';
ab['m'] = 'l';
ab['n'] = 'b';
ab['o'] = 'k';
ab['p'] = 'r';
ab['q'] = 'z';
ab['r'] = 't';
ab['s'] = 'n';
ab['t'] = 'w';
ab['u'] = 'j';
ab['v'] = 'p';
ab['w'] = 'f';
ab['x'] = 'm';
ab['y'] = 'a';
ab['z'] = 'q';
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	init();

	int n;
	scanf("%d\n", &n);
	for1(i, n) {
		string s;
		getline(cin, s);
		printf("Case #%d: ", i);
		forn(j, s.size()) {
			if (islower(int(s[j]))) {
				assert(ab.count(s[j]));
				printf("%c", char(ab[s[j]]));
			} else
				printf("%c", s[j]);
		}
		puts("");
	}

	return 0;
}
