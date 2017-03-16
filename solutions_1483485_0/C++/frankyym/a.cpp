#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;


const string en_text = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const string og_text = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

char tab[300];

int main() {
	for (int i=0; i<en_text.size(); ++i)
		tab[en_text[i]] = og_text[i];
	tab['q'] = 'z';
	tab['z'] = 'q';

	/*
	for (char ch = 'a'; ch <= 'z'; ++ch)
		printf("%c %c\n", ch, tab[ch]);
	*/

	int T;
	scanf("%d", &T);
	char line[200];
	gets(line);
	for (int i=0; i<T; ++i) {
		gets(line);
		//printf("%s\n", line);

		printf("Case #%d: ", i+1);
		for (int j=0; j<strlen(line); ++j)
			printf("%c", tab[line[j]]);
		printf("\n");
	}

	return 0;
}
