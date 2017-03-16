#include <iostream>
using namespace std;
char str[120];
char mm[256];
int main() {
	mm['a'] = 'y';
	mm['b'] = 'h';
	mm['c'] = 'e';
	mm['d'] = 's';
	mm['e'] = 'o';
	mm['f'] = 'c';
	mm['g'] = 'v';
	mm['h'] = 'x';
	mm['i'] = 'd';
	mm['j'] = 'u';
	mm['k'] = 'i';
	mm['l'] = 'g';
	mm['m'] = 'l';
	mm['n'] = 'b';
	mm['o'] = 'k';
	mm['p'] = 'r';
	mm['q'] = 'z';
	mm['r'] = 't';
	mm['s'] = 'n';
	mm['t'] = 'w';
	mm['u'] = 'j';
	mm['v'] = 'p';
	mm['w'] = 'f';
	mm['x'] = 'm';
	mm['y'] = 'a';
	mm['z'] = 'q';
	int T;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	gets(str);
	int b = 0;
	while (T--) {
		gets(str);
		for (int i = 0; str[i] != '\0'; ++i) {
			if (str[i] != ' ') {
				str[i] = mm[str[i]];
			}
		}
		printf("Case #%d: ", ++b);
		puts(str);
	}
	return 0;
}

