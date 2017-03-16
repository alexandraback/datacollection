#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string code = "ynficwlbkuomxsevzpdrjgthaq";
	string decode = "                          ";
	for (int i = 0; i < code.size(); ++i) {
		decode[code[i] - 'a'] = i + 'a';
	}
	int tests;
	scanf("%d\n", &tests);
	for (int i = 0; i < tests; ++i) {
		char * sentence = new char[200];
		gets(sentence);
		printf("Case #%d: ", i + 1);
		int length = strlen(sentence);
		for (int j = 0; j < length; ++j) {
			if (sentence[j] == ' ') {
				printf(" ");
			} else {
				printf("%c", decode[sentence[j] - 'a']);
			}
		}
		printf("\n");
	}
	return 0;
}