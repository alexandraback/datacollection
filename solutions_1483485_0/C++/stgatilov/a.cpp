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

int maps[256];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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
maps['q'] = 'z';
maps['r'] = 't';
maps['s'] = 'n';
maps['t'] = 'w';
maps['u'] = 'j';
maps['v'] = 'p';
maps['w'] = 'f';
maps['x'] = 'm';
maps['y'] = 'a';
maps['z'] = 'q';


	int tests;
	scanf("%d\n", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		gets(str);

		printf("Case #%d: ", tt);
		for (int i = 0; str[i]; i++) {
			if (str[i] == ' ') printf(" ");
			else printf("%c", char(maps[str[i]]));
		}
		printf("\n");
		fflush(stdout);
	}

	return 0;
}
