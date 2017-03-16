#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

char str[1024];
char sout[1024];
int maps[256];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d\n", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		gets(str);
		gets(sout);

		for (int i = 0; str[i]; i++) {
			if (str[i] == ' ') continue;
			maps[str[i]] = sout[i];
		}

/*		printf("Case #%d: \n", tt);
		fflush(stdout);*/
	}

	for (int i = 'a'; i<='z'; i++) printf("maps['%c'] = '%c';\n", char(i), char(maps[i]));

	return 0;
}


/*
maps['a'] = 'y';
maps['b'] = 'h';
maps['c'] = 'e';
maps['d'] = 's';
maps['e'] = 'o';
maps['f'] = 'c';
maps['g'] = 'v';
maps['h'] = 'x';
maps['i'] = 'd';
maps['j'] = 'u';
maps['k'] = 'i';
maps['l'] = 'g';
maps['m'] = 'l';
maps['n'] = 'b';
maps['o'] = 'k';
maps['p'] = 'r';
maps['q'] = ;
maps['r'] = 't';
maps['s'] = 'n';
maps['t'] = 'w';
maps['u'] = 'j';
maps['v'] = 'p';
maps['w'] = 'f';
maps['x'] = 'm';
maps['y'] = 'a';
maps['z'] = ;
*/