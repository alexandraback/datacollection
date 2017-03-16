#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

const string pat[3] = {
	"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", 
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
const string str[3] = {
	"our language is impossible to understand", 
	"there are twenty six factorial possibilities", 
	"so it is okay if you want to just give up"
};

string mapString;

void init() {
	mapString = string(26, ' ');
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < (int)pat[i].size(); j++) {
			if (islower(pat[i][j])) {
				mapString[pat[i][j] - 'a'] = str[i][j];
			}
		}
	}
	mapString['q' - 'a'] = 'z';
	mapString['z' - 'a'] = 'q';
}

int main() {
	init();
	int taskNumber;
	scanf("%d", &taskNumber);
	getchar();
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		printf("Case #%d: ", taskIdx + 1);
		char ch;
		while ((ch = getchar()) != EOF && ch != '\n') {
			putchar(islower(ch) ? mapString[ch - 'a'] : ch);
		}
		putchar('\n');
	}
	return 0;
}
