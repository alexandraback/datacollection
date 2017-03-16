#include <cstdio>

using namespace std;

int main() {
	char ans[26];
	ans[0] = 'y';
	ans[1] = 'h';
	ans[2] = 'e';
	ans[3] = 's';
	ans[4] = 'o';
	ans[5] = 'c';
	ans[6] = 'v';
	ans[7] = 'x';
	ans[8] = 'd';
	ans[9] = 'u';
	ans[10] = 'i';
	ans[11] = 'g';
	ans[12] = 'l';
	ans[13] = 'b';
	ans[14] = 'k';
	ans[15] = 'r';
	ans[16] = 'z';
	ans[17] = 't';
	ans[18] = 'n';
	ans[19] = 'w';
	ans[20] = 'j';
	ans[21] = 'p';
	ans[22] = 'f';
	ans[23] = 'm';
	ans[24] = 'a';
	ans[25] = 'q';

	int tests; scanf("%d", &tests);
	for (int t = 1; t <= tests; t++) {
		char s[105];
		scanf(" %[^\n]\n", s);

		for (int i = 0; s[i] != '\0'; i++) if (s[i] != ' ')
			s[i] = ans[s[i] - 'a'];

		printf("Case #%d: %s\n", t, s);
	}

	return 0;
}
