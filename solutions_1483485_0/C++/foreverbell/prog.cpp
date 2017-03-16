
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int test_case, l;
char M[256], buffer[256];

void init() {
	M['a'] = 'y';
	M['b'] = 'h';
	M['c'] = 'e';
	M['d'] = 's';
	M['e'] = 'o';
	M['f'] = 'c';
	M['g'] = 'v';
	M['h'] = 'x';
	M['i'] = 'd';
	M['j'] = 'u';
	M['k'] = 'i';
	M['l'] = 'g';
	M['m'] = 'l';
	M['n'] = 'b';
	M['o'] = 'k';
	M['p'] = 'r';
	M['q'] = 'z';
	M['r'] = 't';
	M['s'] = 'n';
	M['t'] = 'w';
	M['u'] = 'j';
	M['v'] = 'p';
	M['w'] = 'f';
	M['x'] = 'm';
	M['y'] = 'a';
	M['z'] = 'q';
}

int main() {
	init();
	scanf("%d\n", &test_case);
	for (int i = 1; i <= test_case; ++i) {
		gets(buffer);
		l = strlen(buffer);
		for (int j = 0; j < l; ++j) {
			if (isalpha(buffer[j])) buffer[j] = M[buffer[j]];
		}
		printf("Case #%d: %s\n", i, buffer);
	}
	return 0;
}
