#include <iostream>
#include <map>
#include <cstring>
#include <cassert>

using namespace std;

int main() {
	char *sA[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	char *sB[3] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
	map<char, char> M;
	for (int i = 0; i < 3; ++i) {
		int len = strlen(sA[i]);
		assert(len == strlen(sB[i]));
		for (int j = 0; j < len; ++j) {
			M[sA[i][j]] = sB[i][j];
		}
	}
	M['q'] = 'z';
	M['e'] = 'o';
	M['z'] = 'q';
	M[' '] = ' ';
	for (char c = 'a'; c <= 'z'; ++c) {
		//cout << c << " -> " << M[c] << endl;
		for (char d = c + 1; d <= 'z'; ++d) {
			assert (M[c] != M[d]);
		}
	}
	assert(M.size() == 27);
	int nTests;
	scanf("%d\n", &nTests);
	for (int test = 1; test <= nTests; ++test) {
		printf("Case #%d: ", test);
		char c;
		while ((c = getchar()) != '\n') {
			printf("%c", M[c]);
		}
		printf("\n");
	}
	return 0;
}
